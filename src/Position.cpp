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

#include "Position.h"

Position::Position(double x, double y) {
	this->x = x;
	this->y = y;
	theta = 0.0;
	gamma = 0.0;
}

Position::Position(double x, double y, double theta) {
	this->x = x;
	this->y = y;
	this->theta = theta;
	gamma = 0.0;
}

Position::Position(double x, double y, double theta, double gamma) {
	this->x = x;
	this->y = y;
	this->theta = theta;
	this->gamma = gamma;
}

Position::~Position() {

}

double Position::getX() {
	return x;
}

double Position::getY() {
	return y;
}

double Position::getBodyDirection() {
	return theta;
}

double Position::getHeadDirection() {
	return gamma;
}
