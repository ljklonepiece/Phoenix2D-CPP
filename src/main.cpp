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
#include "Game.h"
#include "Commands.h"
#include "BeforeKickOff.h"
#include "PlayOn.h"
#include <map>
#include "PlayMode.h"
#include "World.h"

int main(int argc, char **argv) {
	if (argc < 3) return 0;
	Controller controller(argv[1], argv[2][0], "localhost");
	controller.connect();
	Commands *commands = controller.getCommands();
	World *world = controller.getWorld();
	std::map<std::string, PlayMode*> play_modes;
	//before_kick_off corner_kick_l corner_kick_r free_kick_l free_kick_r goal_kick_l goal_kick_r kick_in_l kick_in_r kick_off_l kick_off_r play_on
	play_modes["before_kick_off"] = new BeforeKickOff(commands);
	play_modes["play_on"]         = new PlayOn(commands);
	int i = 0;
	while (Game::nextCycle() && i < 1200) {
		std::string play_mode = Game::PLAY_MODE;
		switch (Controller::AGENT_TYPE) {
		case 'p':
			play_modes[play_mode]->onPlayerExecute(world->getWorldModel());
			break;
		case 'g':
			play_modes[play_mode]->onGoalieExecute(world->getWorldModel());
			break;
		case 'c':
			play_modes[play_mode]->onCoachExecute(world->getWorldModel());
			break;
		default:
			break;
		}
		play_modes[play_mode]->onPostExecute();
	}
	//This must be always called in order to avoid memory leaks
	for (std::map<std::string, PlayMode*>::iterator it = play_modes.begin(); it != play_modes.end(); ++it) {
		delete it->second;
		play_modes.erase(it);
	}
	controller.disconnect();
	return 0;
}
