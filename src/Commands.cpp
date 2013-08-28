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

#include "Commands.h"
#include <sstream>
#include <iomanip>
#include <string>

Commands::Commands() {
	connect = 0;
}

Commands::~Commands() {

}

void Commands::move(double x, double y) {
	std::stringstream ss;
	ss << "(move " << std::setprecision(4) << x << " " << y << ")" << std::endl;
	std::string command;
	std::getline(ss, command);
	commands_to_send.push_back(Command(command, 1));
}

void Commands::turn(double moment) {
	std::stringstream ss;
	ss << "(turn " << std::setprecision(4) << moment << ")" << std::endl;
	std::string command;
	std::getline(ss, command);
	commands_to_send.push_back(Command(command, 1));
}

void Commands::dash(double power, double direction) {
	std::stringstream ss;
	ss << "(dash " << std::setprecision(4) << power << " " << direction << ")" << std::endl;
	std::string command;
	std::getline(ss, command);
	commands_to_send.push_back(Command(command, 1));
}
