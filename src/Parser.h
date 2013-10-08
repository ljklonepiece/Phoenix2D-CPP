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

#ifndef PARSER_H_
#define PARSER_H_

#include <string>
#include <boost/regex.hpp>
#include <pthread.h>

class Self;
class Game;
class World;
class PlayMode;

class Parser {
	static Self *self;
	static Game *game;
	static World *world;
	static boost::regex sense_body;
	boost::regex hear_regex;
	boost::regex hear_player_regex;
	static boost::regex see_regex;
	static void *process_sense_body(void *arg);
	static std::string sense_body_message;
	static std::string see_message;
	static void *process_see(void *arg);
	pthread_t thread_sense_body;
	pthread_t thread_see;
	static bool processing_see;
	static pthread_cond_t SEE_COND;
	static pthread_mutex_t SEE_MUTEX;
	static PlayMode* active_play_mode;
public:
	Parser(Self *self, World *world);
	~Parser();
	void parseMessage(std::string message);
	static void registerPlayMode(PlayMode* play_mode);
};

#endif /* PARSER_H_ */
