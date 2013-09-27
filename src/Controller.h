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

#ifndef CONTROLLER_H_
#define CONTROLLER_H_

#include <string>

class Connect;
class Reader;
class Server;
class Parser;
class Commands;
class World;
class Self;

class Controller {
	Connect* c;
	Reader* reader;
	Server* server;
	Commands* commands;
	World* world;
	Self* self;
	bool connected;
	std::string team_name;
	std::string hostname;
public:
	static char AGENT_TYPE;
	Controller(const char *teamName, char agentType, const char *hostname);
	~Controller();
	void connect();
	bool isConnected();
	void reconnect();
	void disconnect();
	Commands* getCommands();
	World* getWorld();
	Self* getSelf();
};

#endif /* CONTROLLER_H_ */
