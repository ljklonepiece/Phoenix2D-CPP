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

World::World() {
	player_id = 0;
	max_history = 32;
}

World::~World() {

}

void World::updateWorld(std::vector<Player> players, std::vector<Ball> ball) {
	if (players_history.size() == max_history) {
		players_history.pop_back();
	}
	if (ball_history.size() == max_history) {
		ball_history.pop_back();
	}
	std::map<int, Player> new_players;
	for (std::vector<Player>::iterator it = players.begin(); it != players.end(); ++it) {
		//int id = player_id++;
		new_players.insert(std::pair<int, Player>(player_id++, *it));
		//new_players[player_id++] = (Player)(*it);
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
