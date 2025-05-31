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

#ifndef SEMIAUTOBOT_H
#define SEMIAUTOBOT_H


#include "genericrobot.h"
#include "battlefield.h"
#include "Constants.h"
#include "trackbot.h"
#include "thirtyshotbot.h"
#include "LongShotBot.h"
#include "HideBot.h"
#include "scoutbot.h"
#include "JumpBot.h"

class SemiAutoBot : public virtual GenericRobot {
public:
    SemiAutoBot(const string& name, int startX, int startY, int w, int h, Battlefield* battlefield)
        : GenericRobot(name, startX, startY, w, h, battlefield) {
        chooseShootingUpgrade("SemiAutoBot");
    }

    // Fire 3 times at normal range (adjacent squares), higher chance to hit
    void fire(int x, int y) override {
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

        Battlefield* bf = this->getBattlefield();
        if (!bf) return;

        if (targetX < 0 || targetX >= bf->getWidth() ||
            targetY < 0 || targetY >= bf->getHeight()) {
            return;
        }

        Robot* target = bf->getRobotAt(targetX, targetY);
        if (target != nullptr && target->isAlive()) {
            bool hit = false;
            for (int i = 0; i < 3; ++i) {
                if (rand() % 100 < 70) {
                    hit = true;
                    cout << name << " hit " << target->getName() << " with burst shot!" << endl;
                    target->takeDamage(name, bf);
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

//2nd upgrade
// SemiAuto + Jump + Scout
class SemiAutoJumpScoutBot : public virtual SemiAutoBot, public virtual JumpBot, public virtual ScoutBot {
public:
    SemiAutoJumpScoutBot(const string& name, int x, int y, int w, int h, Battlefield* battlefield)
        : GenericRobot(name, x, y, w, h, battlefield), SemiAutoBot(name, x, y, w, h, battlefield), JumpBot(name, x, y, w, h, battlefield), ScoutBot(name, x, y, w, h, battlefield) {}
    void displayStats() const override {
        cout << "Upgrade: SemiAuto + Jump + Scout" << endl;
        SemiAutoBot::displayStats();
        JumpBot::displayStats();
        ScoutBot::displayStats();
    }
};

// SemiAuto + Jump + Track
class SemiAutoJumpTrackBot : public virtual SemiAutoBot, public virtual JumpBot, public virtual TrackBot {
public:
    SemiAutoJumpTrackBot(const string& name, int x, int y, int w, int h, Battlefield* battlefield)
        : GenericRobot(name, x, y, w, h, battlefield), SemiAutoBot(name, x, y, w, h, battlefield), JumpBot(name, x, y, w, h, battlefield), TrackBot(name, x, y, w, h, battlefield) {}
    void displayStats() const override {
        cout << "Upgrade: SemiAuto + Jump + Track" << endl;
        SemiAutoBot::displayStats();
        JumpBot::displayStats();
        TrackBot::displayStats();
    }
};

// SemiAuto + Hide + Scout
class SemiAutoHideScoutBot : public virtual SemiAutoBot, public virtual HideBot, public virtual ScoutBot {
public:
    SemiAutoHideScoutBot(const string& name, int x, int y, int w, int h, Battlefield* battlefield)
        : GenericRobot(name, x, y, w, h, battlefield), SemiAutoBot(name, x, y, w, h, battlefield), HideBot(name, x, y, w, h, battlefield), ScoutBot(name, x, y, w, h, battlefield) {}
    void displayStats() const override {
        cout << "Upgrade: SemiAuto + Hide + Scout" << endl;
        SemiAutoBot::displayStats();
        HideBot::displayStats();
        ScoutBot::displayStats();
    }
};

// SemiAuto + Hide + Track
class SemiAutoHideTrackBot : public virtual SemiAutoBot, public virtual HideBot, public virtual TrackBot {
public:
    SemiAutoHideTrackBot(const string& name, int x, int y, int w, int h, Battlefield* battlefield)
        : GenericRobot(name, x, y, w, h, battlefield), SemiAutoBot(name, x, y, w, h, battlefield), HideBot(name, x, y, w, h, battlefield), TrackBot(name, x, y, w, h, battlefield) {}
    void displayStats() const override {
        cout << "Upgrade: SemiAuto + Hide + Track" << endl;
        SemiAutoBot::displayStats();
        HideBot::displayStats();
        TrackBot::displayStats();
    }
};

// SemiAuto + Track + Hide
class SemiAutoTrackHideBot : public virtual SemiAutoBot, public virtual TrackBot, public virtual HideBot {
public:
    SemiAutoTrackHideBot(const string& name, int x, int y, int w, int h, Battlefield* battlefield)
        : GenericRobot(name, x, y, w, h, battlefield), SemiAutoBot(name, x, y, w, h, battlefield), TrackBot(name, x, y, w, h, battlefield), HideBot(name, x, y, w, h, battlefield) {}
    void displayStats() const override {
        cout << "Upgrade: SemiAuto + Track + Hide" << endl;
        SemiAutoBot::displayStats();
        TrackBot::displayStats();
        HideBot::displayStats();
    }
};

// SemiAuto + Track + Jump
class SemiAutoTrackJumpBot : public virtual SemiAutoBot, public virtual TrackBot, public virtual JumpBot {
public:
    SemiAutoTrackJumpBot(const string& name, int x, int y, int w, int h, Battlefield* battlefield)
        : GenericRobot(name, x, y, w, h, battlefield), SemiAutoBot(name, x, y, w, h, battlefield), TrackBot(name, x, y, w, h, battlefield), JumpBot(name, x, y, w, h, battlefield) {}
    void displayStats() const override {
        cout << "Upgrade: SemiAuto + Track + Jump" << endl;
        SemiAutoBot::displayStats();
        TrackBot::displayStats();
        JumpBot::displayStats();
    }
};

// SemiAuto + Scout + Hide
class SemiAutoScoutHideBot : public virtual SemiAutoBot, public virtual ScoutBot, public virtual HideBot {
public:
    SemiAutoScoutHideBot(const string& name, int x, int y, int w, int h, Battlefield* battlefield)
        : GenericRobot(name, x, y, w, h, battlefield), SemiAutoBot(name, x, y, w, h, battlefield), ScoutBot(name, x, y, w, h, battlefield), HideBot(name, x, y, w, h, battlefield) {}
    void displayStats() const override {
        cout << "Upgrade: SemiAuto + Scout + Hide" << endl;
        SemiAutoBot::displayStats();
        ScoutBot::displayStats();
        HideBot::displayStats();
    }
};

// SemiAuto + Scout + Jump
class SemiAutoScoutJumpBot : public virtual SemiAutoBot, public virtual ScoutBot, public virtual JumpBot {
public:
    SemiAutoScoutJumpBot(const string& name, int x, int y, int w, int h, Battlefield* battlefield)
        : GenericRobot(name, x, y, w, h, battlefield), SemiAutoBot(name, x, y, w, h, battlefield), ScoutBot(name, x, y, w, h, battlefield), JumpBot(name, x, y, w, h, battlefield) {}
    void displayStats() const override {
        cout << "Upgrade: SemiAuto + Scout + Jump" << endl;
        SemiAutoBot::displayStats();
        ScoutBot::displayStats();
        JumpBot::displayStats();
    }
};

#endif
