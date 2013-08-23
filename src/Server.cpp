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

#include "Server.h"
#include <boost/regex.hpp>

double      Server::AUDIO_CUT_DIST                 = 50.0;
int         Server::AUTO_MODE                      = 0;
double      Server::BACK_DASH_RATE                 = 0.6;
int         Server::BACK_PASSES                    = 1;
double      Server::BALL_ACCEL_MAX                 = 2.7;
double      Server::BALL_DECAY                     = 0.94;
double      Server::BALL_RAND                      = 0.05;
double      Server::BALL_SIZE                      = 0.085;
double      Server::BALL_SPEED_MAX                 = 3.0;
double      Server::BALL_STUCK_AREA                = 3.0;
double      Server::BALL_WEIGHT                    = 0.2;
int         Server::CATCH_BAN_CYCLE                = 5;
double      Server::CATCH_PROBABILITY              = 1.0;
double      Server::CATCHABLE_AREA_L               = 1.2;
double      Server::CATCHABLE_AREA_W               = 1.0;
double      Server::CKICK_MARGIN                   = 1.0;
int         Server::CLANG_ADVICE_WIN               = 1;
int         Server::CLANG_DEFINE_WIN               = 1;
int         Server::CLANG_DEL_WIN                  = 1;
int         Server::CLANG_INFO_WIN                 = 1;
int         Server::CLANG_MESS_DELAY               = 50;
int         Server::CLANG_MESS_PER_CYCLE           = 1;
int         Server::CLANG_META_WIN                 = 1;
int         Server::CLANG_RULE_WIN                 = 1;
int         Server::CLANG_WIN_SIZE                 = 300;
int         Server::COACH                          = 0;
int         Server::COACH_PORT                     = 6001;
int         Server::COACH_W_REFEREE                = 0;
int         Server::CONNECT_WAIT                   = 300;
double      Server::CONTROL_RADIUS                 = 2.0;
double      Server::DASH_ANGLE_STEP                = 45.0;
double      Server::DASH_POWER_RATE                = 0.006;
int         Server::DROP_BALL_TIME                 = 100;
double      Server::EFFORT_DEC                     = 0.005;
double      Server::EFFORT_DEC_THR                 = 0.3;
double      Server::EFFORT_INC                     = 0.01;
double      Server::EFFORT_INC_THR                 = 0.6;
double      Server::EFFORT_INIT                    = 1.0;
double      Server::EFFORT_MIN                     = 0.6;
int         Server::EXTRA_HALF_TIME                = 100;
int         Server::EXTRA_STAMINA                  = 50;
int         Server::FORBID_KICK_OFF_OFFSIDE        = 1;
int         Server::FOUL_CYCLES                    = 5;
double      Server::FOUL_DETECT_PROBABILITY        = 0.5;
int         Server::FOUL_EXPONENT                  = 10;
int         Server::FREE_KICK_FAULTS               = 1;
int         Server::FREEFORM_SEND_PERIOD           = 20;
int         Server::FREEFORM_WAIT_PERIOD           = 600;
int         Server::FULLSTATE_L                    = 0;
int         Server::FULLSTATE_R                    = 0;
int         Server::GAME_LOG_COMPRESSION           = 0;
int         Server::GAME_LOG_DATED                 = 1;
std::string Server::GAME_LOG_DIR                   = "./";
int         Server::GAME_LOG_FIXED                 = 0;
std::string Server::GAME_LOG_FIXED_NAME            = "rcssserver";
int         Server::GAME_LOG_VERSION               = 5;
int         Server::GAME_LOGGING                   = 1;
int         Server::GAME_OVER_WAIT                 = 100;
double      Server::GOAL_WIDTH                     = 14.02;
int         Server::GOALIE_MAX_MOVES               = 2;
int         Server::GOLDEN_GOAL                    = 0;
int         Server::HALF_TIME                      = 300;
int         Server::HEAR_DECAY                     = 1;
int         Server::HEAR_INC                       = 1;
int         Server::HEAR_MAX                       = 1;
int         Server::INERTIA_MOMENT                 = 5;
int         Server::KEEPAWAY                       = 1;
int         Server::KEEPAWAY_LENGTH                = 20;
int         Server::KEEPAWAY_LOG_DATED             = 1;
std::string Server::KEEPAWAY_LOG_DIR               = "./";
int         Server::KEEPAWAY_LOG_FIXED             = 0;
std::string Server::KEEPAWAY_LOG_FIXED_NAME        = "rcssserver";
int         Server::KEEPAWAY_LOGGING               = 1;
int         Server::KEEPAWAY_START                 = -1;
int         Server::KEEPAWAY_WIDTH                 = 20;
int         Server::KICK_OFF_WAIT                  = 100;
double      Server::KICK_POWER_RATE                = 0.027;
double      Server::KICK_RAND                      = 0.1;
double      Server::KICK_RAND_FACTOR_L             = 1.0;
double      Server::KICK_RAND_FACTOR_R             = 1.0;
double      Server::KICKABLE_MARGIN                = 0.7;
std::string Server::LANDMARK_FILE                  = "~/.rcssserver-landmark.xml";
std::string Server::LOG_DATE_FORMAT                = "%Y%m%d%H%M-";
int         Server::LOG_TIMES                      = 0;
double      Server::MAX_BACK_TACKLE_POWER          = 0.0;
double      Server::MAX_DASH_ANGLE                 = 180.0;
double      Server::MAX_DASH_POWER                 = 100.0;
int         Server::MAX_GOAL_KICKS                 = 3;
double      Server::MAX_TACKLE_POWER               = 100.0;
double      Server::MAXMOMENT                      = 180.0;
double      Server::MAXNECKANG                     = 90.0;
double      Server::MAXNECKMOMENT                  = 180.0;
double      Server::MAXPOWER                       = 100.0;
double      Server::MIN_DASH_ANGLE                 = -180.0;
double      Server::MIN_DASH_POWER                 = -100.0;
double      Server::MINMOMENT                      = -180.0;
double      Server::MINNECKANG                     = -90.0;
double      Server::MINNECKMOMENT                  = -180.0;
double      Server::MINPOWER                       = -100.0;
int         Server::NR_EXTRA_HALFS                 = 2;
int         Server::NR_NORMAL_HALFS                = 2;
double      Server::OFFSIDE_ACTIVE_AREA_SIZE       = 2.5;
double      Server::OFFSIDE_KICK_MARGIN            = 9.15;
int         Server::OLCOACH_PORT                   = 6002;
int         Server::OLD_COACH_HEAR                 = 0;
int         Server::PEN_ALLOW_MULT_KICKS           = 1;
int         Server::PEN_BEFORE_SETUP_WAIT          = 10;
int         Server::PEN_COACH_MOVES_PLAYERS        = 1;
double      Server::PEN_DIST_X                     = 42.5;
int         Server::PEN_MAX_EXTRA_KICKS            = 5;
double      Server::PEN_MAX_GOALIE_DIST_X          = 14.0;
int         Server::PEN_NR_KICKS                   = 5;
double      Server::PEN_RANDOM_WINNER              = 0;
int         Server::PEN_READY_WAIT                 = 10;
int         Server::PEN_SETUP_WAIT                 = 70;
int         Server::PEN_TAKEN_WAIT                 = 150;
int         Server::PENALTY_SHOOT_OUTS             = 1;
double      Server::PLAYER_ACCEL_MAX               = 1.0;
double      Server::PLAYER_DECAY                   = 0.4;
double      Server::PLAYER_RAND                    = 0.1;
double      Server::PLAYER_SIZE                    = 0.3;
double      Server::PLAYER_SPEED_MAX               = 1.05;
double      Server::PLAYER_SPEED_MAX_MIN           = 0.75;
double      Server::PLAYER_WEIGHT                  = 60.0;
int         Server::POINT_TO_BAN                   = 5;
int         Server::POINT_TO_DURATION              = 20;
int         Server::PORT                           = 6000;
double      Server::PRAND_FACTOR_L                 = 1.0;
double      Server::PRAND_FACTOR_R                 = 1.0;
int         Server::PROFILE                        = 0;
int         Server::PROPER_GOAL_KICKS              = 0;
double      Server::QUANTIZE_STEP                  = 0.1;
double      Server::QUANTIZE_STEP_L                = 0.01;
int         Server::RECORD_MESSAGES                = 0;
double      Server::RECOVER_DEC                    = 0.002;
double      Server::RECOVER_DEC_THR                = 0.3;
double      Server::RECOVER_INIT                   = 1.0;
double      Server::RECOVER_MIN                    = 0.5;
int         Server::RECV_STEP                      = 10;
double      Server::RED_CARD_PROBABILITY           = 0.0;
int         Server::SAY_COACH_CNT_MAX              = 128;
int         Server::SAY_COACH_MSG_SIZE             = 128;
int         Server::SAY_MSG_SIZE                   = 10; //DAMN =S
int         Server::SEND_COMMS                     = 0;
int         Server::SEND_STEP                      = 150;
int         Server::SEND_VI_STEP                   = 100;
int         Server::SENSE_BODY_STEP                = 100;
double      Server::SIDE_DASH_RATE                 = 0.4;
int         Server::SIMULATOR_STEP                 = 100;
double      Server::SLOW_DOWN_FACTOR               = 1.0;
double      Server::SLOWNESS_ON_TOP_FOR_LEFT_TEAM  = 1.0;
double      Server::SLOWNESS_ON_TOP_FOR_RIGHT_TEAM = 1.0;
int         Server::STAMINA_CAPACITY               = 130600;
int         Server::STAMINA_INC_MAX                = 45;
int         Server::STAMINA_MAX                    = 8000;
int         Server::START_GOAL_L                   = 0;
int         Server::START_GOAL_R                   = 0;
double      Server::STOPPED_BALL_VEL               = 0.01;
int         Server::SYNCH_MICRO_SLEEP              = 1;
int         Server::SYNCH_MODE                     = 0;
int         Server::SYNCH_OFFSET                   = 60;
int         Server::SYNCH_SEE_OFFSET               = 0;
double      Server::TACKLE_BACK_DIST               = 0.0;
int         Server::TACKLE_CYCLES                  = 10;
double      Server::TACKLE_DIST                    = 2.0;
int         Server::TACKLE_EXPONENT                = 6;
double      Server::TACKLE_POWER_RATE              = 0.027;
double      Server::TACKLE_RAND_FACTOR             = 2.0;
double      Server::TACKLE_WIDTH                   = 1.25;
double      Server::TEAM_ACTUATOR_NOISE            = 0.0;
std::string Server::TEAM_L_START                   = "";
std::string Server::TEAM_R_START                   = "";
int         Server::TEXT_LOG_COMPRESSION           = 0;
int         Server::TEXT_LOG_DATED                 = 1;
std::string Server::TEXT_LOG_DIR                   = "./";
int         Server::TEXT_LOG_FIXED                 = 0;
std::string Server::TEXT_LOG_FIXED_NAME            = "rcssserver";
int         Server::TEXT_LOGGING                   = 1;
int         Server::USE_OFFSIDE                    = 1;
int         Server::VERBOSE                        = 0;
double      Server::VISIBLE_ANGLE                  = 90.0;
double      Server::VISIBLE_DISTANCE               = 3.0;
double      Server::WIND_ANG                       = 0.0;
double      Server::WIND_DIR                       = 0.0;
double      Server::WIND_FORCE                     = 0.0;
double      Server::WIND_NONE                      = 0.0;
double      Server::WIND_RAND                      = 0.0;
double      Server::WIND_RANDOM                    = 0.0;

Server::Server(const char *server_params) {
	this->server_params = std::string(server_params);
}

Server::~Server() {

}

std::string Server::getParameter(std::string parameter) {
	boost::regex parameter_regex("\\(" + parameter + "\\s+([\\w\\-\\.~%]*)\\)");
	boost::cmatch match;
	if (boost::regex_match(server_params.c_str(), match, parameter_regex)) {
		return std::string() + match[1];
	} else {
		return "";
	}
}
