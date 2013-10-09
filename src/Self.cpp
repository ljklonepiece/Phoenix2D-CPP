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
#include <cmath>
#include <algorithm>
#include "Command.h"

int buffer_max_capacity = 8;

bool   Self::positioned = false;
double Self::x          = 0.0;
double Self::y          = 0.0;
double Self::theta      = 0.0;
std::vector<Command*>   Self::last_commands_sent;
std::deque<std::string> Self::view_mode_width_deque;
std::deque<std::string> Self::view_mode_quality_deque;
std::deque<double>      Self::stamina_deque;
std::deque<double>      Self::effort_deque;
std::deque<double>      Self::stamina_capacity_deque;
std::deque<double>      Self::amount_of_speed_deque;
std::deque<double>      Self::direction_of_speed_deque;
std::deque<double>      Self::head_angle_deque;
std::deque<int>         Self::kick_count_deque;
std::deque<int>         Self::dash_count_deque;
std::deque<int>         Self::turn_count_deque;
std::deque<int>         Self::say_count_deque;
std::deque<int>         Self::turn_neck_count_deque;
std::deque<int>         Self::catch_count_deque;
std::deque<int>         Self::move_count_deque;
std::deque<int>         Self::change_view_count_deque;
std::deque<int>         Self::arm_movable_deque;
std::deque<int>         Self::arm_expires_deque;
std::deque<double>      Self::arm_dist_deque;
std::deque<double>      Self::arm_dir_deque;
std::deque<int>         Self::arm_count_deque;
std::deque<std::string> Self::focus_target_deque;
std::deque<int>         Self::focus_count_deque;
std::deque<int>         Self::tackle_expires_deque;
std::deque<int>         Self::tackle_count_deque;
std::deque<std::vector<std::string> > Self::collisions_deque;
std::deque<int>         Self::foul_charged_deque;
std::deque<std::string> Self::foul_card_deque;

double Self::PI         = 3.14159265359;

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
	Self::positioned = false;
}

