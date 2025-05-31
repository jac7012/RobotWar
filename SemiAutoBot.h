#pragma once

/**********|**********|**********|
 Program: SemiAutoBot.h
 Course: OOPDS
 Trimester: 2510
 Name: Lim E Jac
 ID: 242UC245BG
 Lecture Section: TC1L
 Tutorial Section: TT2L
 Email: LIM.E.JAC@student.mmu.edu.my
 Phone: 017-7026113
 **********|**********|**********/

#include "genericrobot.h"
#include "battlefield.h"
#include "Constants.h"

class SemiAutoBot : public virtual GenericRobot , public virtual ShootingRobot {
public:
    SemiAutoBot(const string& name, int startX, int startY, int w, int h, Battlefield* battlefield)
        : GenericRobot(name, startX, startY, w, h, battlefield) {
        chooseShootingUpgrade("SemiAutoBot");
    }

    // Fire 3 times at normal range (adjacent squares), higher chance to hit
    void fire(Battlefield& battlefield, int x, int y) override {
        if (shells <= 0) {
            return; // no shells left, cannot shoot
        }

        if (x < -1 || x > 1 || y < -1 || y > 1 || (x == 0 && y == 0)) {
            cout << "Target out of range for SemiAutoBot!\n";
            return;
        }

        shells--;

        int targetX = pos.robotPositionX + x;
        int targetY = pos.robotPositionY + y;

        if (targetX < 0 || targetX >= battlefield.getWidth() ||
            targetY < 0 || targetY >= battlefield.getHeight()) {
            return;
        }

        Robot* target = battlefield.getRobotAt(targetX, targetY);
        if (target != nullptr && target->isAlive()) {
            bool hit = false;
            for (int i = 0; i < 3; ++i) {
                if (rand() % 100 < 70) {
                    hit = true;
                    cout << name << " hit " << target->getName() << " with burst shot!" << endl;
                    target->takeDamage(name, &battlefield);
                }
            }
            if (!hit) {
                cout << name << " missed all burst shots at " << target->getName() << "." << endl;
            }
        } else {
            cout << name << " fired at (" << targetX << ", " << targetY << ") but no target." << endl;
        }
    }

    void displayStats() const override {
        GenericRobot::displayStats();
        cout << "Upgrade: SemiAutoBot | 3-shot burst" << endl;
    }
};

//First Upgrade
// SemiAuto + Scout
class SemiAutoScoutBot : public virtual SemiAutoBot, public virtual ScoutBot {
public:
    SemiAutoScoutBot(const string& name, int x, int y, int w, int h, Battlefield* battlefield)
        : GenericRobot(name, x, y, w, h, battlefield), SemiAutoBot(name, x, y, w, h, battlefield), ScoutBot(name, x, y, w, h, battlefield) {}
    void displayStats() const override {
        cout << "Upgrade: SemiAuto + Scout" << endl;
        SemiAutoBot::displayStats();
        ScoutBot::displayStats();
    }
};

// SemiAuto + Track
class SemiAutoTrackBot : public virtual SemiAutoBot, public virtual TrackBot {
public:
    SemiAutoTrackBot(const string& name, int x, int y, int w, int h, Battlefield* battlefield)
        : GenericRobot(name, x, y, w, h, battlefield), SemiAutoBot(name, x, y, w, h, battlefield), TrackBot(name, x, y, w, h, battlefield) {}
    void displayStats() const override {
        cout << "Upgrade: SemiAuto + Track" << endl;
        SemiAutoBot::displayStats();
        TrackBot::displayStats();
    }
};

// SemiAuto + Hide
class SemiAutoHideBot : public virtual SemiAutoBot, public virtual HideBot {
public:
    SemiAutoHideBot(const string& name, int x, int y, int w, int h, Battlefield* battlefield)
        : GenericRobot(name, x, y, w, h, battlefield), SemiAutoBot(name, x, y, w, h, battlefield), HideBot(name, x, y, w, h, battlefield) {}
    void displayStats() const override {
        cout << "Upgrade: SemiAuto + Hide" << endl;
        SemiAutoBot::displayStats();
        HideBot::displayStats();
    }
};

// SemiAuto + Jump
class SemiAutoJumpBot : public virtual SemiAutoBot, public virtual JumpBot {
public:
    SemiAutoJumpBot(const string& name, int x, int y, int w, int h, Battlefield* battlefield)
        : GenericRobot(name, x, y, w, h, battlefield), SemiAutoBot(name, x, y, w, h, battlefield), JumpBot(name, x, y, w, h, battlefield) {}
    void displayStats() const override {
        cout << "Upgrade: SemiAuto + Jump" << endl;
        SemiAutoBot::displayStats();
        JumpBot::displayStats();
    }
};
