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

#ifndef SELF_H_
#define SELF_H_

#include <string>
#include <vector>
#include <boost/regex.hpp>
#include <vector>
#include "Flag.h"

class Self {
	int    *types_id;
	double *player_speed_max;
	double *stamina_inc_max;
	double *player_decay;
	double *inertia_moment;
	double *dash_power_rate;
	double *player_size;
	double *kickable_margin;
	double *kick_rand;
	double *extra_stamina;
	double *effort_max;
	double *effort_min;
	double *kick_power_rate;
	double *foul_detect_probability;
	double *catchable_area_l_stretch;
	std::string player_params;
	std::string getParameter(std::string parameter);
	std::string getParameter(std::string player_type, std::string parameter);
	boost::regex sense_body;
	static double x;
	static double y;
	static double theta;
public:
	static std::string TEAM_NAME;
	static int         UNIFORM_NUMBER;
	static std::string SIDE;
	static int         ALLOW_MULT_DEFAULT_TYPE;
	static double      CATCHABLE_AREA_L_STRECH_MAX;
	static double      CATCHABLE_AREA_L_STRECH_MIN;
	static double      DASH_POWER_RATE_DELTA_MAX;
	static double      DASH_POWER_RATE_DELTA_MIN;
	static double      EFFORT_MAX_DELTA_FACTOR;
	static double      EFFORT_MIN_DELTA_FACTOR;
	static double      EXTRA_STAMINA_DELTA_MAX;
	static double      EXTRA_STAMINA_DELTA_MIN;
	static double      FOUL_DETECT_PROBABILITY_DELTA_FACTOR;
	static double      INERTIA_MOMENT_DELTA_FACTOR;
	static double      KICK_POWER_RATE_DELTA_MAX;
	static double      KICK_POWER_RATE_DELTA_MIN;
	static double      KICK_RAND_DELTA_FACTOR;
	static double      KICKABLE_MARGIN_DELTA_MAX;
	static double      KICKABLE_MARGIN_DELTA_MIN;
	static double      NEW_DASH_POWER_RATE_DELTA_MAX;
	static double      NEW_DASH_POWER_RATE_DELTA_MIN;
	static double      NEW_STAMINA_INC_MAX_DELTA_FACTOR;
	static double      PLAYER_DECAY_DELTA_MAX;
	static double      PLAYER_DECAY_DELTA_MIN;
	static double      PLAYER_SIZE_DELTA_FACTOR;
	static double      PLAYER_SPEED_MAX_DELTA_MAX;
	static double      PLAYER_SPEED_MAX_DELTA_MIN;
	static int         PLAYER_TYPES;
	static int         PT_MAX;
	static int         RANDOM_SEED;
	static double      STAMINA_INC_MAX_DELTA_FACTOR;
	static int         SUBS_MAX;
	static int         TYPE_ID;
	static double      PLAYER_SPEED_MAX;
	static double      STAMINA_INC_MAX;
	static double      PLAYER_DECAY;
	static double      INERTIA_MOMENT;
	static double      DASH_POWER_RATE;
	static double      PLAYER_SIZE;
	static double      KICKABLE_MARGIN;
	static double      KICK_RAND;
	static double      EXTRA_STAMINA;
	static double      EFFORT_MAX;
	static double      EFFORT_MIN;
	static double      KICK_POWER_RATE;
	static double      FOUL_DETECT_PROBABILITY;
	static double      CATCHABLE_AREA_L_STRETCH;
	static std::string VIEW_MODE_WIDTH;
	static std::string VIEW_MODE_QUALITY;
	static double      STAMINA;
	static double      EFFORT;
	static double      STAMINA_CAPACITY;
	static double      AMOUNT_OF_SPEED;
	static double      DIRECTION_OF_SPEED;
	static double      HEAD_ANGLE;
	static int         KICK_COUNT;
	static int         DASH_COUNT;
	static int         TURN_COUNT;
	static int         SAY_COUNT;
	static int         TURN_NECK_COUNT;
	static int         CATCH_COUNT;
	static int         MOVE_COUNT;
	static int         CHANGE_VIEW_COUNT;
	static int         ARM_MOVABLE;
	static int         ARM_EXPIRES;
	static double      ARM_DIST;
	static double      ARM_DIR;
	static int         ARM_COUNT;
	static std::string FOCUS_TARGET;
	static int         FOCUS_COUNT;
	static int         TACKLE_EXPIRES;
	static int         TACKLE_COUNT;
	static std::vector<std::string> COLLISION;
	static int         FOUL_CHARGED;
	static std::string FOUL_CARD;
	Self(std::string player_params, std::string team_name, int unum, std::string side);
	~Self();
	void addPlayerType(std::string player_type);
	void processSenseBody(std::string sense_body);
	void changePlayerType(int type);
	void localize(std::vector<Flag> flags);
	void localize();
};

#endif /* SELF_H_ */