Self::~Self() {
	if (types_id)                 delete[] types_id;
	if (player_speed_max)         delete[] player_speed_max;
	if (stamina_inc_max)          delete[] stamina_inc_max;
	if (player_decay)             delete[] player_decay;
	if (inertia_moment)           delete[] inertia_moment;
	if (dash_power_rate)          delete[] dash_power_rate;
	if (player_size)              delete[] player_size;
	if (kickable_margin)          delete[] kickable_margin;
	if (kick_rand)                delete[] kick_rand;
	if (extra_stamina)            delete[] extra_stamina;
	if (effort_max)               delete[] effort_max;
	if (effort_min)               delete[] effort_min;
	if (kick_power_rate)          delete[] kick_power_rate;
	if (foul_detect_probability)  delete[] foul_detect_probability;
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
		//view_mode_quality
		Self::VIEW_MODE_QUALITY = match[1];
		if (Self::view_mode_quality_deque.size() == buffer_max_capacity) Self::view_mode_quality_deque.pop_back();
		Self::view_mode_quality_deque.push_front(Self::VIEW_MODE_QUALITY);
		//view_mode_width
		Self::VIEW_MODE_WIDTH = match[2];
		if (Self::view_mode_width_deque.size() == buffer_max_capacity) Self::view_mode_width_deque.pop_back();
		Self::view_mode_width_deque.push_front(Self::VIEW_MODE_WIDTH);
		//stamina
		Self::STAMINA = atof((std::string() + match[3]).c_str());
		if (Self::stamina_deque.size() == buffer_max_capacity) Self::stamina_deque.pop_back();
		Self::stamina_deque.push_front(Self::STAMINA);
		//effort
		Self::EFFORT = atof((std::string() + match[4]).c_str());
		if (Self::effort_deque.size() == buffer_max_capacity) Self::effort_deque.pop_back();
		Self::effort_deque.push_front(Self::EFFORT);
		//stamina_capacity
		Self::STAMINA_CAPACITY = atof((std::string() + match[5]).c_str());
		if (Self::stamina_capacity_deque.size() == buffer_max_capacity) Self::stamina_capacity_deque.pop_back();
		Self::stamina_capacity_deque.push_front(Self::STAMINA_CAPACITY);
		//amount_of_speed
		Self::AMOUNT_OF_SPEED = atof((std::string() + match[6]).c_str());
		if (Self::amount_of_speed_deque.size() == buffer_max_capacity) Self::amount_of_speed_deque.pop_back();
		Self::amount_of_speed_deque.push_front(Self::AMOUNT_OF_SPEED);
		//direction_of_speed
		Self::DIRECTION_OF_SPEED = atof((std::string() + match[7]).c_str());
		if (Self::direction_of_speed_deque.size() == buffer_max_capacity) Self::direction_of_speed_deque.pop_back();
		Self::direction_of_speed_deque.push_front(Self::DIRECTION_OF_SPEED);
		//head_angle
		Self::HEAD_ANGLE = atof((std::string() + match[8]).c_str());
		if (Self::head_angle_deque.size() == buffer_max_capacity) Self::head_angle_deque.pop_back();
		Self::head_angle_deque.push_front(Self::HEAD_ANGLE);
		//kick_count
		Self::KICK_COUNT = atoi((std::string() + match[9]).c_str());
		if (Self::KICK_COUNT > Self::getKickCountAtTime(0)) {
			for (std::vector<Command*>::iterator it = Self::last_commands_sent.begin(); it != Self::last_commands_sent.end(); ++it) {
				if ((*it)->getCommandType() == Command::KICK) {
					(*it)->changeStatusTo(Command::EXECUTED);
					break;
				}
			}
		}
		if (Self::kick_count_deque.size() == buffer_max_capacity) Self::kick_count_deque.pop_back();
		Self::kick_count_deque.push_front(Self::KICK_COUNT);
		//dash_count
		Self::DASH_COUNT = atoi((std::string() + match[10]).c_str());
		if (Self::DASH_COUNT > Self::getDashCountAtTime(0)) {
			for (std::vector<Command*>::iterator it = Self::last_commands_sent.begin(); it != Self::last_commands_sent.end(); ++it) {
				if ((*it)->getCommandType() == Command::DASH) {
					(*it)->changeStatusTo(Command::EXECUTED);
					break;
				}
			}
		}
		if (Self::dash_count_deque.size() == buffer_max_capacity) Self::dash_count_deque.pop_back();
		Self::dash_count_deque.push_front(Self::DASH_COUNT);
		//turn_count
		Self::TURN_COUNT = atoi((std::string() + match[11]).c_str());
		if (Self::TURN_COUNT > Self::getTurnCountAtTime(0)) {
			for (std::vector<Command*>::iterator it = Self::last_commands_sent.begin(); it != Self::last_commands_sent.end(); ++it) {
				if ((*it)->getCommandType() == Command::TURN) {
					(*it)->changeStatusTo(Command::EXECUTED);
					break;
				}
			}
		}
		if (Self::turn_count_deque.size() == buffer_max_capacity) Self::turn_count_deque.pop_back();
		Self::turn_count_deque.push_front(Self::TURN_COUNT);
		//say_count
		Self::SAY_COUNT = atoi((std::string() + match[12]).c_str());
		if (Self::SAY_COUNT > Self::getSayCountAtTime(0)) {
			for (std::vector<Command*>::iterator it = Self::last_commands_sent.begin(); it != Self::last_commands_sent.end(); ++it) {
				if ((*it)->getCommandType() == Command::SAY) {
					(*it)->changeStatusTo(Command::EXECUTED);
					break;
				}
			}
		}
		if (Self::say_count_deque.size() == buffer_max_capacity) Self::say_count_deque.pop_back();
		Self::say_count_deque.push_front(Self::SAY_COUNT);
		//turn_neck_count
		Self::TURN_NECK_COUNT = atoi((std::string() + match[13]).c_str());
		if (Self::TURN_NECK_COUNT > Self::getTurnNeckCountAtTime(0)) {
			for (std::vector<Command*>::iterator it = Self::last_commands_sent.begin(); it != Self::last_commands_sent.end(); ++it) {
				if ((*it)->getCommandType() == Command::TURN_NECK) {
					(*it)->changeStatusTo(Command::EXECUTED);
					break;
				}
			}
		}
		if (Self::turn_neck_count_deque.size() == buffer_max_capacity) Self::turn_neck_count_deque.pop_back();
		Self::turn_neck_count_deque.push_front(Self::TURN_NECK_COUNT);
		//catch_count
		Self::CATCH_COUNT = atoi((std::string() + match[14]).c_str());
		if (Self::CATCH_COUNT > Self::getCatchCountAtTime(0)) {
			for (std::vector<Command*>::iterator it = Self::last_commands_sent.begin(); it != Self::last_commands_sent.end(); ++it) {
				if ((*it)->getCommandType() == Command::CATCH) {
					(*it)->changeStatusTo(Command::EXECUTED);
					break;
				}
			}
		}
		if (Self::catch_count_deque.size() == buffer_max_capacity) Self::catch_count_deque.pop_back();
		Self::catch_count_deque.push_front(Self::CATCH_COUNT);
		//move_count
		Self::MOVE_COUNT = atoi((std::string() + match[15]).c_str());
		if (Self::MOVE_COUNT > Self::getMoveCountAtTime(0)) {
			for (std::vector<Command*>::iterator it = Self::last_commands_sent.begin(); it != Self::last_commands_sent.end(); ++it) {
				if ((*it)->getCommandType() == Command::MOVE) {
					(*it)->changeStatusTo(Command::EXECUTED);
					break;
				}
			}
		}
		if (Self::move_count_deque.size() == buffer_max_capacity) Self::move_count_deque.pop_back();
		Self::move_count_deque.push_front(Self::MOVE_COUNT);
		//change_view_count
		Self::CHANGE_VIEW_COUNT = atoi((std::string() + match[16]).c_str());
		if (Self::CHANGE_VIEW_COUNT > Self::getChangeViewCountAtTime(0)) {
			for (std::vector<Command*>::iterator it = Self::last_commands_sent.begin(); it != Self::last_commands_sent.end(); ++it) {
				if ((*it)->getCommandType() == Command::CHANGE_VIEW) {
					(*it)->changeStatusTo(Command::EXECUTED);
					break;
				}
			}
		}
		if (Self::change_view_count_deque.size() == buffer_max_capacity) Self::change_view_count_deque.pop_back();
		Self::change_view_count_deque.push_front(Self::CHANGE_VIEW_COUNT);
		//arm_movable
		Self::ARM_MOVABLE = atoi((std::string() + match[17]).c_str());
		if (Self::arm_movable_deque.size() == buffer_max_capacity) Self::arm_movable_deque.pop_back();
		Self::arm_movable_deque.push_front(Self::ARM_MOVABLE);
		//arm_expires
		Self::ARM_EXPIRES = atoi((std::string() + match[18]).c_str());
		if (Self::arm_expires_deque.size() == buffer_max_capacity) Self::arm_expires_deque.pop_back();
		Self::arm_expires_deque.push_front(Self::ARM_EXPIRES);
		//arm_dist
		Self::ARM_DIST = atof((std::string() + match[19]).c_str());
		if (Self::arm_dist_deque.size() == buffer_max_capacity) Self::arm_dist_deque.pop_back();
		Self::arm_dist_deque.push_front(Self::ARM_DIST);
		//arm_dir
		Self::ARM_DIR = atof((std::string() + match[20]).c_str());
		if (Self::arm_dir_deque.size() == buffer_max_capacity) Self::arm_dir_deque.pop_back();
		Self::arm_dir_deque.push_front(Self::ARM_DIR);
		//arm_count
		Self::ARM_COUNT = atoi((std::string() + match[21]).c_str());
		if (Self::ARM_COUNT > Self::getArmCountAtTime(0)) {
			for (std::vector<Command*>::iterator it = Self::last_commands_sent.begin(); it != Self::last_commands_sent.end(); ++it) {
				if ((*it)->getCommandType() == Command::POINT) {
					(*it)->changeStatusTo(Command::EXECUTED);
					break;
				}
			}
		}
		if (Self::arm_count_deque.size() == buffer_max_capacity) Self::arm_count_deque.pop_back();
		Self::arm_count_deque.push_front(Self::ARM_COUNT);
		//focus_target
		Self::FOCUS_TARGET = match[22];
		if (Self::focus_target_deque.size() == buffer_max_capacity) Self::focus_target_deque.pop_back();
		Self::focus_target_deque.push_front(Self::FOCUS_TARGET);
		//focus_count
		Self::FOCUS_COUNT = atoi((std::string() + match[23]).c_str());
		if (Self::focus_count_deque.size() == buffer_max_capacity) Self::focus_count_deque.pop_back();
		Self::focus_count_deque.push_front(Self::FOCUS_COUNT);
		//tackle_expires
		Self::TACKLE_EXPIRES = atoi((std::string() + match[24]).c_str());
		if (Self::tackle_expires_deque.size() == buffer_max_capacity) Self::tackle_expires_deque.pop_back();
		Self::tackle_expires_deque.push_front(Self::TACKLE_EXPIRES);
		//tackle_count
		Self::TACKLE_COUNT = atoi((std::string() + match[25]).c_str());
		if (Self::TACKLE_COUNT > Self::getTackleCountAtTime(0)) {
			for (std::vector<Command*>::iterator it = Self::last_commands_sent.begin(); it != Self::last_commands_sent.end(); ++it) {
				if ((*it)->getCommandType() == Command::TACKLE) {
					(*it)->changeStatusTo(Command::EXECUTED);
					break;
				}
			}
		}
		if (Self::tackle_count_deque.size() == buffer_max_capacity) Self::tackle_count_deque.pop_back();
		Self::tackle_count_deque.push_front(Self::TACKLE_COUNT);
		//collisions
		Self::COLLISION.clear();
		std::stringstream ss(std::string() + match[26]);
		std::string token;
		while(std::getline(ss, token, ' ')) {
			Self::COLLISION.push_back(token);
		}
		if (Self::collisions_deque.size() == buffer_max_capacity) Self::collisions_deque.pop_back();
		Self::collisions_deque.push_front(Self::COLLISION);
		//foul_charged
		Self::FOUL_CHARGED = atoi((std::string() + match[27]).c_str());
		if (Self::foul_charged_deque.size() == buffer_max_capacity) Self::foul_charged_deque.pop_back();
		Self::foul_charged_deque.push_front(Self::FOUL_CHARGED);
		//foul_card
		Self::FOUL_CARD = match[28];
		if (Self::foul_card_deque.size() == buffer_max_capacity) Self::foul_card_deque.pop_back();
		Self::foul_card_deque.push_front(Self::FOUL_CARD);
	} else {
		std::cerr << "Self::processSenseBody(string) -> failed to match sense body" << std::endl;
	}
}

