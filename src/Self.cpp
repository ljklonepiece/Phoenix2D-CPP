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

#include "Self.h"
#include <boost/regex.hpp>
#include <cstdlib>

int         Self::ALLOW_MULT_DEFAULT_TYPE              = 0;
double      Self::CATCHABLE_AREA_L_STRECH_MAX          = 1.3;
double      Self::CATCHABLE_AREA_L_STRECH_MIN          = 1.0;
double      Self::DASH_POWER_RATE_DELTA_MAX            = 0.0;
double      Self::DASH_POWER_RATE_DELTA_MIN            = 0.0;
double      Self::EFFORT_MAX_DELTA_FACTOR              = -0.004;
double      Self::EFFORT_MIN_DELTA_FACTOR              = -0.004;
double      Self::EXTRA_STAMINA_DELTA_MAX              = 50.0;
double      Self::EXTRA_STAMINA_DELTA_MIN              = 0.0;
double      Self::FOUL_DETECT_PROBABILITY_DELTA_FACTOR = 0.0;
double      Self::INERTIA_MOMENT_DELTA_FACTOR          = 25.0;
double      Self::KICK_POWER_RATE_DELTA_MAX            = 0.0;
double      Self::KICK_POWER_RATE_DELTA_MIN            = 0.0;
double      Self::KICK_RAND_DELTA_FACTOR               = 1.0;
double      Self::KICKABLE_MARGIN_DELTA_MAX            = 0.1;
double      Self::KICKABLE_MARGIN_DELTA_MIN            = -0.1;
double      Self::NEW_DASH_POWER_RATE_DELTA_MAX        = 0.0008;
double      Self::NEW_DASH_POWER_RATE_DELTA_MIN        = -0.0012;
double      Self::NEW_STAMINA_INC_MAX_DELTA_FACTOR     = -6000.0;
double      Self::PLAYER_DECAY_DELTA_MAX               = 0.1;
double      Self::PLAYER_DECAY_DELTA_MIN               = -0.1;
double      Self::PLAYER_SIZE_DELTA_FACTOR             = -100.0;
double      Self::PLAYER_SPEED_MAX_DELTA_MAX           = 0.0;
double      Self::PLAYER_SPEED_MAX_DELTA_MIN           = 0.0;
int         Self::PLAYER_TYPES                         = 18;
int         Self::PT_MAX                               = 1;
int         Self::RANDOM_SEED                          = 1325632690;
double      Self::STAMINA_INC_MAX_DELTA_FACTOR         = 0.0;
int         Self::SUBS_MAX                             = 3;
int         Self::TYPE_ID                              = 0;
double      Self::PLAYER_SPEED_MAX                     = 1.05;
double      Self::STAMINA_INC_MAX                      = 45.0;
double      Self::PLAYER_DECAY                         = 0.4;
double      Self::INERTIA_MOMENT                       = 5.0;
double      Self::DASH_POWER_RATE                      = 0.006;
double      Self::PLAYER_SIZE                          = 0.3;
double      Self::KICKABLE_MARGIN                      = 0.7;
double      Self::KICK_RAND                            = 0.1;
double      Self::EXTRA_STAMINA                        = 50.0;
double      Self::EFFORT_MAX                           = 1.0;
double      Self::EFFORT_MIN                           = 0.6;
double      Self::KICK_POWER_RATE                      = 0.027;
double      Self::FOUL_DETECT_PROBABILITY              = 0.5;
double      Self::CATCHABLE_AREA_L_STRETCH             = 1.0;
std::string Self::VIEW_MODE_WIDTH                      = "high";
std::string Self::VIEW_MODE_QUALITY                    = "normal";
double      Self::STAMINA                              = 8000.0;
double      Self::EFFORT                               = 1.0;
double      Self::STAMINA_CAPACITY                     = 130600.0;
double      Self::AMOUNT_OF_SPEED                      = 0.0;
double      Self::DIRECTION_OF_SPEED                   = 0.0;
double      Self::HEAD_ANGLE                           = 0.0;
int         Self::KICK_COUNT                           = 0;
int         Self::DASH_COUNT                           = 0;
int         Self::TURN_COUNT                           = 0;
int         Self::SAY_COUNT                            = 0;
int         Self::TURN_NECK_COUNT                      = 0;
int         Self::CATCH_COUNT                          = 0;
int         Self::MOVE_COUNT                           = 0;
int         Self::CHANGE_VIEW_COUNT                    = 0;
int         Self::ARM_MOVABLE                          = 0;
int         Self::ARM_EXPIRES                          = 0;
double      Self::ARM_DIST                             = 0.0;
double      Self::ARM_DIR                              = 0.0;
int         Self::ARM_COUNT                            = 0;
std::string Self::FOCUS_TARGET                         = "none";
int         Self::FOCUS_COUNT                          = 0;
int         Self::TACKLE_EXPIRES                       = 0;
int         Self::TACKLE_COUNT                         = 0;
std::vector<std::string> Self::COLLISION;              //empty
int         Self::FOUL_CHARGED                         = 0;
std::string Self::FOUL_CARD                            = "none";

