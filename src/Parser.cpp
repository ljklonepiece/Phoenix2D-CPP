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

Parser::Parser(Self *self) {
	this->self = self;
	sense_body = boost::regex("\\(sense_body\\s+(\\d+)\\s+");
	game = 0;
}

Parser::~Parser() {
	if (game) delete game;
	if (self) delete self;
}

/*
 * Possible messages:
 * (sense_body ...)
 * (see ...)
 * (hear ...)
 */
void Parser::parseMessage(std::string message) {
	size_t found = message.find_first_of(" ");
	std::string message_type = message.substr(1, found - 1);
	std::cout << "Message type: " << message_type << std::endl;
	if (message_type.compare("sense_body") == 0) {
		boost::cmatch match;
		if (boost::regex_search(message.c_str(), match, sense_body)) {
			std::cout << "Game time: " << match[1] << std::endl;
		}
	} else if (message_type.compare("see") == 0) {

	} else if (message_type.compare("hear") == 0) {

	} else {
		std::cerr << "Parse::parseMessage(string) -> message " << message << " not recognized" << std::endl;
	}
}
