#ifndef THIRTYSHOTBOT_H
#define THIRTYSHOTBOT_H

#include "GenericRobot.h"

class ThirtyShotBot : public GenericRobot {
public:
    ThirtyShotBot(const string& name, int startX, int startY, int w, int h)
        : GenericRobot(name, startX, startY, w, h) {
        chooseShootingUpgrade("ThirtyShotBot");
        shells = 30; // Override to 30 shells
    }

    void displayStats() const override {
        GenericRobot::displayStats();
        cout << "Type: ThirtyShotBot | Shells: " << shells << "/30" << endl;
    }
};

#endif