Self::Self(const char *player_params) {
	this->player_params = player_params;
	Self::ALLOW_MULT_DEFAULT_TYPE = atoi((char *)getParameter("allow_mult_default_type"));
	Self::CATCHABLE_AREA_L_STRECH_MAX = atof((char *)getParameter("catchable_area_l_stretch_max"));
	Self::CATCHABLE_AREA_L_STRECH_MIN = atof((char *)getParameter("catchable_area_l_stretch_min"));
	Self::DASH_POWER_RATE_DELTA_MAX = atof((char *)getParameter("dash_power_rate_delta_max"));
	Self::DASH_POWER_RATE_DELTA_MIN = atof((char *)getParameter("dash_power_rate_delta_min"));
	Self::EFFORT_MAX_DELTA_FACTOR = atof((char *)getParameter("effort_max_delta_factor"));
	Self::EFFORT_MIN_DELTA_FACTOR = atof((char *)getParameter("effort_min_delta_factor"));
	Self::EXTRA_STAMINA_DELTA_MAX = atof((char *)getParameter("extra_stamina_delta_max"));
	Self::EXTRA_STAMINA_DELTA_MIN = atof((char *)getParameter("extra_stamina_delta_min"));
	Self::FOUL_DETECT_PROBABILITY_DELTA_FACTOR = atof((char *)getParameter("foul_detect_probability_delta_factor"));
	Self::INERTIA_MOMENT_DELTA_FACTOR = atof((char *)getParameter("inertia_moment_delta_factor"));
	Self::KICK_POWER_RATE_DELTA_MAX = atof((char *)getParameter("kick_power_rate_delta_max"));
	Self::KICK_POWER_RATE_DELTA_MIN = atof((char *)getParameter("kick_power_rate_delta_min"));
	Self::KICK_RAND_DELTA_FACTOR = atof((char *)getParameter("kick_rand_delta_factor"));
	Self::KICKABLE_MARGIN_DELTA_MAX = atof((char *)getParameter("kickable_margin_delta_max"));
	Self::KICKABLE_MARGIN_DELTA_MIN = atof((char *)getParameter("kickable_margin_delta_min"));
	Self::NEW_DASH_POWER_RATE_DELTA_MAX = atof((char *)getParameter("new_dash_power_rate_delta_max"));
	Self::NEW_DASH_POWER_RATE_DELTA_MIN = atof((char *)getParameter("new_dash_power_rate_delta_min"));
	Self::NEW_STAMINA_INC_MAX_DELTA_FACTOR = atof((char *)getParameter("new_stamina_inc_max_delta_factor"));
	Self::PLAYER_DECAY_DELTA_MAX = atof((char *)getParameter("player_decay_delta_max"));
	Self::PLAYER_DECAY_DELTA_MIN = atof((char *)getParameter("player_decay_delta_min"));
	Self::PLAYER_SIZE_DELTA_FACTOR = atof((char *)getParameter("player_size_delta_factor"));
	Self::PLAYER_SPEED_MAX_DELTA_MAX = atof((char *)getParameter("player_speed_max_delta_max"));
	Self::PLAYER_SPEED_MAX_DELTA_MIN = atof((char *)getParameter("player_speed_max_delta_min"));
	Self::PLAYER_TYPES = atoi((char *)getParameter("player_types"));
	Self::PT_MAX = atoi((char *)getParameter("pt_max"));
	Self::RANDOM_SEED = atoi((char *)getParameter("random_seed"));
	Self::STAMINA_INC_MAX_DELTA_FACTOR = atof((char *)getParameter("stamina_inc_max_delta_factor"));
	Self::SUBS_MAX = atoi((char *)getParameter("subs_max"));
	types_id = new int[Self::PLAYER_TYPES];
	player_speed_max = new double[Self::PLAYER_TYPES];
	stamina_inc_max = new double[Self::PLAYER_TYPES];
	player_decay = new double[Self::PLAYER_TYPES];
	inertia_moment = new double[Self::PLAYER_TYPES];
	dash_power_rate = new double[Self::PLAYER_TYPES];
	player_size = new double[Self::PLAYER_TYPES];
	kickable_margin = new double[Self::PLAYER_TYPES];
	kick_rand = new double[Self::PLAYER_TYPES];
	extra_stamina = new double[Self::PLAYER_TYPES];
	effort_max = new double[Self::PLAYER_TYPES];
	effort_min = new double[Self::PLAYER_TYPES];
	kick_power_rate = new double[Self::PLAYER_TYPES];
	foul_detect_probability = new double[Self::PLAYER_TYPES];
	catchable_area_l_stretch = new double[Self::PLAYER_TYPES];
}

Self::~Self() {
	if (types_id) delete[] types_id;
	if (player_speed_max) delete[] player_speed_max;
	if (stamina_inc_max) delete[] stamina_inc_max;
	if (player_decay) delete[] player_decay;
	if (inertia_moment) delete[] inertia_moment;
	if (dash_power_rate) delete[] dash_power_rate;
	if (player_size) delete[] player_size;
	if (kickable_margin) delete[] kickable_margin;
	if (kick_rand) delete[] kick_rand;
	if (extra_stamina) delete[] extra_stamina;
	if (effort_max) delete[] effort_max;
	if (effort_min) delete[] effort_min;
	if (kick_power_rate) delete[] kick_power_rate;
	if (foul_detect_probability) delete[] foul_detect_probability;
	if (catchable_area_l_stretch) delete[] catchable_area_l_stretch;
}

std::string Self::getParameter(const char *parameter) {
	boost::regex parameter_regex("\\(" + parameter + "\\s+([\\w\\-\\.]*)\\)");
	boost::cmatch match;
	if (boost::regex_match(player_params, match, parameter_regex)) {
		return match[1];
	} else {
		return "";
	}
}
