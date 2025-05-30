/**********|**********|**********|
 Program: Utilities.h 
 Course: OOPDS
 Trimester: 2510
 Name: Abikirthikka
 ID: 242UC24420
 Lecture Section: TC1L
 Tutorial Section: TT2L
 Email: ABIKIRTHIKKA.TAMIL.ARASAN@student.mmu.edu.my
 Phone: 014-9350432
 **********|**********|**********/
#ifndef UTILITIES_H
#define UTILITIES_H

#include "Constants.h"
#include <cstdlib>
#include <ctime>
#include <vector>
#include <algorithm>

class Utilities {
public:
    // Initialize random seed
    static void initRandom() {
        srand(static_cast<unsigned>(time(nullptr)));
    }

    // Generate random number between min and max (inclusive)
    static int randomInt(int min, int max) {
        return min + (rand() % (max - min + 1));
    }

    // Calculate distance between two positions
    static int calculateDistance(const Position& pos1, const Position& pos2) {
        return abs(pos1.robotPositionX - pos2.robotPositionX) + 
               abs(pos1.robotPositionY - pos2.robotPositionY);
    }

    // Check if position is valid on battlefield
    static bool isValidPosition(const Position& pos, int width, int height) {
        return (pos.robotPositionX >= 0 && pos.robotPositionX < width &&
                pos.robotPositionY >= 0 && pos.robotPositionY < height);
    }

    // Convert direction enum to string
    static string directionToString(Direction dir) {
        switch (dir) {
            case UP: return "Up";
            case DOWN: return "Down";
            case LEFT: return "Left";
            case RIGHT: return "Right";
            case UP_LEFT: return "Up-Left";
            case UP_RIGHT: return "Up-Right";
            case DOWN_LEFT: return "Down-Left";
            case DOWN_RIGHT: return "Down-Right";
            case NONE: return "None";
            default: return "Unknown";
        }
    }

    // Convert robot type to string
    static string robotTypeToString(RobotType type) {
        switch (type) {
            case GENERIC_ROBOT: return "GenericRobot";
            case FIRE_ROBOT: return "FireRobot";
            case RECON_ROBOT: return "ReconRobot";
            case FAST_ROBOT: return "FastRobot";
            case JUMP_BOT: return "JumpBot";
            case LONG_SHOT_BOT: return "LongShotBot";
            case SEMI_AUTO_BOT: return "SemiAutoBot";
            case THIRTY_SHOT_BOT: return "ThirtyShotBot";
            case SCOUT_BOT: return "ScoutBot";
            case TRACK_BOT: return "TrackBot";
            case HIDE_BOT: return "HideBot";
            default: return "Unknown";
        }
    }
};

#endif // UTILITIES_H