void Self::changePlayerType(int type) {
	Self::PLAYER_SPEED_MAX         = player_speed_max[type];
	Self::STAMINA_INC_MAX          = stamina_inc_max[type];
	Self::PLAYER_DECAY             = player_decay[type];
	Self::INERTIA_MOMENT           = inertia_moment[type];
	Self::DASH_POWER_RATE          = dash_power_rate[type];
	Self::PLAYER_SIZE              = player_size[type];
	Self::KICKABLE_MARGIN          = kickable_margin[type];
	Self::KICK_RAND                = kick_rand[type];
	Self::EXTRA_STAMINA            = extra_stamina[type];
	Self::EFFORT_MAX               = effort_max[type];
	Self::EFFORT_MIN               = effort_min[type];
	Self::KICK_POWER_RATE          = kick_power_rate[type];
	Self::FOUL_DETECT_PROBABILITY  = foul_detect_probability[type];
	Self::CATCHABLE_AREA_L_STRETCH = catchable_area_l_stretch[type];
}

void Self::localize(std::vector<Flag> flags) {
	for (std::vector<Command*>::iterator it = Self::last_commands_sent.begin(); it != Self::last_commands_sent.end(); ++it) {
		switch ((*it)->getCommandType()) {
		case Command::MOVE:
			Self::x = (*it)->getMoveX();
			Self::y = (*it)->getMoveY();
			Self::positioned = true;
			break;
		default:
			break;
		}
	}
	if (!Self::positioned) return;
	std::vector<double> xs;
	std::vector<double> ys;
	std::vector<double> thetas;
	for (std::vector<Flag>::iterator it = flags.begin(); it != flags.end() - 1; ++it) {
		double k0 = pow(it->getX(), 2.0) + pow(it->getY(), 2.0) - pow(it->getDistance(), 2.0);
		double k1 = pow((it + 1)->getX(), 2.0) + pow((it + 1)->getY(), 2.0) - pow((it + 1)->getDistance(), 2.0);
		double x0, x1, y0, y1, B, C;
		if (it->getX() == (it + 1)->getX()) {
			double y = (k1 - k0) / (2.0 * ((it + 1)->getY() - it->getY()));
			y0 = y;
			y1 = y;
			B = -2.0 * it->getX();
			C = pow(y, 2.0) - 2.0 * y * it->getY() + k0;
			if (pow(B, 2.0) - 4.0 * C > 0) {
				x0 = (-B + sqrt(pow(B, 2.0) - 4.0 * C)) / 2.0;
				x1 = (-B - sqrt(pow(B, 2.0) - 4.0 * C)) / 2.0;
			} else {
				continue;
			}
		} else if (it->getY() == (it + 1)->getY()) {
			double x = (k1 - k0) / (2.0 * ((it + 1)->getX() - it->getX()));
			x0 = x;
			x1 = x;
			B = -2.0 * it->getY();
			C = pow(x, 2.0) - 2.0 * x * it->getX() + k0;
			if (pow(B, 2.0) - 4.0 * C > 0) {
				y0 = (-B + sqrt(pow(B, 2.0) - 4.0 * C)) / 2.0;
				y1 = (-B - sqrt(pow(B, 2.0) - 4.0 * C)) / 2.0;
			} else {
				continue;
			}
		} else {
			double M = (k1 - k0) / (2.0 * ((it + 1)->getX() - it->getX()));
			double N = (it->getY() - (it + 1)->getY()) / ((it + 1)->getX() - it->getX());
			B = (2.0 * (M * N - N * it->getX() - it->getY())) / (pow(N, 2.0) + 1.0);
			C = (k0 + pow(M, 2.0) - 2.0 * M * it->getX()) / (pow(N, 2.0) + 1.0);
			if (pow(B, 2.0) - 4.0 * C > 0) {
				y0 = (-B + sqrt(pow(B, 2.0) - 4.0 * C)) / 2.0;
				x0 = M + y0 * N;
				y1 = (-B - sqrt(pow(B, 2.0) - 4.0 * C)) / 2.0;
				x1 = M + y1 * N;
			} else {
				continue;
			}
		}
		double d0 = sqrt(pow(x0 - Self::x, 2.0) + pow(y0 - Self::y, 2.0));
		double d1 = sqrt(pow(x1 - Self::x, 2.0) + pow(y1 - Self::y, 2.0));
		double gamma0, gamma1;
		if (d0 < d1) {
			xs.push_back(x0);
			ys.push_back(y0);
			gamma0 = 180 * atan2(it->getY() - y0, it->getX() - x0) / Self::PI - it->getDirection();
			gamma1 = 180 * atan2((it + 1)->getY() - y0, (it + 1)->getX() - x0) / Self::PI - (it + 1)->getDirection();
		} else {
			xs.push_back(x1);
			ys.push_back(y1);
			gamma0 = 180 * atan2(it->getY() - y1, it->getX() - x1) / Self::PI - it->getDirection();
			gamma1 = 180 * atan2((it + 1)->getY() - y1, (it + 1)->getX() - x1) / Self::PI - (it + 1)->getDirection();
		}
		if (gamma0 >= 180.0)      gamma0 -= 360.0;
		else if (gamma0 < -180.0) gamma0 += 360.0;
		if (gamma1 >= 180.0)      gamma1 -= 360.0;
		else if (gamma1 < -180.0) gamma1 += 360.0;
		double midpoint0 = (gamma0 + gamma1) / 2.0;
		double midpoint1 = midpoint0 + 180.0;
		if (midpoint1 >= 180.0) midpoint1 -= 360.0;
		double arc0 = abs(gamma0 - midpoint0);
		if (arc0 > 180.0) arc0 -= 360.0;
		double arc1 = abs(gamma0 - midpoint1);
		if (arc1 > 180.0) arc1 -= 360.0;
		if (arc0 < arc1) thetas.push_back(midpoint0);
		else thetas.push_back(midpoint1);
	}
	if (xs.size() > 0) {
		double accum_xs = 0.0;
		int i = xs.size();
		double total_weight = 0.0;
		for (std::vector<double>::iterator accum_it = xs.begin(); accum_it != xs.end(); ++accum_it) {
			double weight = sqrt(i--);
			accum_xs += *accum_it * weight;
			total_weight += weight;
		}
		Self::x = accum_xs / total_weight;
	}
	if (ys.size() > 0) {
		double accum_ys = 0.0;
		int i = ys.size();
		double total_weight = 0.0;
		for (std::vector<double>::iterator accum_it = ys.begin(); accum_it != ys.end(); ++accum_it) {
			double weight = sqrt(i--);
			accum_ys += *accum_it * weight;
			total_weight += weight;
		}
		Self::y = accum_ys / total_weight;
	}
	if (thetas.size() > 0) {
		std::sort(thetas.begin(), thetas.end());
		Self::theta = thetas[thetas.size() / 2];
	}
}

