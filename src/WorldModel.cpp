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

#include "WorldModel.h"

WorldModel::WorldModel(std::vector<Player> players) {
	this->players = players;
}

WorldModel::~WorldModel() {

}

std::vector<Player*> WorldModel::getPlayers() {
	std::vector<Player*> all_players;
	for (std::vector<Player>::iterator it = players.begin(); it != players.end(); ++it) {
		all_players.push_back(&(*it));
	}
	return all_players;
}

std::vector<Player*> WorldModel::getOurPlayers() {
	std::vector<Player*> our_players;
	for (std::vector<Player>::iterator it = players.begin(); it != players.end(); ++it) {
		if (it->getTeam().compare("our") == 0) {
			our_players.push_back(&(*it));
		}
	}
	return our_players;
}

std::vector<Player*> WorldModel::getOppPlayers() {
	std::vector<Player*> opp_players;
	for (std::vector<Player>::iterator it = players.begin(); it != players.end(); ++it) {
		if (it->getTeam().compare("opp") == 0) {
			opp_players.push_back(&(*it));
		}
	}
	return opp_players;
}

std::vector<Player*> WorldModel::getUndPlayers() {
	std::vector<Player*> und_players;
	for (std::vector<Player>::iterator it = players.begin(); it != players.end(); ++it) {
		if (it->getTeam().compare("undefined") == 0) {
			und_players.push_back(&(*it));
		}
	}
	return und_players;
}
