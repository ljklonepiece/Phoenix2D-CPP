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

#include "Config.h"
#include <fstream>
#include "Position.h"
#include <boost/regex.hpp>
#include <cstdlib>

boost::regex position_regex("\\(position\\s(\\d+)\\s\\([\\d\\.\\-]+)\\s\\([\\d\\.\\-]+)\\)");

int Config::POSITIONS[12];
int Config::BUFFER_MAX_HISTORY = 8;
int Config::PLAYER_MAX_HISTORY = 16;
int Config::BALL_MAX_HISTORY = 16;
bool Config::LOGGING = false;

Config::Config() {
	std::ifstream file("conf.phx", std::ifstream::in);
	Config::POSITIONS[0] = Position(0.0, 0.0);
	if (file) {
		std::string line;
		while (std::getline(file, line)) {
			boost::cmatch match;
			if (boost::regex_match(line.c_str(), match, position_regex)) {
				int number = atoi((std::string() + match[1]).c_str());
				double x = atof((std::string() + match[2]).c_str());
				double y = atof((std::string() + match[3]).c_str());
				Config::POSITIONS[number] = Position(x, y);
			}
		}
		file.close();
	} else {
		Config::POSITIONS[1] = Position(-50.0, 0.0);
		Config::POSITIONS[2] = Position(-10.0, 0.0);
		Config::POSITIONS[3] = Position(-1.0, -10.0);
		Config::POSITIONS[4] = Position(-1.0, 10.0);
		Config::POSITIONS[5] = Position(-12.0, 0.0);
		Config::POSITIONS[6] = Position(-2.0, -11.0);
		Config::POSITIONS[7] = Position(-2.0, 11.0);
		Config::POSITIONS[8] = Position(-14.0, -5.0);
		Config::POSITIONS[9] = Position(-14.0, 5.0);
		Config::POSITIONS[10] = Position(-14.0, -10.0);
		Config::POSITIONS[11] = Position(-14.0, 10.0);
	}
}

Config::~Config() {

}
