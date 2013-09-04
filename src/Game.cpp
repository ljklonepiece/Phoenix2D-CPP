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

#include "Game.h"
#include <iostream>
#include "Self.h"

int Game::GAME_TIME = 0;
int Game::SIMULATION_TIME = 0;
int Game::GOALS = 0;
int Game::GOALS_AGAINST = 0;
std::string Game::PLAY_MODE = "before_kick_off";
pthread_cond_t Game::CYCLE_COND = PTHREAD_COND_INITIALIZER;
pthread_mutex_t Game::CYCLE_MUTEX = PTHREAD_MUTEX_INITIALIZER;
bool Game::CYCLE_FLAG = false;
bool Game::ON_GAME = true;

Game::Game() {
	play_modes = "before_kick_off corner_kick_l corner_kick_r free_kick_l free_kick_r goal_kick_l goal_kick_r kick_in_l kick_in_r kick_off_l kick_off_r play_on";
	events     = "drop_ball goal_l goal_r offside_l offside_r time_over";
	goal_regex = boost::regex("goal_(l|r)_(\\d+)");
}

Game::~Game() {

}

void Game::updateTime(int game_time) {
	int success = pthread_mutex_lock(&Game::CYCLE_MUTEX);
	if (success) {
		std::cerr << "Game::updateTimes(int) -> can not lock mutex" << std::endl;
		return;
	}
	Game::GAME_TIME = game_time;
	Game::SIMULATION_TIME++;
	Game::CYCLE_FLAG = true;
	success = pthread_mutex_unlock(&Game::CYCLE_MUTEX);
	if (success) {
		std::cerr << "Game::updateTimes(int) -> can not unlock mutex" << std::endl;
	}
	success = pthread_cond_signal(&Game::CYCLE_COND);
	if (success) {
		std::cerr << "Game::updateTime(int) -> can not signal to blocked threads" << std::endl;
	}
}

void Game::updatePlayMode(std::string play_mode) {
	boost::cmatch match;
	if (boost::regex_match(play_mode.c_str(), match, goal_regex)) {
		int goals = atoi((std::string() + match[2]).c_str());
		if (Self::SIDE.compare(match[1])) {
			Game::GOALS = goals;
		} else {
			Game::GOALS_AGAINST = goals;
		}
		play_mode = std::string() + "goal_" + match[2];
	}
	if (play_modes.find(play_mode)) {
		Game::PLAY_MODE = play_mode;
	}
}

bool Game::nextCycle() {
	int success = pthread_mutex_lock(&Game::CYCLE_MUTEX);
	if (success) {
		std::cerr << "Game::nextCycle() -> can not lock mutex" << std::endl;
		return false;
	}
	while (!Game::CYCLE_FLAG) {
		success = pthread_cond_wait(&Game::CYCLE_COND, &Game::CYCLE_MUTEX);
		if (success) {
			std::cerr << "Game::nextCycle() -> can not wait for condition" << std::endl;
			return false;
		}
	}
	Game::CYCLE_FLAG = false;
	success = pthread_mutex_unlock(&Game::CYCLE_MUTEX);
	if (success) {
		std::cerr << "Game::nextCycle() -> can not unlock mutex" << std::endl;
	}
	return Game::ON_GAME; //In some point we need to change this variable when the game is over
}
