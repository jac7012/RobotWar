#ifndef THIRTYSHOTBOT_H
#define THIRTYSHOTBOT_H

#include "GenericRobot.h"
#include "JumpBot.h"
#include "TrackBot.h"
#include "ScoutBot.h"
#include "HideBot.h"
#include "SemiAutoBot.h"
#include "LongShotBot.h"

class ThirtyShotBot : public virtual GenericRobot {
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

// ThirtyShot + Hide
class ThirtyShotHideBot : public virtual ThirtyShotBot, public virtual HideBot {
public:
    ThirtyShotHideBot(const string& name, int x, int y, int w, int h)
        : GenericRobot(name, x, y, w, h), ThirtyShotBot(name, x, y, w, h), HideBot(name, x, y, w, h) {}
    void think() override { ThirtyShotBot::think(); HideBot::think(); }
    void displayStats() const override {
        cout << "Upgrade: ThirtyShot + Hide" << endl;
        ThirtyShotBot::displayStats();
        HideBot::displayStats();
    }
};

// ThirtyShot + Jump
class ThirtyShotJumpBot : public virtual ThirtyShotBot, public virtual JumpBot {
public:
    ThirtyShotJumpBot(const string& name, int x, int y, int w, int h)
        : GenericRobot(name, x, y, w, h), ThirtyShotBot(name, x, y, w, h), JumpBot(name, x, y, w, h) {}
    void think() override { ThirtyShotBot::think(); JumpBot::think(); }
    void displayStats() const override {
        cout << "Upgrade: ThirtyShot + Jump" << endl;
        ThirtyShotBot::displayStats();
        JumpBot::displayStats();
    }
};

// ThirtyShot + Scout
class ThirtyShotScoutBot : public virtual ThirtyShotBot, public virtual ScoutBot {
public:
    ThirtyShotScoutBot(const string& name, int x, int y, int w, int h)
        : GenericRobot(name, x, y, w, h), ThirtyShotBot(name, x, y, w, h), ScoutBot(name, x, y, w, h) {}
    void think() override { ThirtyShotBot::think(); ScoutBot::think(); }
    void displayStats() const override {
        cout << "Upgrade: ThirtyShot + Scout" << endl;
        ThirtyShotBot::displayStats();
        ScoutBot::displayStats();
    }
};

// ThirtyShot + Track
class ThirtyShotTrackBot : public virtual ThirtyShotBot, public virtual TrackBot {
public:
    ThirtyShotTrackBot(const string& name, int x, int y, int w, int h)
        : GenericRobot(name, x, y, w, h), ThirtyShotBot(name, x, y, w, h), TrackBot(name, x, y, w, h) {}
    void think() override { ThirtyShotBot::think(); TrackBot::think(); }
    void displayStats() const override {
        cout << "Upgrade: ThirtyShot + Track" << endl;
        ThirtyShotBot::displayStats();
        TrackBot::displayStats();
    }
};

// ThirtyShot + Hide + Scout
class ThirtyShotHideScoutBot : public virtual ThirtyShotBot, public virtual HideBot, public virtual ScoutBot {
public:
    ThirtyShotHideScoutBot(const string& name, int x, int y, int w, int h)
        : GenericRobot(name, x, y, w, h), ThirtyShotBot(name, x, y, w, h), HideBot(name, x, y, w, h), ScoutBot(name, x, y, w, h) {}
    void think() override { ThirtyShotBot::think(); HideBot::think(); ScoutBot::think(); }
    void displayStats() const override {
        cout << "Upgrade: ThirtyShot + Hide + Scout" << endl;
        ThirtyShotBot::displayStats();
        HideBot::displayStats();
        ScoutBot::displayStats();
    }
};

// ThirtyShot + Hide + Track
class ThirtyShotHideTrackBot : public virtual ThirtyShotBot, public virtual HideBot, public virtual TrackBot {
public:
    ThirtyShotHideTrackBot(const string& name, int x, int y, int w, int h)
        : GenericRobot(name, x, y, w, h), ThirtyShotBot(name, x, y, w, h), HideBot(name, x, y, w, h), TrackBot(name, x, y, w, h) {}
    void think() override { ThirtyShotBot::think(); HideBot::think(); TrackBot::think(); }
    void displayStats() const override {
        cout << "Upgrade: ThirtyShot + Hide + Track" << endl;
        ThirtyShotBot::displayStats();
        HideBot::displayStats();
        TrackBot::displayStats();
    }
};

// ThirtyShot + Jump + Scout
class ThirtyShotJumpScoutBot : public virtual ThirtyShotBot, public virtual JumpBot, public virtual ScoutBot {
public:
    ThirtyShotJumpScoutBot(const string& name, int x, int y, int w, int h)
        : GenericRobot(name, x, y, w, h), ThirtyShotBot(name, x, y, w, h), JumpBot(name, x, y, w, h), ScoutBot(name, x, y, w, h) {}
    void think() override { ThirtyShotBot::think(); JumpBot::think(); ScoutBot::think(); }
    void displayStats() const override {
        cout << "Upgrade: ThirtyShot + Jump + Scout" << endl;
        ThirtyShotBot::displayStats();
        JumpBot::displayStats();
        ScoutBot::displayStats();
    }
};

// ThirtyShot + Jump + Track
class ThirtyShotJumpTrackBot : public virtual ThirtyShotBot, public virtual JumpBot, public virtual TrackBot {
public:
    ThirtyShotJumpTrackBot(const string& name, int x, int y, int w, int h)
        : GenericRobot(name, x, y, w, h), ThirtyShotBot(name, x, y, w, h), JumpBot(name, x, y, w, h), TrackBot(name, x, y, w, h) {}
    void think() override { ThirtyShotBot::think(); JumpBot::think(); TrackBot::think(); }
    void displayStats() const override {
        cout << "Upgrade: ThirtyShot + Jump + Track" << endl;
        ThirtyShotBot::displayStats();
        JumpBot::displayStats();
        TrackBot::displayStats();
    }
};

#endif
