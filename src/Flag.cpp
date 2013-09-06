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

#include "Flag.h"
#include <sstream>
#include <cstdlib>

_coordinate::_coordinate(double x0, double y0) {
	if (Self::SIDE.compare("r") == 0) {
		x = -1.0 * x0;
		y = -1.0 * y0;
	} else {
		x = x0;
		y = y0;
	}
}

std::map<std::string, Coordinate> Flag::FIELD = {
		{"f t 0",    Coordinate(  0.0, -39.0)},
		{"f t r 10", Coordinate( 10.0, -39.0)},
		{"f t r 20", Coordinate( 20.0, -39.0)},
		{"f t r 30", Coordinate( 30.0, -39.0)},
		{"f t r 40", Coordinate( 40.0, -39.0)},
		{"f t r 50", Coordinate( 50.0, -39.0)},
		{"f r t 30", Coordinate( 57.5, -30.0)},
		{"f r t 20", Coordinate( 57.5, -20.0)},
		{"f r t 10", Coordinate( 57.5, -10.0)},
		{"f r 0",    Coordinate( 57.5,   0.0)},
		{"f r b 10", Coordinate( 57.5,  10.0)},
		{"f r b 20", Coordinate( 57.5,  20.0)},
		{"f r b 30", Coordinate( 57.5,  30.0)},
		{"f b r 50", Coordinate( 50.0,  39.0)},
		{"f b r 40", Coordinate( 40.0,  39.0)},
		{"f b r 30", Coordinate( 30.0,  39.0)},
		{"f b r 20", Coordinate( 20.0,  39.0)},
		{"f b r 10", Coordinate( 10.0,  39.0)},
		{"f b 0",    Coordinate(  0.0,  39.0)},
		{"f b l 10", Coordinate(-10.0,  39.0)},
		{"f b l 20", Coordinate(-20.0,  39.0)},
		{"f b l 30", Coordinate(-30.0,  39.0)},
		{"f b l 40", Coordinate(-40.0,  39.0)},
		{"f b l 50", Coordinate(-50.0,  39.0)},
		{"f l b 30", Coordinate(-57.5,  30.0)},
		{"f l b 20", Coordinate(-57.5,  20.0)},
		{"f l b 10", Coordinate(-57.5,  10.0)},
		{"f l 0",    Coordinate(-57.5,   0.0)},
		{"f l t 10", Coordinate(-57.5, -10.0)},
		{"f l t 20", Coordinate(-57.5, -20.0)},
		{"f l t 30", Coordinate(-57.5, -30.0)},
		{"f t l 50", Coordinate(-50.0, -39.0)},
		{"f t l 40", Coordinate(-40.0, -39.0)},
		{"f t l 30", Coordinate(-30.0, -39.0)},
		{"f t l 20", Coordinate(-20.0, -39.0)},
		{"f t l 10", Coordinate(-10.0, -39.0)},
		{"f c",      Coordinate(  0.0,   0.0)},
		{"f c t",    Coordinate(  0.0, -34.0)},
		{"f r t",    Coordinate( 52.5, -34.0)},
		{"f r b",    Coordinate( 52.5,  34.0)},
		{"f c b",    Coordinate(  0.0,  34.0)},
		{"f l b",    Coordinate(-52.5,  34.0)},
		{"f l t",    Coordinate(-52.5, -34.0)},
		{"g l",      Coordinate(-52.5,   0.0)},
		{"f g l t",  Coordinate(-52.5,  -7.0)},
		{"f p l t",  Coordinate(-36.0, -20.0)},
		{"f p l c",  Coordinate(-36.0,   0.0)},
		{"f p l b",  Coordinate(-36.0,  20.0)},
		{"f g l b",  Coordinate(-52.5,   7.0)},
		{"g r",      Coordinate( 52.5,   0.0)},
		{"f g r t",  Coordinate( 52.5,  -7.0)},
		{"f p r t",  Coordinate( 52.5, -20.0)},
		{"f p r c",  Coordinate( 36.0,   0.0)},
		{"f p r b",  Coordinate( 36.0,  20.0)},
		{"f g r b",  Coordinate( 52.5,   7.0)}
};

Flag::Flag(std::string name, std::string position, int simulation_time) {
	this->name = name;
	this->simulation_time = simulation_time;
	std::stringstream ss(position);
	std::string token;
	std::getline(ss, token, ' ');
	distance = atof(token.c_str());
	std::getline(ss, token, ' ');
	direction = atof(token.c_str());
	x = Flag::FIELD[name].x;
	y = Flag::FIELD[name].y;
}

Flag::~Flag() {

}

std::string Flag::getName() {
	return name;
}

double Flag::getDistance() {
	return distance;
}

double Flag::getDirection() {
	return direction;
}

double Flag::getX() {
	return x;
}

double Flag::getY() {
	return y;
}
