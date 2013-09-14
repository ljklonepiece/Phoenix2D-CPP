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

#include "Vector2D.h"
#include <cmath>
#include "Self.h"

Vector2D::Vector2D(double magnitude, double direction) {
	dx = magnitude * cos(Self::PI * direction / 180.0);
	dy = magnitude * sin(Self::PI * direction / 180.0);
	this->magnitude = magnitude;
	this->direction = direction;
}

Vector2D::~Vector2D() {

}

Vector2D Vector2D::getVector2DWithMagnitudeAndDirection(double magnitude, double direction) {
	return Vector2D(magnitude, direction);
}

Vector2D Vector2D::getVector2DWithXAndY(double dx, double dy) {
	double magnitude = sqrt(pow(dx, 2.0) + pow(dy, 2.0));
	double direction = 180.0 * atan2(dy, dx) / Self::PI;
	return Vector2D(magnitude, direction);
}

double Vector2D::getXComponent() {
	return dx;
}

double Vector2D::getYComponent() {
	return dy;
}

double Vector2D::getMagnitude() {
	return magnitude;
}

double Vector2D::getDirection() {
	return direction;
}
