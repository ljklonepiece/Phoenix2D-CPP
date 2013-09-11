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
#include <iostream>
#include <sstream>
#include <iomanip>
#include <string>
#include "Command.h"
#include "Connect.h"
#include "Self.h"

Commands::Commands(Connect *connect) {
	this->connect = connect;
}

Commands::~Commands() {

}

void Commands::move(double x, double y) {
	std::stringstream ss;
	ss << "(move " << std::setprecision(4) << x << " " << y << ")" << std::endl;
	std::string command;
	std::getline(ss, command);
	commands_to_send.push_back(Command(command, 1, Command::COMMAND_TYPE::MOVE));
	Self::onMoveCommand(x, y);
}

void Commands::turn(double moment) {
	std::stringstream ss;
	ss << "(turn " << std::setprecision(4) << moment << ")" << std::endl;
	std::string command;
	std::getline(ss, command);
	commands_to_send.push_back(Command(command, 1, Command::COMMAND_TYPE::TURN));
}

void Commands::dash(double power, double direction) {
	std::stringstream ss;
	ss << "(dash " << std::setprecision(4) << power << " " << direction << ")" << std::endl;
	std::string command;
	std::getline(ss, command);
	commands_to_send.push_back(Command(command, 1, Command::COMMAND_TYPE::DASH));
}

void Commands::say(std::string message) {
	std::string command = "(say " + message + ")";
	commands_to_send.push_back(Command(command, 1, Command::COMMAND_TYPE::SAY));
}

int Commands::sendCommands() {
	int commands_sent = 0;
	if (commands_to_send.size() > 0) {
		std::string message = "";
		int weight = 0;
		do {
			weight += commands_to_send.at(0).getWeight();
			if (weight < 2) {
				message += commands_to_send.at(0).getCommand();
				switch (commands_to_send.at(0).getCommandType()) {
				case Command::COMMAND_TYPE::MOVE:
					break;
				default:
					break;
				}
				commands_to_send.erase(commands_to_send.begin());
				commands_sent++;
			}
		} while (weight < 2 && commands_to_send.size() > 0);
		connect->sendMessage(message);
	}
	commands_to_send.clear();
	return commands_sent;
}
