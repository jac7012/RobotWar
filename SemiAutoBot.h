#ifndef SEMIAUTOBOT_H
#define SEMIAUTOBOT_H

#include "GenericRobot.h"
#include "JumpBot.h"
#include "TrackBot.h"   
#include "ThirtyShotBot.h"
#include "ScoutBot.h"
#include "HideBot.h"
#include "LongShotBot.h"

class SemiAutoBot : public virtual GenericRobot {
public:
    SemiAutoBot(const string& name, int startX, int startY, int w, int h)
        : GenericRobot(name, startX, startY, w, h) {
        chooseShootingUpgrade("SemiAutoBot");
    }

    void fire(Battlefield* battlefield, int x, int y) override {
        if (shells <= 0) return;
        
        if (x < -1 || x > 1 || y < -1 || y > 1 || (x == 0 && y == 0)) return;
        
        shells--;
        int targetX = pos.robotPositionX + x;
        int targetY = pos.robotPositionY + y;
        
        if (targetX < 0 || targetX >= fieldWidth ||
            targetY < 0 || targetY >= fieldHeight)
            return;

        cout << name << " firing 3-shot burst!\n";
        for (int i = 0; i < 3; i++) {
            if (rand() % 100 < 70) {
                int damage = rand() % 71;
                Robot* target = battlefield->getRobotAt(targetX, targetY);
                if (target != nullptr && target->isLives()) {
                    target->takeDamage(damage);
                    cout << "Hit " << target->getName() 
                         << " with burst shot\n";
                }
            }
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
    SemiAutoScoutBot(const string& name, int x, int y, int w, int h)
        : GenericRobot(name, x, y, w, h), SemiAutoBot(name, x, y, w, h), ScoutBot(name, x, y, w, h) {}
    void think() override { SemiAutoBot::think(); ScoutBot::think(); }
    void displayStats() const override {
        cout << "Upgrade: SemiAuto + Scout" << endl;
        SemiAutoBot::displayStats();
        ScoutBot::displayStats();
    }
};

// SemiAuto + Track
class SemiAutoTrackBot : public virtual SemiAutoBot, public virtual TrackBot {
public:
    SemiAutoTrackBot(const string& name, int x, int y, int w, int h)
        : GenericRobot(name, x, y, w, h), SemiAutoBot(name, x, y, w, h), TrackBot(name, x, y, w, h) {}
    void think() override { SemiAutoBot::think(); TrackBot::think(); }
    void displayStats() const override {
        cout << "Upgrade: SemiAuto + Track" << endl;
        SemiAutoBot::displayStats();
        TrackBot::displayStats();
    }
};

// SemiAuto + Hide
class SemiAutoHideBot : public virtual SemiAutoBot, public virtual HideBot {
public:
    SemiAutoHideBot(const string& name, int x, int y, int w, int h)
        : GenericRobot(name, x, y, w, h), SemiAutoBot(name, x, y, w, h), HideBot(name, x, y, w, h) {}
    void think() override { SemiAutoBot::think(); HideBot::think(); }
    void displayStats() const override {
        cout << "Upgrade: SemiAuto + Hide" << endl;
        SemiAutoBot::displayStats();
        HideBot::displayStats();
    }
};

// SemiAuto + Jump
class SemiAutoJumpBot : public virtual SemiAutoBot, public virtual JumpBot {
public:
    SemiAutoJumpBot(const string& name, int x, int y, int w, int h)
        : GenericRobot(name, x, y, w, h), SemiAutoBot(name, x, y, w, h), JumpBot(name, x, y, w, h) {}
    void think() override { SemiAutoBot::think(); JumpBot::think(); }
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
    SemiAutoJumpScoutBot(const string& name, int x, int y, int w, int h)
        : GenericRobot(name, x, y, w, h), SemiAutoBot(name, x, y, w, h), JumpBot(name, x, y, w, h), ScoutBot(name, x, y, w, h) {}
    void think() override { SemiAutoBot::think(); JumpBot::think(); ScoutBot::think(); }
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
    SemiAutoJumpTrackBot(const string& name, int x, int y, int w, int h)
        : GenericRobot(name, x, y, w, h), SemiAutoBot(name, x, y, w, h), JumpBot(name, x, y, w, h), TrackBot(name, x, y, w, h) {}
    void think() override { SemiAutoBot::think(); JumpBot::think(); TrackBot::think(); }
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
    SemiAutoHideScoutBot(const string& name, int x, int y, int w, int h)
        : GenericRobot(name, x, y, w, h), SemiAutoBot(name, x, y, w, h), HideBot(name, x, y, w, h), ScoutBot(name, x, y, w, h) {}
    void think() override { SemiAutoBot::think(); HideBot::think(); ScoutBot::think(); }
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
    SemiAutoHideTrackBot(const string& name, int x, int y, int w, int h)
        : GenericRobot(name, x, y, w, h), SemiAutoBot(name, x, y, w, h), HideBot(name, x, y, w, h), TrackBot(name, x, y, w, h) {}
    void think() override { SemiAutoBot::think(); HideBot::think(); TrackBot::think(); }
    void displayStats() const override {
        cout << "Upgrade: SemiAuto + Hide + Track" << endl;
        SemiAutoBot::displayStats();
        HideBot::displayStats();
        TrackBot::displayStats();
    }
};

#endif
