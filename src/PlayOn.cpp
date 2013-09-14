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

#include "PlayOn.h"
#include "Commands.h"
#include "Game.h"
#include "Self.h"
#include "Position.h"
#include <iostream>

PlayOn::PlayOn(Commands *commands) : PlayMode(commands) {

}

PlayOn::~PlayOn() {

}

void PlayOn::onPlayerExecute(WorldModel world) {
	if (Game::SIMULATION_TIME % 20 == 0) {
		commands->dash(70.0, 0.0);
	}
	Position pos = Self::getPosition();
	std::cout << "I'm in x: " << pos.getX() << ", y: " << pos.getY() << ", direction: " << pos.getBodyDirection() << std::endl;
}

void PlayOn::onGoalieExecute(WorldModel world) {

}

void PlayOn::onCoachExecute(WorldModel world) {

}