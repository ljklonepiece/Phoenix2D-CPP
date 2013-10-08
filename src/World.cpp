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

#include "World.h"
#include "Game.h"
#include "Config.h"

World::World() {
	player_id = 0;
}

World::~World() {

}

void World::updateWorld(std::vector<Player> players, std::vector<Ball> ball) {
	if (players_history.size() == Config::PLAYER_MAX_HISTORY) {
		players_history.pop_back();
	}
	if (ball_history.size() == Config::BALL_MAX_HISTORY) {
		ball_history.pop_back();
	}
	std::map<int, Player> new_players;
	for (std::vector<Player>::iterator it = players.begin(); it != players.end(); ++it) {
		int id = player_id++;
		it->setPlayerId(id);
		//new_players.insert(std::pair<int, Player>(player_id++, *it));
		new_players[id] = *it;
	}
	for (std::vector<Player>::iterator it = players_history.front().begin(); it != players_history.front().end(); ++it) {
		double vision_angle = 180.0;
		if (Self::VIEW_MODE_WIDTH.compare("narrow") == 0) {
			vision_angle = 60.0;
		} else if (Self::VIEW_MODE_WIDTH.compare("normal")) {
			vision_angle = 120.0;
		}
		if (Self::getPosition().getDirectionTo(&(it->getPosition())) > vision_angle) {
			new_players[it->getPlayerId()] == *it;
		}
	}
	if (ball.size() == 0) {
		if (ball_history.size() > 0) {
			ball_history.push_front(Ball(Game::SIMULATION_TIME));
		} else {

		}
	} else {
		ball_history.push_front(ball.front());
	}
	players_history.push_front(new_players);
}

WorldModel World::getWorldModel() {
	std::vector<Player> players;
	std::map<int, Player> current_players = players_history.front();
	for (std::map<int, Player>::iterator it = current_players.begin(); it != current_players.end(); ++it) {
		players.push_back(it->second);
	}
	return WorldModel(players);
}
