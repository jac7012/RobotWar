#ifndef LONGSHOTBOT_H
#define LONGSHOTBOT_H

#include "GenericRobot.h"
#include "JumpBot.h"
#include "TrackBot.h"
#include "ThirtyShotBot.h"
#include "SemiAutoBot.h"
#include "ScoutBot.h"
#include "HideBot.h"

class LongShotBot : public virtual GenericRobot {
public:
    LongShotBot(const string& name, int startX, int startY, int w, int h)
        : GenericRobot(name, startX, startY, w, h) {
        chooseShootingUpgrade("LongShotBot");
    }

    void fire(Battlefield* battlefield, int x, int y) override {
        if (shells <= 0) return;
        
        if (abs(x) + abs(y) > 3) {
            cout << "Target out of range for LongShotBot!\n";
            return;
        }

        shells--;
        int targetX = pos.robotPositionX + x;
        int targetY = pos.robotPositionY + y;
        
        if (targetX < 0 || targetX >= fieldWidth ||
            targetY < 0 || targetY >= fieldHeight)
            return;

        if (rand() % 100 < 70) {
            int damage = rand() % 71;
            Robot* target = battlefield->getRobotAt(targetX, targetY);
            if (target != nullptr && target->isLives()) {
                target->takeDamage(damage);
                cout << name << " hit " << target->getName() 
                     << " from long range \n";
            }
        }
    }

    void displayStats() const override {
        GenericRobot::displayStats();
        cout << "Upgrade: LongShotBot | Range: 3 units" << endl;
    }
};


// LongShot + Hide
class LongShotHideBot : public virtual LongShotBot, public virtual HideBot {
public:
    LongShotHideBot(const string& name, int startX, int startY, int w, int h)
        : GenericRobot(name, startX, startY, w, h),
          LongShotBot(name, startX, startY, w, h),
          HideBot(name, startX, startY, w, h) {}

    void think() override {
        LongShotBot::think();
        HideBot::think();
    }

    void fire(Battlefield* battlefield, int x, int y) override {
        LongShotBot::fire(battlefield, x, y);
    }

    void displayStats() const override {
        cout << "Upgrade: LongShot + Hide" << endl;
        LongShotBot::displayStats();
        HideBot::displayStats();
    }
};

// LongShot + Scout
class LongShotScoutBot : public virtual LongShotBot, public virtual ScoutBot {
public:
    LongShotScoutBot(const string& name, int startX, int startY, int w, int h)
        : GenericRobot(name, startX, startY, w, h),
          LongShotBot(name, startX, startY, w, h),
          ScoutBot(name, startX, startY, w, h) {}

    void think() override {
        LongShotBot::think();
        ScoutBot::think();
    }

    void fire(Battlefield* battlefield, int x, int y) override {
        LongShotBot::fire(battlefield, x, y);
    }

    void displayStats() const override {
        cout << "Upgrade: LongShot + Scout" << endl;
        LongShotBot::displayStats();
        ScoutBot::displayStats();
    }
};


// LongShot + Jump
class LongShotJumpBot : public virtual LongShotBot, public virtual JumpBot {
public:
    LongShotJumpBot(const string& name, int startX, int startY, int w, int h)
        : GenericRobot(name, startX, startY, w, h),
          LongShotBot(name, startX, startY, w, h),
          JumpBot(name, startX, startY, w, h) {}

    void think() override {
        LongShotBot::think();
        JumpBot::think();
    }

    // Fix ambiguity by explicitly overriding fire()
    void fire(Battlefield* battlefield, int x, int y) override {
        LongShotBot::fire(battlefield, x, y);
    }

    void displayStats() const override {
        cout << "Upgrade: LongShot + Jump" << endl;
        LongShotBot::displayStats();
        JumpBot::displayStats();
    }
};

