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

std::vector<Player> WorldModel::getPlayers() {
	return players;
}

std::vector<Player> WorldModel::getOurPlayers() {
	std::vector<Player> ourPlayers;
	for (std::vector<Player>::iterator it = players.begin(); it != players.end(); ++it) {
		if ((*it).getTeam().compare("our") == 0) {
			ourPlayers.push_back(*it);
		}
	}
	return ourPlayers;
}

std::vector<Player> WorldModel::getOppPlayers() {
	std::vector<Player> oppPlayers;
	for (std::vector<Player>::iterator it = players.begin(); it != players.end(); ++it) {
		if ((*it).getTeam().compare("opp") == 0) {
			oppPlayers.push_back(*it);
		}
	}
	return oppPlayers;
}

std::vector<Player> WorldModel::getUndPlayers() {
	std::vector<Player> undPlayers;
	for (std::vector<Player>::iterator it = players.begin(); it != players.end(); ++it) {
		if ((*it).getTeam().compare("undefined") == 0) {
			undPlayers.push_back(*it);
		}
	}
	return undPlayers;
}
