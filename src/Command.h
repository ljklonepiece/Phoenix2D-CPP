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

#ifndef COMMAND_H_
#define COMMAND_H_

#include <string>

class Command {
public:
	enum COMMAND_TYPE {
		MOVE,
		DASH,
		TURN,
		SAY
	};
	Command(std::string command, int weight, Command::COMMAND_TYPE type, void *arg_0, void *arg_1);
	~Command();
	std::string getCommand();
	int getWeight();
	Command::COMMAND_TYPE getCommandType();
	double getDashPower();
	double getDashDirection();
	double getTurnMoment();
	double getMoveX();
	double getMoveY();
	std::string getSayMessage();
private:
	std::string command;
	int weight;
	Command::COMMAND_TYPE type;
	double double_arg_0;
	double double_arg_1;
	std::string string_arg_0;
};

#endif /* COMMAND_H_ */
