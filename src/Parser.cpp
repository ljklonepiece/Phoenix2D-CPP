/*
 * Phoenix2D (RoboCup Soccer Simulation 2D League)
 * Copyright (c) 2013 Ivan Gonzalez
 *
 * This file is part of Phoenix2D.
 *
 * Phoenix2D is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * Phoenix2D is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with Phoenix2D.  If not, see <http://www.gnu.org/licenses/>.
 */

#include "Parser.h"
#include <iostream>
#include "Game.h"
#include <cstdlib>
#include "Self.h"
#include "Flag.h"
#include "Player.h"
#include <vector>
#include <unistd.h>
#include "Server.h"
#include <algorithm>
#include "Position.h"
#include "World.h"
#include "Ball.h"

pthread_cond_t Parser::SEE_COND = PTHREAD_COND_INITIALIZER;
pthread_mutex_t Parser::SEE_MUTEX = PTHREAD_MUTEX_INITIALIZER;

Self *Parser::self = 0;
Game *Parser::game = 0;
World *Parser::world = 0;
boost::regex Parser::sense_body = boost::regex("\\(sense_body\\s+(\\d+)\\s+");
boost::regex Parser::see_regex = boost::regex("\\(([^()]+)\\)\\s*([\\d\\.\\-etk\\s]*)");
bool Parser::processing_see = false;

std::string Parser::sense_body_message = std::string();
std::string Parser::see_message = std::string();

bool compareFlags(Flag f0, Flag f1) {
	return f0.getDistance() < f1.getDistance();
}

Parser::Parser(Self *self, World *world) {
	Parser::self = self;
	Parser::world = world;
	hear_regex = boost::regex("\\(hear\\s+(\\d+)\\s+(self|referee|online_coach_left|online_coach_right)\\s+([\\\"\\w\\s]*)\\)");
	hear_player_regex = boost::regex("");
	Parser::game = new Game();
	thread_sense_body = 0;
	thread_see = 0;
}

void *Parser::process_sense_body(void *arg) {
	Parser::self->processSenseBody(Parser::sense_body_message);
	boost::cmatch match;
	usleep(1000 * Server::SYNCH_SEE_OFFSET);
	int success = pthread_mutex_lock(&Parser::SEE_MUTEX);
	if (success) {
		std::cerr << "Parser::process_sense_body(void*) -> cannot lock mutex" << std::endl;
		return 0;
	}
	while(Parser::processing_see) {
		success = pthread_cond_wait(&Parser::SEE_COND, &Parser::SEE_MUTEX);
		if (success) {
			std::cerr << "Parser::process_sense_body(void*) -> cannot wait for condition" << std::endl;
			return 0;
		}
	}
	success = pthread_mutex_unlock(&Parser::SEE_MUTEX);
	if (success) {
		std::cerr << "Parser::process_sense_body(void*) -> cannot unlock mutex" << std::endl;
	}
	if (boost::regex_search(Parser::sense_body_message.c_str(), match, Parser::sense_body)) {
		Parser::game->updateTime(atoi((std::string() + match[1]).c_str()));
	}
	return 0;
}

void *Parser::process_see(void *arg) {
	Parser::processing_see = true;
	int simulation_time = Game::SIMULATION_TIME;
	Position player_position = Self::getPosition();
	int success = pthread_mutex_lock(&Parser::SEE_MUTEX);
	if (success) {
		std::cerr << "Parser::process_see(void*) -> cannot lock mutex" << std::endl;
		return 0;
	}
	std::vector<Flag> flags;
	std::vector<Player> players;
	std::vector<Ball> ball;
	std::string::const_iterator start, end;
	start = Parser::see_message.begin();
	end = Parser::see_message.end();
	boost::match_results<std::string::const_iterator> match;
	boost::match_flag_type search_flags = boost::match_default;
	while (boost::regex_search(start, end, match, Parser::see_regex, search_flags)) {
		std::string name = std::string() + match[1];
		std::string data = std::string() + match[2];
		switch (name[0]) {
		case 'g':
			break;
		case 'f':
			flags.push_back(Flag(name, data, simulation_time));
			break;
		case 'p':
			players.push_back(Player(name, data, simulation_time, player_position));
			break;
		case 'b':
			ball.push_back(Ball(data, simulation_time, player_position));
			break;
		default:
			break;
		}
		start = match[0].second;
		search_flags |= boost::match_prev_avail;
		search_flags |= boost::match_not_bob;
	}
	std::sort(flags.begin(), flags.end(), compareFlags);
	Parser::self->localize(flags);
	Parser::world->updateWorld(players, ball);
	Parser::processing_see = false;
	success = pthread_mutex_unlock(&Parser::SEE_MUTEX);
	if (success) {
		std::cerr << "Parser::process_see(void*) -> cannot unlock mutex" << std::endl;
	}
	success = pthread_cond_signal(&Parser::SEE_COND);
	if (success) {
		std::cerr << "Parser::process_see(void*) -> cannot signal to blocked threads" << std::endl;
	}
	return 0;
}

Parser::~Parser() {
	if (Parser::game) delete Parser::game;
	if (Parser::self) delete Parser::self;
}

void Parser::parseMessage(std::string message) {
	size_t found = message.find_first_of(" ");
	std::string message_type = message.substr(1, found - 1);
	if (message_type.compare("sense_body") == 0) {
		Parser::sense_body_message = message;
		int success = pthread_create(&thread_sense_body, 0, Parser::process_sense_body, 0);
		if (success) {
			std::cerr << "Parser::parseMessage(string) -> error creating sense_body thread" << std::endl;
		}
	} else if (message_type.compare("see") == 0) {
		Parser::see_message = message;
		int success = pthread_create(&thread_see, 0, Parser::process_see, 0);
		if (success) {
			std::cerr << "Parser::parseMessage(string) -> error creating see thread" << std::endl;
		}
	} else if (message_type.compare("hear") == 0) {
		//(hear 0 referee play_on)
		//(hear 432 173 opp "Phoenix")
		//(hear 551 self "Nemesis");
		boost::cmatch match;
		if (boost::regex_match(message.c_str(), match, hear_regex)) {
			std::string sender = std::string() + match[2];
			if (sender.compare("referee") == 0) {
				game->updatePlayMode(std::string() + match[3]);
			}
		}
	} else if (message_type.compare("change_player_type") == 0) {

	} else if (message_type.compare("see_global") == 0){
		int simulation_time = Game::SIMULATION_TIME;
		std::vector<Player> players;
		std::vector<Ball> ball;
		std::string::const_iterator start, end;
		start = Parser::see_message.begin();
		end = Parser::see_message.end();
		boost::match_results<std::string::const_iterator> match;
		boost::match_flag_type search_flags = boost::match_default;
		while (boost::regex_search(start, end, match, Parser::see_regex, search_flags)) {
			std::string name = std::string() + match[1];
			std::string data = std::string() + match[2];
			switch (name[0]) {
			case 'g':
				break;
			case 'p':
				players.push_back(Player(name, data, simulation_time));
				break;
			case 'b':
				ball.push_back(Ball(data, simulation_time));
				break;
			default:
				break;
			}
			start = match[0].second;
			search_flags |= boost::match_prev_avail;
			search_flags |= boost::match_not_bob;
		}
		Parser::world->updateWorld(players, ball);
	} else if (message_type.compare("ok") == 0) {

	} else {
		std::cerr << "Parse::parseMessage(string) -> message " << message << " not recognized" << std::endl;
	}
}
