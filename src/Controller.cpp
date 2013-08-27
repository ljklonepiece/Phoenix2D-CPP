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

#include "Controller.h"
#include <boost/regex.hpp>
#include <iostream>
#include <cstdlib>
#include "Connect.h"
#include "Self.h"
#include "Reader.h"
#include "Server.h"
#include "Parser.h"

char Controller::AGENT_TYPE = 'p';

Controller::Controller(const char *teamName, char agentType, const char *hostname) {
	this->hostname = std::string(hostname);
	Controller::AGENT_TYPE = agentType;
	team_name = std::string(teamName);
	connected = false;
	c = 0;
	reader = 0;
	server = 0;
}

Controller::~Controller() {
	if (reader) delete reader;
	if (server) delete server;
	if (c) delete c;
}

void Controller::connect() {
	std::string message = "(init " + team_name + " (version 15.1)";
	int port = 6000;
	switch (Controller::AGENT_TYPE) {
	case 'g':
		message = message + " (goalie))";
		break;
	case 't':
		message = "(init (version 15.1))";
		port = 6001;
		break;
	case 'c':
		message = message + ")";
		port = 6002;
		break;
	default:
		message = message + ")";
		break;
	}
	boost::regex error("\\(error\\s+([\\w\\_]+)\\)"); //i.e (error no_more_team_or_player_or_goalie)
	boost::cmatch match;
	c = new Connect(hostname.c_str(), port);
	c->sendMessage(message);
	message = c->receiveMessage();
	if (boost::regex_match(message.c_str(), match, error)) {
		std::cerr << "Controller::connect() -> " << match[1] << std::endl; //Error
		return;
	} else {
		boost::regex response("\\(init\\s+(l|r)\\s+(\\d+)\\s+([\\w\\_]+)\\)"); //i.e (init l 1 before_kick_off)
		std::string side;
		int unum;
		if (boost::regex_match(message.c_str(), match, response)) {
			side = match[1];
			std::string unum_str = std::string() + match[2];
			unum = atoi(unum_str.c_str()); //C++11: use std::stoi()
		} else {
			side = "undefined";
			unum = 0;
			std::cerr << "Controller::connect() -> Does not match response" << std::endl;
		}
		switch (Controller::AGENT_TYPE) {
		case 't':
			side = "trainer";
			break;
		case 'c': //Especial case, we need to consider the regex for this case
			break;
		default:
			break;
		}
		message = c->receiveMessage(); //server_params
		server = new Server(message);
		message = c->receiveMessage(); //player_params
		Self *self = new Self(message, team_name, unum, side);
		for (int i = 0; i < Self::PLAYER_TYPES; i++) {
			message = c->receiveMessage(); //player_type
			self->addPlayerType(message);
		}
		Parser *parser = new Parser(self);
		reader = new Reader(c, parser);
		reader->start();
		connected = true;
	}
}

bool Controller::isConnected() {
	return connected;
}

void Controller::reconnect() {

}

void Controller::disconnect() {
	std::cout << "Controller::disconnect() -> waiting for reader" << std::endl;
	reader->stop();
	if (isConnected()) {
		c->sendMessage("(bye)");
	}
	connected = false;
}
