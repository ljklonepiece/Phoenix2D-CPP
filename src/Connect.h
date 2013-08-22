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

#ifndef CONNECT_H_
#define CONNECT_H_

#include <sys/socket.h>
#include <arpa/inet.h>
#include <string>

typedef struct _socket {
	int socketfd;
	struct sockaddr_in server;
} Socket;

class Connect {
	Socket sock;
	void connectToServer(const char *host, int port);
public:
	Connect(const char *host, int port);
	~Connect();
	bool        sendMessage(std::string msg);
	std::string receiveMessage();
};

#endif /* CONNECT_H_ */