void Self::localize() {
	for (std::vector<Command*>::iterator it = Self::last_commands_sent.begin(); it != Self::last_commands_sent.end(); ++it) {
		switch ((*it)->getCommandType()) {
		case Command::MOVE:
			Self::x = (*it)->getMoveX();
			Self::y = (*it)->getMoveY();
			Self::positioned = true;
			break;
		case Command::TURN:
			Self::theta += (*it)->getTurnMoment() / (1.0 + Self::getAmountOfSpeedAtTime(1) * Self::INERTIA_MOMENT);
			break;
		case Command::DASH:
			break;
		default:
			break;
		}
	}
}

Position Self::getPosition() {
	return Position(Self::x, Self::y, Self::theta);
}

Vector2D Self::getVelocity() {
	return Vector2D::getVector2DWithMagnitudeAndDirection(Self::AMOUNT_OF_SPEED, Self::DIRECTION_OF_SPEED);
}

void Self::setLastCommandsSet(std::vector<Command*> last_commands_sent) {
	Self::last_commands_sent = last_commands_sent;
}

std::string Self::getViewModeWidthAtTime(int time) {
	return (time < Self::view_mode_width_deque.size()) ? Self::view_mode_width_deque.at(time) : "";
}

std::string Self::getViewModeQualityAtTime(int time) {
	return (time < Self::view_mode_quality_deque.size()) ? Self::view_mode_quality_deque.at(time) : "";
}

