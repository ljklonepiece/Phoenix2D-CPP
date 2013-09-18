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
	commands_to_send.push_back(Command(command, 1, Command::MOVE, (void *)&x, (void *)&y));
	Self::onMoveCommand(x, y);
}

void Commands::turn(double moment) {
	std::stringstream ss;
	ss << "(turn " << std::setprecision(4) << moment << ")" << std::endl;
	std::string command;
	std::getline(ss, command);
	commands_to_send.push_back(Command(command, 1, Command::TURN, (void *)&moment, 0));
}

void Commands::turnNeck(double moment) {
	std::stringstream ss;
	ss << "(turn_neck " << std::setprecision(4) << moment << ")" << std::endl;
	std::string command;
	std::getline(ss, command);
	commands_to_send.push_back(Command(command, 0, Command::TURN_NECK, (void *)&moment, 0));
}

void Commands::dash(double power, double direction) {
	std::stringstream ss;
	ss << "(dash " << std::setprecision(4) << power << " " << direction << ")" << std::endl;
	std::string command;
	std::getline(ss, command);
	commands_to_send.push_back(Command(command, 1, Command::DASH, (void *)&power, (void *)&direction));
}

void Commands::say(std::string message) {
	std::string command = "(say " + message + ")";
	commands_to_send.push_back(Command(command, 1, Command::SAY, (void *)&message, 0));
}

void Commands::catchBall(double direction) {
	std::stringstream ss;
	ss << "(catch " << std::setprecision(4) << direction << ")" << std::endl;
	std::string command;
	std::getline(ss, command);
	commands_to_send.push_back(Command(command, 1, Command::CATCH, (void *)&direction, 0));
}

void Commands::kick(double power, double direction) {
	std::stringstream ss;
	ss << "(kick " << std::setprecision(4) << power << " " << direction << ")" << std::endl;
	std::string command;
	std::getline(ss, command);
	commands_to_send.push_back(Command(command, 1, Command::KICK, (void *)&power, (void *)&direction));
}

void Commands::tackle(double power, bool willToFoul) {
	std::stringstream ss;
	ss << "(tackle " << std::setprecision(4) << power << (willToFoul ? " true" : " false") << std::endl;
	std::string command;
	std::getline(ss, command);
	commands_to_send.push_back(Command(command, 1, Command::TACKLE, (void *)&power, (void *)willToFoul));
}

void Commands::pointTo(double distance, double direction) {
	std::stringstream ss;
	ss << "(pointto " << std::setprecision(4) << distance << " " << direction << ")" << std::endl;
	std::string command;
	std::getline(ss, command);
	commands_to_send.push_back(Command(command, 1, Command::POINT, (void *)&distance, (void *)&direction));
}

void Commands::changeView(std::string width) {
	std::string command = "(change_view " + width + ")";
	commands_to_send.push_back(Command(command, 1, Command::CHANGE_VIEW, (void *)&width, 0));
}

void Commands::moveObject(std::string object, double x, double y) {
	std::stringstream ss;
	ss << "(move " << object << " " << std::setprecision(4) << x << " " << y << ")" << std::endl;
	std::string command;
	std::getline(ss, command);
	commands_to_send.push_back(Command(command, 1, Command::MOVE_OBJECT, 0, 0));
}

void Commands::changeMode(std::string mode) {
	std::string command = "(change_mode " + mode + ")";
	commands_to_send.push_back(Command(command, 1, Command::CHANGE_MODE, (void *)&mode, 0));
}

void Commands::start() {
	std::string command = "(start)";
	commands_to_send.push_back(Command(command, 1, Command::START, 0, 0));
}

void Commands::recover() {
	std::string command = "(recover)";
	commands_to_send.push_back(Command(command, 1, Command::RECOVER, 0, 0));
}

int Commands::sendCommands() {
	int commands_sent = 0;
	if (commands_to_send.size() > 0) {
		std::string message = "";
		int weight = 0;
		do {
			Command *command_to_send = &commands_to_send.at(0);
			weight += command_to_send->getWeight();
			if (weight < 2) {
				message += command_to_send->getCommand();
				switch (command_to_send->getCommandType()) {
				case Command::MOVE:
					Self::onMoveCommand(command_to_send->getMoveX(), command_to_send->getMoveY());
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