// LongShot + Track
class LongShotTrackBot : public virtual LongShotBot, public virtual TrackBot {
public:
    LongShotTrackBot(const string& name, int startX, int startY, int w, int h)
        : GenericRobot(name, startX, startY, w, h),
          LongShotBot(name, startX, startY, w, h),
          TrackBot(name, startX, startY, w, h) {}

    void think() override {
        LongShotBot::think();
        TrackBot::think();
    }

    void fire(Battlefield* battlefield, int x, int y) override {
        LongShotBot::fire(battlefield, x, y);
    }

    void displayStats() const override {
        cout << "Upgrade: LongShot + Track" << endl;
        LongShotBot::displayStats();
        TrackBot::displayStats();
    }
};

// LongShot + Jump + Track
class LongShotJumpTrackBot : public virtual LongShotBot, public virtual JumpBot, public virtual TrackBot {
public:
    LongShotJumpTrackBot(const string& name, int startX, int startY, int w, int h)
        : GenericRobot(name, startX, startY, w, h),
          LongShotBot(name, startX, startY, w, h),
          JumpBot(name, startX, startY, w, h),
          TrackBot(name, startX, startY, w, h) {}

    void think() override {
        LongShotBot::think();
        JumpBot::think();
        TrackBot::think();
    }

    // Explicitly resolve fire() ambiguity
    void fire(Battlefield* battlefield, int x, int y) override {
        LongShotBot::fire(battlefield, x, y);
    }

    void displayStats() const override {
        cout << "Upgrade: LongShot + Jump + Track" << endl;
        LongShotBot::displayStats();
        JumpBot::displayStats();
        TrackBot::displayStats();
    }
};

// LongShot + Hide + Scout
class LongShotHideScoutBot : public virtual LongShotBot, public virtual HideBot, public virtual ScoutBot {
public:
    LongShotHideScoutBot(const string& name, int startX, int startY, int w, int h)
        : GenericRobot(name, startX, startY, w, h),
          LongShotBot(name, startX, startY, w, h),
          HideBot(name, startX, startY, w, h),
          ScoutBot(name, startX, startY, w, h) {}

    void think() override {
        LongShotBot::think();
        HideBot::think();
        ScoutBot::think();
    }

    void fire(Battlefield* battlefield, int x, int y) override {
        LongShotBot::fire(battlefield, x, y);
    }

    void displayStats() const override {
        cout << "Upgrade: LongShot + Hide + Scout" << endl;
        LongShotBot::displayStats();
        HideBot::displayStats();
        ScoutBot::displayStats();
    }
};

// LongShot + Hide + Track
class LongShotHideTrackBot : public virtual LongShotBot, public virtual HideBot, public virtual TrackBot {
public:
    LongShotHideTrackBot(const string& name, int startX, int startY, int w, int h)
        : GenericRobot(name, startX, startY, w, h),
          LongShotBot(name, startX, startY, w, h),
          HideBot(name, startX, startY, w, h),
          TrackBot(name, startX, startY, w, h) {}

    void think() override {
        LongShotBot::think();
        HideBot::think();
        TrackBot::think();
    }

    void fire(Battlefield* battlefield, int x, int y) override {
        LongShotBot::fire(battlefield, x, y);
    }

    void displayStats() const override {
        cout << "Upgrade: LongShot + Hide + Track" << endl;
        LongShotBot::displayStats();
        HideBot::displayStats();
        TrackBot::displayStats();
    }
};

// LongShot + Jump + Scout
class LongShotJumpScoutBot : public virtual LongShotBot, public virtual JumpBot, public virtual ScoutBot {
public:
    LongShotJumpScoutBot(const string& name, int startX, int startY, int w, int h)
        : GenericRobot(name, startX, startY, w, h),
          LongShotBot(name, startX, startY, w, h),
          JumpBot(name, startX, startY, w, h),
          ScoutBot(name, startX, startY, w, h) {}

    void think() override {
        LongShotBot::think();
        JumpBot::think();
        ScoutBot::think();
    }