double Self::getStaminaAtTime(int time) {
	return (time < Self::stamina_deque.size()) ? Self::stamina_deque.at(time) : 0.0;
}

double Self::getEffortAtTime(int time) {
	return (time < Self::effort_deque.size()) ? Self::effort_deque.at(time) : 0.0;
}

double Self::getStaminaCapacityAtTime(int time) {
	return (time < Self::stamina_capacity_deque.size()) ? Self::stamina_capacity_deque.at(time) : 0.0;
}

double Self::getAmountOfSpeedAtTime(int time) {
	return (time < Self::amount_of_speed_deque.size()) ? Self::amount_of_speed_deque.at(time) : 0.0;
}

double Self::getDirectionOfSpeedAtTime(int time) {
	return (time < Self::direction_of_speed_deque.size()) ? Self::direction_of_speed_deque.at(time) : 0.0;
}

int Self::getKickCountAtTime(int time) {
	return (time < Self::kick_count_deque.size()) ? Self::kick_count_deque.at(time) : 0;
}

int Self::getDashCountAtTime(int time) {
	return (time < Self::dash_count_deque.size()) ? Self::dash_count_deque.at(time) : 0;
}

int Self::getTurnCountAtTime(int time) {
	return (time < Self::turn_count_deque.size()) ? Self::turn_count_deque.at(time) : 0;
}

