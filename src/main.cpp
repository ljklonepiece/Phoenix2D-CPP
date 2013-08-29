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

#include "Controller.h"
#include <iostream>
#include "Game.h"
#include "Commands.h"
#include "BeforeKickOff.h"

int main() {
	Controller controller("Nemesis", 'p', "localhost");
	controller.connect();
	Commands *commands = controller.getCommands();
	BeforeKickOff before_kick_off(commands);
	int i = 0;
	while (Game::nextCycle() && i < 1200) {
		before_kick_off.onPlayerExecute();
		before_kick_off.onPostExecute();
		i++;
	}
	controller.disconnect();
	return 0;
}
