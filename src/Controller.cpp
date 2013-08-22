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

#include <Controller.h>
#include <boost/regex.hpp>
#include <iostream>
#include <cstdlib>
#include "Self.h"

std::string Controller::HOSTNAME = "localhost";
std::string Controller::TEAM_NAME = "undefined";
std::string Controller::SIDE = "l";
int Controller::UNIFORM_NUMBER = "0";
char Controller::AGENT_TYPE = 'p';

Controller::Controller(const char *teamName, char agentType, const char *hostname) {
	Controller::HOSTNAME = std::string(hostname);
	Controller::AGENT_TYPE = agentType;
	Controller::TEAM_NAME = std::string(teamName);
	connected = false;
	c = 0;
}

Controller::~Controller() {
	if (c) delete c;
}

void Controller::connect() {
	std::string message = "(init " + Controller::TEAM_NAME + " (version 15.1)";
	int port = 6000;
	switch (Controller::AGENT_TYPE) {
	case 'g':
		message = message + " (goalie))";
		break;
	case 't':
		message = "(init (version 15))";
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
	c = new Connect(Controller::HOSTNAME.c_str(), port);
	c->sendMessage(message);
	message = c->receiveMessage();
	if (boost::regex_match(message.c_str(), match, error)) {
		std::cerr << match[1] << std::endl; //Error
		return;
	} else {
		boost::regex response("\\(init\\s+(l|r)\\s+(\\d+)\\s+([\\w\\_]+)\\)"); //i.e (init l 1 before_kick_off)
		std::string side;
		int unum;
		if (boost::regex_match(message.c_str(), match, response)) {
			side = match[1];
			unum = atoi((char *)match[2]); //C++11: use std::stoi()
		} else {
			side = "undefined";
			unum = 0;
			std::cerr << "Does not match response" << std::endl;
		}
		switch (Controller::AGENT_TYPE) {
		case 't':
			Controller::SIDE = "trainer";
			break;
		case 'c': //Especial case, we need to consider the regex for this case
			break;
		default:
			Controller::SIDE = side;
			Controller::UNIFORM_NUMBER = unum;
			break;
		}
		std::cout << c->receiveMessage() << std::endl; //server_params
		message = c->receiveMessage(); //player_params
		Self self(message);
		for (int i = 0; i < Self::PLAYER_TYPES; i++) {
			std::cout << c->receiveMessage() << std::endl; //player_types
		}
		connected = true;
	}
}

bool Controller::isConnected() {
	return connected;
}

void Controller::reconnect() {

}

void Controller::disconnect() {
	if (isConnected()) {
		c->sendMessage("(bye)");
	}
	connected = false;
}