int Self::getSayCountAtTime(int time) {
	return (time < Self::say_count_deque.size()) ? Self::say_count_deque.at(time) : 0;
}

int Self::getTurnNeckCountAtTime(int time) {
	return (time < Self::turn_neck_count_deque.size()) ? Self::turn_neck_count_deque.at(time) : 0;
}

int Self::getCatchCountAtTime(int time) {
	return (time < Self::catch_count_deque.size()) ? Self::catch_count_deque.at(time) : 0;
}

int Self::getMoveCountAtTime(int time) {
	return (time < Self::move_count_deque.size()) ? Self::move_count_deque.at(time) : 0;
}

int Self::getChangeViewCountAtTime(int time) {
	return (time < Self::change_view_count_deque.size()) ? Self::change_view_count_deque.at(time) : 0;
}

int Self::getArmMovableAtTime(int time) {
	return (time < Self::arm_movable_deque.size()) ? Self::arm_movable_deque.at(time) : 0;
}

int Self::getArmExpiresAtTime(int time) {
	return (time < Self::arm_expires_deque.size()) ? Self::arm_expires_deque.at(time) : 0;
}

double Self::getArmDistAtTime(int time) {
	return (time < Self::arm_dist_deque.size()) ? Self::arm_dist_deque.at(time) : 0.0;
}