    void fire(Battlefield* battlefield, int x, int y) override {
        LongShotBot::fire(battlefield, x, y);
    }

    void displayStats() const override {
        cout << "Upgrade: LongShot + Jump + Scout" << endl;
        LongShotBot::displayStats();
        JumpBot::displayStats();
        ScoutBot::displayStats();
    }
};

// LongShot + Scout + Hide
class LongShotScoutHideBot : public virtual LongShotBot, public virtual ScoutBot, public virtual HideBot {
public:
    LongShotScoutHideBot(const string& name, int startX, int startY, int w, int h)
        : GenericRobot(name, startX, startY, w, h),
          LongShotBot(name, startX, startY, w, h),
          ScoutBot(name, startX, startY, w, h),
          HideBot(name, startX, startY, w, h) {}

    void think() override {
        LongShotBot::think();
        ScoutBot::think();
        HideBot::think();
    }

    void fire(Battlefield* battlefield, int x, int y) override {
        LongShotBot::fire(battlefield, x, y);
    }

    void displayStats() const override {
        cout << "Upgrade: LongShot + Scout + Hide" << endl;
        LongShotBot::displayStats();
        ScoutBot::displayStats();
        HideBot::displayStats();
    }
};

// LongShot + Track + Hide
class LongShotTrackHideBot : public virtual LongShotBot, public virtual TrackBot, public virtual HideBot {
public:
    LongShotTrackHideBot(const string& name, int startX, int startY, int w, int h)
        : GenericRobot(name, startX, startY, w, h),
          LongShotBot(name, startX, startY, w, h),
          TrackBot(name, startX, startY, w, h),
          HideBot(name, startX, startY, w, h) {}

    void think() override {
        LongShotBot::think();
        TrackBot::think();
        HideBot::think();
    }

    void fire(Battlefield* battlefield, int x, int y) override {
        LongShotBot::fire(battlefield, x, y);
    }

    void displayStats() const override {
        cout << "Upgrade: LongShot + Track + Hide" << endl;
        LongShotBot::displayStats();
        TrackBot::displayStats();
        HideBot::displayStats();
    }
};

// LongShot + Track + Jump
class LongShotTrackJumpBot : public virtual LongShotBot, public virtual TrackBot, public virtual JumpBot {
public:
    LongShotTrackJumpBot(const string& name, int startX, int startY, int w, int h)
        : GenericRobot(name, startX, startY, w, h),
          LongShotBot(name, startX, startY, w, h),
          TrackBot(name, startX, startY, w, h),
          JumpBot(name, startX, startY, w, h) {}

    void think() override {
        LongShotBot::think();
        TrackBot::think();
        JumpBot::think();
    }

    void fire(Battlefield* battlefield, int x, int y) override {
        LongShotBot::fire(battlefield, x, y);
    }

    void displayStats() const override {
        cout << "Upgrade: LongShot + Track + Jump" << endl;
        LongShotBot::displayStats();
        TrackBot::displayStats();
        JumpBot::displayStats();
    }
};

// LongShot + Scout + Jump
class LongShotScoutJumpBot : public virtual LongShotBot, public virtual ScoutBot, public virtual JumpBot {
public:
    LongShotScoutJumpBot(const string& name, int startX, int startY, int w, int h)
        : GenericRobot(name, startX, startY, w, h),
          LongShotBot(name, startX, startY, w, h),
          ScoutBot(name, startX, startY, w, h),
          JumpBot(name, startX, startY, w, h) {}

    void think() override {
        LongShotBot::think();
        ScoutBot::think();
        JumpBot::think();
    }

    void fire(Battlefield* battlefield, int x, int y) override {
        LongShotBot::fire(battlefield, x, y);
    }

    void displayStats() const override {
        cout << "Upgrade: LongShot + Scout + Jump" << endl;
        LongShotBot::displayStats();
        ScoutBot::displayStats();
        JumpBot::displayStats();
    }
};

#endif
