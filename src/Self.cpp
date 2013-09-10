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
#include <cstdlib>
#include <sstream>

double Self::x     = 0.0;
double Self::y     = 0.0;
double Self::theta = 0.0;

std::string Self::TEAM_NAME                            = "Phoenix2D";
int         Self::UNIFORM_NUMBER                       = 1;
std::string Self::SIDE                                 = "l";
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

Self::Self(std::string player_params, std::string team_name, int unum, std::string side) {
	this->player_params = player_params;
	Self::TEAM_NAME = team_name;
	Self::UNIFORM_NUMBER = unum;
	Self::SIDE = side;
	Self::ALLOW_MULT_DEFAULT_TYPE              = atoi((getParameter("allow_mult_default_type")).c_str());
	Self::CATCHABLE_AREA_L_STRECH_MAX          = atof((getParameter("catchable_area_l_stretch_max")).c_str());
	Self::CATCHABLE_AREA_L_STRECH_MIN          = atof((getParameter("catchable_area_l_stretch_min")).c_str());
	Self::DASH_POWER_RATE_DELTA_MAX            = atof((getParameter("dash_power_rate_delta_max")).c_str());
	Self::DASH_POWER_RATE_DELTA_MIN            = atof((getParameter("dash_power_rate_delta_min")).c_str());
	Self::EFFORT_MAX_DELTA_FACTOR              = atof((getParameter("effort_max_delta_factor")).c_str());
	Self::EFFORT_MIN_DELTA_FACTOR              = atof((getParameter("effort_min_delta_factor")).c_str());
	Self::EXTRA_STAMINA_DELTA_MAX              = atof((getParameter("extra_stamina_delta_max")).c_str());
	Self::EXTRA_STAMINA_DELTA_MIN              = atof((getParameter("extra_stamina_delta_min")).c_str());
	Self::FOUL_DETECT_PROBABILITY_DELTA_FACTOR = atof((getParameter("foul_detect_probability_delta_factor")).c_str());
	Self::INERTIA_MOMENT_DELTA_FACTOR          = atof((getParameter("inertia_moment_delta_factor")).c_str());
	Self::KICK_POWER_RATE_DELTA_MAX            = atof((getParameter("kick_power_rate_delta_max")).c_str());
	Self::KICK_POWER_RATE_DELTA_MIN            = atof((getParameter("kick_power_rate_delta_min")).c_str());
	Self::KICK_RAND_DELTA_FACTOR               = atof((getParameter("kick_rand_delta_factor")).c_str());
	Self::KICKABLE_MARGIN_DELTA_MAX            = atof((getParameter("kickable_margin_delta_max")).c_str());
	Self::KICKABLE_MARGIN_DELTA_MIN            = atof((getParameter("kickable_margin_delta_min")).c_str());
	Self::NEW_DASH_POWER_RATE_DELTA_MAX        = atof((getParameter("new_dash_power_rate_delta_max")).c_str());
	Self::NEW_DASH_POWER_RATE_DELTA_MIN        = atof((getParameter("new_dash_power_rate_delta_min")).c_str());
	Self::NEW_STAMINA_INC_MAX_DELTA_FACTOR     = atof((getParameter("new_stamina_inc_max_delta_factor")).c_str());
	Self::PLAYER_DECAY_DELTA_MAX               = atof((getParameter("player_decay_delta_max")).c_str());
	Self::PLAYER_DECAY_DELTA_MIN               = atof((getParameter("player_decay_delta_min")).c_str());
	Self::PLAYER_SIZE_DELTA_FACTOR             = atof((getParameter("player_size_delta_factor")).c_str());
	Self::PLAYER_SPEED_MAX_DELTA_MAX           = atof((getParameter("player_speed_max_delta_max")).c_str());
	Self::PLAYER_SPEED_MAX_DELTA_MIN           = atof((getParameter("player_speed_max_delta_min")).c_str());
	Self::PLAYER_TYPES                         = atoi((getParameter("player_types")).c_str());
	Self::PT_MAX                               = atoi((getParameter("pt_max")).c_str());
	Self::RANDOM_SEED                          = atoi((getParameter("random_seed")).c_str());
	Self::STAMINA_INC_MAX_DELTA_FACTOR         = atof((getParameter("stamina_inc_max_delta_factor")).c_str());
	Self::SUBS_MAX                             = atoi((getParameter("subs_max")).c_str());
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
	sense_body = boost::regex(std::string() + "^\\(sense_body\\s+\\d+\\s+" +
					"\\(view_mode\\s+(\\w+)\\s+(\\w+)\\)\\s*" + //group 1 group 2
					"\\(stamina\\s+([\\d\\.\\-e]+)\\s+([\\d\\.\\-e]+)\\s+([\\d\\.\\-e]+)\\)\\s*" + //\\-\\d+|\\d+\\.\\d+ //group 3 group 4 group 5
					"\\(speed\\s+([\\d\\.\\-e]+)\\s+([\\d\\.\\-e]+)\\)\\s*" + //group 6 group 7
					"\\(head_angle\\s+([\\d\\.\\-e]+)\\)\\s*" + //group 8
					"\\(kick\\s+(\\d+)\\)\\s*" + //group 9
					"\\(dash\\s+(\\d+)\\)\\s*" + //group 10
					"\\(turn\\s+(\\d+)\\)\\s*" + //group 11
					"\\(say\\s+(\\d+)\\)\\s*" + //group 12
					"\\(turn_neck\\s+(\\d+)\\)\\s*" + //group 13
					"\\(catch\\s+(\\d+)\\)\\s*" + //group 14
					"\\(move\\s+(\\d+)\\)\\s*" + //group 15
					"\\(change_view\\s+(\\d+)\\)\\s*" + //group 16
					"\\(arm\\s+" +
						"\\(movable\\s+(\\d+)\\)\\s*" + //group 17
						"\\(expires\\s+(\\d+)\\)\\s*" + //group 18
						"\\(target\\s+([\\d\\.\\-e]+)\\s+([\\d\\.\\-e]+)\\)\\s*" + //group 19 20
						"\\(count\\s+(\\d+)\\)\\s*" + //group 21
					"\\)\\s*" +
					"\\(focus\\s+" +
						"\\(target\\s+(none|[lr]\\s+\\d+)\\)\\s*" + //group 22
						"\\(count\\s+(\\d+)\\)\\s*" + //group 23
					"\\)\\s*" +
					"\\(tackle\\s+" +
	   					"\\(expires\\s+(\\d+)\\)\\s*" + //group 24
	   					"\\(count\\s+(\\d+)\\)\\s*" + //group 25
	   				"\\)\\s*" +
	   				"\\(collision\\s+(none|\\(ball\\)|\\(player\\)|\\(post\\)|\\s)+\\)\\s*" + //group 26
	   				"\\(foul\\s+" +
	   					"\\(charged\\s+(\\d+)\\)\\s*" + //group 27
	   					"\\(card\\s+(none|yellow|red)\\)\\s*" + //group 28
	   				"\\)\\s*" +
			"\\)$");
	Flag::initializeField();
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

void Self::addPlayerType(std::string player_type) {
	int id = atoi((getParameter(player_type, "id")).c_str());
	types_id[id]                 = id;
	player_speed_max[id]         = atof((getParameter(player_type, "player_speed_max")).c_str());
	stamina_inc_max[id]          = atof((getParameter(player_type, "stamina_inc_max")).c_str());
	player_decay[id]             = atof((getParameter(player_type, "player_decay")).c_str());
	inertia_moment[id]           = atof((getParameter(player_type, "inertia_moment")).c_str());
	dash_power_rate[id]          = atof((getParameter(player_type, "dash_power_rate")).c_str());
	player_size[id]              = atof((getParameter(player_type, "player_size")).c_str());
	kickable_margin[id]          = atof((getParameter(player_type, "player_size")).c_str());
	kick_rand[id]                = atof((getParameter(player_type, "kick_rand")).c_str());
	extra_stamina[id]            = atof((getParameter(player_type, "extra_stamina")).c_str());
	effort_max[id]               = atof((getParameter(player_type, "effort_max")).c_str());
	effort_min[id]               = atof((getParameter(player_type, "effort_min")).c_str());
	kick_power_rate[id]          = atof((getParameter(player_type, "kick_power_rate")).c_str());
	foul_detect_probability[id]  = atof((getParameter(player_type, "foul_detect_probability")).c_str());
	catchable_area_l_stretch[id] = atof((getParameter(player_type, "catchable_area_l_stretch")).c_str());
}

std::string Self::getParameter(std::string player_type, std::string parameter) {
	boost::regex parameter_regex("\\(" + parameter + "\\s+([\\w\\-\\.]+)\\)");
	boost::cmatch match;
	if (boost::regex_search(player_type.c_str(), match, parameter_regex)) {
		return std::string() + match[1];
	} else {
		std::cerr << "Self::getParameter(string, string) -> search failed miserably for parameter " << parameter << std::endl;
		return "";
	}
}

std::string Self::getParameter(std::string parameter) {
	boost::regex parameter_regex("\\(" + parameter + "\\s+([\\w\\-\\.]+)\\)");
	boost::cmatch match;
	if (boost::regex_search(player_params.c_str(), match, parameter_regex)) {
		return std::string() + match[1];
	} else {
		std::cerr << "Self::getParameter(string) -> search failed miserably for parameter " << parameter << std::endl;
		return "";
	}
}

void Self::processSenseBody(std::string sense_body) {
	boost::cmatch match;
	if (boost::regex_match(sense_body.c_str(), match, this->sense_body)) {
		Self::VIEW_MODE_QUALITY = match[1];
		Self::VIEW_MODE_WIDTH = match[2];
		Self::STAMINA = atof((std::string() + match[3]).c_str());
		Self::EFFORT = atof((std::string() + match[4]).c_str());
		Self::STAMINA_CAPACITY = atof((std::string() + match[5]).c_str());
		Self::AMOUNT_OF_SPEED = atof((std::string() + match[6]).c_str());
		Self::DIRECTION_OF_SPEED = atof((std::string() + match[7]).c_str());
		Self::HEAD_ANGLE = atof((std::string() + match[8]).c_str());
		Self::KICK_COUNT = atoi((std::string() + match[9]).c_str());
		Self::DASH_COUNT = atoi((std::string() + match[10]).c_str());
		Self::TURN_COUNT = atoi((std::string() + match[11]).c_str());
		Self::SAY_COUNT = atoi((std::string() + match[12]).c_str());
		Self::TURN_NECK_COUNT = atoi((std::string() + match[13]).c_str());
		Self::CATCH_COUNT = atoi((std::string() + match[14]).c_str());
		Self::MOVE_COUNT = atoi((std::string() + match[15]).c_str());
		Self::CHANGE_VIEW_COUNT = atoi((std::string() + match[16]).c_str());
		Self::ARM_MOVABLE = atoi((std::string() + match[17]).c_str());
		Self::ARM_EXPIRES = atoi((std::string() + match[18]).c_str());
		Self::ARM_DIST = atof((std::string() + match[19]).c_str());
		Self::ARM_DIR = atof((std::string() + match[20]).c_str());
		Self::ARM_COUNT = atoi((std::string() + match[21]).c_str());
		Self::FOCUS_TARGET = match[22];
		Self::FOCUS_COUNT = atoi((std::string() + match[23]).c_str());
		Self::TACKLE_EXPIRES = atoi((std::string() + match[24]).c_str());
		Self::TACKLE_COUNT = atoi((std::string() + match[25]).c_str());
		Self::COLLISION.clear();
		std::stringstream ss(std::string() + match[26]);
		std::string token;
		while(std::getline(ss, token, ' ')) {
			Self::COLLISION.push_back(token);
		}
		Self::FOUL_CHARGED = atoi((std::string() + match[27]).c_str());
		Self::FOUL_CARD = match[28];
	} else {
		std::cerr << "Self::processSenseBody(string) -> failed to match sense body" << std::endl;
	}
}

void Self::changePlayerType(int type) {
	Self::PLAYER_SPEED_MAX = player_speed_max[type];
	Self::STAMINA_INC_MAX = stamina_inc_max[type];
	Self::PLAYER_DECAY = player_decay[type];
	Self::INERTIA_MOMENT = inertia_moment[type];
	Self::DASH_POWER_RATE = dash_power_rate[type];
	Self::PLAYER_SIZE = player_size[type];
	Self::KICKABLE_MARGIN = kickable_margin[type];
	Self::KICK_RAND = kick_rand[type];
	Self::EXTRA_STAMINA = extra_stamina[type];
	Self::EFFORT_MAX = effort_max[type];
	Self::EFFORT_MIN = effort_min[type];
	Self::KICK_POWER_RATE = kick_power_rate[type];
	Self::FOUL_DETECT_PROBABILITY = foul_detect_probability[type];
	Self::CATCHABLE_AREA_L_STRETCH = catchable_area_l_stretch[type];
}

void Self::localize(std::vector<Flag> flags) {

}

void Self::localize() {

}
