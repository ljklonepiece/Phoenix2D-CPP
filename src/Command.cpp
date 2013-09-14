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

#include "Command.h"

Command::Command(std::string command, int weight, Command::COMMAND_TYPE type, void *arg_0, void *arg_1) {
	this->command = command;
	this->weight = weight;
	this->type = type;
	switch(type) {
	case MOVE:
		double_arg_0 = *((double *)arg_0);
		double_arg_1 = *((double *)arg_1);
		string_arg_0 = "";
		break;
	case DASH:
		double_arg_0 = *((double *)arg_0);
		double_arg_1 = *((double *)arg_1);
		string_arg_0 = "";
		break;
	case TURN:
		double_arg_0 = *((double *)arg_0);
		double_arg_1 = 0.0;
		string_arg_0 = "";
		break;
	case SAY:
		double_arg_0 = 0.0;
		double_arg_1 = 0.0;
		string_arg_0 = *((std::string *)arg_0);
		break;
	}
}

Command::~Command() {

}

std::string Command::getCommand() {
	return command;
}

int Command::getWeight() {
	return weight;
}

Command::COMMAND_TYPE Command::getCommandType() {
	return type;
}

double Command::getDashPower() {
	return double_arg_0;
}

double Command::getDashDirection() {
	return double_arg_1;
}

double Command::getTurnMoment() {
	return double_arg_0;
}

double Command::getMoveX() {
	return double_arg_0;
}

double Command::getMoveY() {
	return double_arg_1;
}

std::string Command::getSayMessage() {
	return string_arg_0;
}
