/**********|**********|**********|
 Program:Constants.h 
 Course: OOPDS
 Trimester: 2510
 Name: Abikirthikka
 ID: 242UC24420
 Lecture Section: TC1L
 Tutorial Section: TT2L
 Email: ABIKIRTHIKKA.TAMIL.ARASAN@student.mmu.edu.my
 Phone: 014-9350432
 **********|**********|**********/
 
 #ifndef CONSTANTS_H
#define CONSTANTS_H

// Display constants
const char EMPTY_SPACE = '.';
const char BORDER = '#';
const char HIDDEN_SYMBOL = '?';
const char ROBOT_SYMBOL = 'R';
const char WALL_SYMBOL = 'W';

// Simulation constants
const double FIRE_HIT_PROBABILITY = 0.7;
const int INITIAL_SHELLS = 10;
const int MAX_LIVES = 3;
const int MAX_UPGRADES = 3;
const int MAX_TURNS = 300;

// Direction constants
enum Direction {
    UP, DOWN, LEFT, RIGHT,
    UP_LEFT, UP_RIGHT,
    DOWN_LEFT, DOWN_RIGHT,
    NONE
};

// Robot types
enum RobotType {
    GENERIC_ROBOT,
    JUMP_BOT,
    LONG_SHOT_BOT,
    SEMI_AUTO_BOT,
    THIRTY_SHOT_BOT,
    SCOUT_BOT,
    TRACK_BOT,
    HIDE_BOT,
};