double Self::getArmDirAtTime(int time) {
	return (time < Self::arm_dir_deque.size()) ? Self::arm_dir_deque.at(time) : 0.0;
}

int Self::getArmCountAtTime(int time) {
	return (time < Self::arm_count_deque.size()) ? Self::arm_count_deque.at(time) : 0;
}

std::string Self::getFocusTargetAtTime(int time) {
	return (time < Self::focus_target_deque.size()) ? Self::focus_target_deque.at(time) : "";
}

int Self::getFocusCountAtTime(int time) {
	return (time < Self::focus_count_deque.size()) ? Self::focus_count_deque.at(time) : 0;
}

int Self::getTackleExpiresAtTime(int time) {
	return (time < Self::tackle_expires_deque.size()) ? Self::tackle_expires_deque.at(time) : 0;
}

int Self::getTackleCountAtTime(int time) {
	return (time < Self::tackle_count_deque.size()) ? Self::tackle_count_deque.at(time) : 0;
}

std::vector<std::string> Self::getCollisionsAtTime(int time) {
	std::vector<std::string> empty_vector;
	return (time < Self::collisions_deque.size()) ? Self::collisions_deque.at(time) : empty_vector;
}

int Self::getFoulChargedAtTime(int time) {
	return (time < Self::foul_charged_deque.size()) ? Self::foul_charged_deque.at(time) : 0;
}

std::string Self::getFoulCardAtTime(int time) {
	return (time < Self::foul_card_deque.size()) ? Self::foul_card_deque.at(time) : "";
}
