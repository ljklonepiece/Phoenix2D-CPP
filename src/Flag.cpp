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
#include "Self.h"

_coordinate makeCoordinate(double x, double y) {
	if (Self::SIDE.compare("r") == 0) {
		x *= -1.0;
		y *= -1.0;
	}
	_coordinate c = {x , y};
	return c;
}

std::map<std::string, _coordinate> getField() {
	std::map<std::string, _coordinate> field;
	field["f t 0"]    = makeCoordinate( 0.0, -39.0);
	field["f t r 10"] = makeCoordinate( 10.0, -39.0);
	field["f t r 20"] = makeCoordinate( 20.0, -39.0);
	field["f t r 30"] = makeCoordinate( 30.0, -39.0);
	field["f t r 40"] = makeCoordinate( 40.0, -39.0);
	field["f t r 50"] = makeCoordinate( 50.0, -39.0);
	field["f r t 30"] = makeCoordinate( 57.5, -30.0);
	field["f r t 20"] = makeCoordinate( 57.5, -20.0);
	field["f r t 10"] = makeCoordinate( 57.5, -10.0);
	field["f r 0"]    = makeCoordinate( 57.5,   0.0);
	field["f r b 10"] = makeCoordinate( 57.5,  10.0);
	field["f r b 20"] = makeCoordinate( 57.5,  20.0);
	field["f r b 30"] = makeCoordinate( 57.5,  30.0);
	field["f b r 50"] = makeCoordinate( 50.0,  39.0);
	field["f b r 40"] = makeCoordinate( 40.0,  39.0);
	field["f b r 30"] = makeCoordinate( 30.0,  39.0);
	field["f b r 20"] = makeCoordinate( 20.0,  39.0);
	field["f b r 10"] = makeCoordinate( 10.0,  39.0);
	field["f b 0"]    = makeCoordinate(  0.0,  39.0);
	field["f b l 10"] = makeCoordinate(-10.0,  39.0);
	field["f b l 20"] = makeCoordinate(-20.0,  39.0);
	field["f b l 30"] = makeCoordinate(-30.0,  39.0);
	field["f b l 40"] = makeCoordinate(-40.0,  39.0);
	field["f b l 50"] = makeCoordinate(-50.0,  39.0);
	field["f l b 30"] = makeCoordinate(-57.5,  30.0);
	field["f l b 20"] = makeCoordinate(-57.5,  20.0);
	field["f l b 10"] = makeCoordinate(-57.5,  10.0);
	field["f l 0"]    = makeCoordinate(-57.5,   0.0);
	field["f l t 10"] = makeCoordinate(-57.5, -10.0);
	field["f l t 20"] = makeCoordinate(-57.5, -20.0);
	field["f l t 30"] = makeCoordinate(-57.5, -30.0);
	field["f t l 50"] = makeCoordinate(-50.0, -39.0);
	field["f t l 40"] = makeCoordinate(-40.0, -39.0);
	field["f t l 30"] = makeCoordinate(-30.0, -39.0);
	field["f t l 20"] = makeCoordinate(-20.0, -39.0);
	field["f t l 10"] = makeCoordinate(-10.0, -39.0);
	field["f c"]      = makeCoordinate(  0.0,   0.0);
	field["f c t"]    = makeCoordinate(  0.0, -34.0);
	field["f r t"]    = makeCoordinate( 52.5, -34.0);
	field["f r b"]    = makeCoordinate( 52.5,  34.0);
	field["f c b"]    = makeCoordinate(  0.0,  34.0);
	field["f l b"]    = makeCoordinate(-52.5,  34.0);
	field["f l t"]    = makeCoordinate(-52.5, -34.0);
	field["g l"]      = makeCoordinate(-52.5,   0.0);
	field["f g l t"]  = makeCoordinate(-52.5,  -7.0);
	field["f p l t"]  = makeCoordinate(-36.0, -20.0);
	field["f p l c"]  = makeCoordinate(-36.0,   0.0);
	field["f p l b"]  = makeCoordinate(-36.0,  20.0);
	field["f g l b"]  = makeCoordinate(-52.5,   7.0);
	field["g r"]      = makeCoordinate( 52.5,   0.0);
	field["f g r t"]  = makeCoordinate( 52.5,  -7.0);
	field["f p r t"]  = makeCoordinate( 52.5, -20.0);
	field["f p r c"]  = makeCoordinate( 36.0,   0.0);
	field["f p r b"]  = makeCoordinate( 36.0,  20.0);
	field["f g r b"]  = makeCoordinate( 52.5,   7.0);
	return field;
}

std::map<std::string, _coordinate> Flag::FIELD;

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

void Flag::initializeField() {
	Flag::FIELD = getField();
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
