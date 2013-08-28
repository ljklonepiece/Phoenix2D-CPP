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

#include "Reader.h"
#include <string>
#include <iostream>
#include "Connect.h"
#include "Parser.h"

Reader::Reader(Connect *connect, Parser *parser) {
	this->connect = connect;
	this->parser = parser;
	running = false;
	thread = 0;
}

Reader::~Reader() {
	if (parser) delete parser;
}

void *Reader::run(void *arg) {
	Reader* reader = (Reader *)arg;
	reader->execute();
	return 0;
}

void Reader::execute() {
	while (running) {
		parser->parseMessage(connect->receiveMessage());
	}
	std::cout << "Reader::read() -> thread stopped" << std::endl;
}

bool Reader::isRunning() {
	return running;
}

void Reader::start() {
	running = true;
	int success = pthread_create(&thread, 0, Reader::run, this);
	if (success) {
		running = false;
		std::cerr << "Reader::start() -> error creating thread" << std::endl;
	}
}

void Reader::stop() {
	void *res;
	running = false;
	connect->sendMessage("(bye)");
	connect->disconnect();
	int success = pthread_join(thread, &res);
	if (success) {
		std::cerr << "Reader::stop() -> failed to join thread" << std::endl;
	}
}
