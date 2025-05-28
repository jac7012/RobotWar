#ifndef JUMPBOT_H
#define JUMPBOT_H

#include "GenericRobot.h"
#include "Battlefield.h"
#include "TrackBot.h"
#include "ThirtyShotBot.h"
#include "SemiAutoBot.h"
#include "hideBot.h"
#include "JumpBot.h"

class JumpBot : public virtual GenericRobot {
private:
    int jumpCount;
    
public:
    JumpBot(const string& name, int startX, int startY, int w, int h)
        : GenericRobot(name, startX, startY, w, h), jumpCount(3) {
        chooseMovingUpgrade("JumpBot");
    }

    void jump(Battlefield& battlefield, int targetX, int targetY) override {
        if (jumpCount > 0) {
            if (targetX >= 0 && targetX < fieldWidth && 
                targetY >= 0 && targetY < fieldHeight) {
                Position newPos;
                newPos.robotPositionX = targetX;
                newPos.robotPositionY = targetY;
                
                if (battlefield.isValidMove(newPos)) {
                    pos = newPos;
                    jumpCount--;
                    cout << name << " jumped to (" << targetX << "," << targetY 
                         << ") (" << jumpCount << " jumps remaining)\n";
                }
            }
        }
    }

    void displayStats() const override {
        GenericRobot::displayStats();
        cout << "Upgrade: JumpBot | Jumps left: " << jumpCount << endl;
    }
};


// Jump + LongShot
class JumpLongShotBot : public virtual JumpBot, public virtual LongShotBot {
public:
    JumpLongShotBot(const string& name, int startX, int startY, int w, int h)
        : GenericRobot(name, startX, startY, w, h),
          JumpBot(name, startX, startY, w, h),
          LongShotBot(name, startX, startY, w, h) {}

    void think() override {
        JumpBot::think();
        LongShotBot::think();
    }

    void fire(Battlefield* battlefield, int x, int y) override {
        LongShotBot::fire(battlefield, x, y);
    }

    void displayStats() const override {
        GenericRobot::displayStats();
        cout << "Upgrade: Jump + LongShot" << endl;
    }
};

// Jump + Scout
class JumpScoutBot : public virtual JumpBot, public virtual ScoutBot {
public:
    JumpScoutBot(const string& name, int startX, int startY, int w, int h)
        : GenericRobot(name, startX, startY, w, h),
          JumpBot(name, startX, startY, w, h),
          ScoutBot(name, startX, startY, w, h) {}

    void think() override {
        JumpBot::think();
        ScoutBot::think();
    }

    void displayStats() const override {
        GenericRobot::displayStats();
        cout << "Upgrade: Jump + Scout" << endl;
    }
};

// Jump + Track
class JumpTrackBot : public virtual JumpBot, public virtual TrackBot {
public:
    JumpTrackBot(const string& name, int startX, int startY, int w, int h)
        : GenericRobot(name, startX, startY, w, h),
          JumpBot(name, startX, startY, w, h),
          TrackBot(name, startX, startY, w, h) {}

    void think() override {
        JumpBot::think();
        TrackBot::think();
    }

    void displayStats() const override {
        GenericRobot::displayStats();
        cout << "Upgrade: Jump + Track" << endl;
    }
};

// Jump + ThirtyShot
class JumpThirtyShotBot : public virtual JumpBot, public virtual ThirtyShotBot {
public:
    JumpThirtyShotBot(const string& name, int startX, int startY, int w, int h)
        : GenericRobot(name, startX, startY, w, h),
          JumpBot(name, startX, startY, w, h),
          ThirtyShotBot(name, startX, startY, w, h) {}

    void think() override {
        JumpBot::think();
        ThirtyShotBot::think();
    }

    void displayStats() const override {
        GenericRobot::displayStats();
        cout << "Upgrade: Jump + ThirtyShot" << endl;
    }
};

// Jump + SemiAuto
class JumpSemiAutoBot : public virtual JumpBot, public virtual SemiAutoBot {
public:
    JumpSemiAutoBot(const string& name, int startX, int startY, int w, int h)
        : GenericRobot(name, startX, startY, w, h),
          JumpBot(name, startX, startY, w, h),
          SemiAutoBot(name, startX, startY, w, h) {}

    void think() override {
        JumpBot::think();
        SemiAutoBot::think();
    }

    void displayStats() const override {
        GenericRobot::displayStats();
        cout << "Upgrade: Jump + SemiAuto" << endl;
    }
};

// Jump + Track + ThirtyShot
class JumpTrackThirtyShotBot : public virtual JumpBot, public virtual TrackBot, public virtual ThirtyShotBot {
public:
    JumpTrackThirtyShotBot(const string& name, int startX, int startY, int w, int h)
        : GenericRobot(name, startX, startY, w, h),
          JumpBot(name, startX, startY, w, h),
          TrackBot(name, startX, startY, w, h),
          ThirtyShotBot(name, startX, startY, w, h) {}

    void think() override {
        JumpBot::think();
        TrackBot::think();
        ThirtyShotBot::think();
    }

    void displayStats() const override {
        GenericRobot::displayStats();
        cout << "Upgrade: Jump + Track + ThirtyShot" << endl;
    }
};

// Jump + Track + SemiAuto
class JumpTrackSemiAutoBot : public virtual JumpBot, public virtual TrackBot, public virtual SemiAutoBot {
public:
    JumpTrackSemiAutoBot(const string& name, int startX, int startY, int w, int h)
        : GenericRobot(name, startX, startY, w, h),
          JumpBot(name, startX, startY, w, h),
          TrackBot(name, startX, startY, w, h),
          SemiAutoBot(name, startX, startY, w, h) {}

    void think() override {
        JumpBot::think();
        TrackBot::think();
        SemiAutoBot::think();
    }

    void displayStats() const override {
        GenericRobot::displayStats();
        cout << "Upgrade: Jump + Track + SemiAuto" << endl;
    }
};


// Jump + Track + LongShot
class JumpTrackLongShotBot : public virtual JumpBot, public virtual TrackBot, public virtual LongShotBot {
public:
    JumpTrackLongShotBot(const string& name, int startX, int startY, int w, int h)
        : GenericRobot(name, startX, startY, w, h),
          JumpBot(name, startX, startY, w, h),
          TrackBot(name, startX, startY, w, h),
          LongShotBot(name, startX, startY, w, h) {}

    void think() override {
        JumpBot::think();
        TrackBot::think();
        LongShotBot::think();
    }

    void fire(Battlefield* battlefield, int x, int y) override {
        LongShotBot::fire(battlefield, x, y);
    }

    void displayStats() const override {
        GenericRobot::displayStats();
        cout << "Upgrade: Jump + Track + LongShot" << endl;
    }
};

// Jump + Scout + LongShot
class JumpScoutLongShotBot : public virtual JumpBot, public virtual ScoutBot, public virtual LongShotBot {
public:
    JumpScoutLongShotBot(const string& name, int startX, int startY, int w, int h)
        : GenericRobot(name, startX, startY, w, h),
          JumpBot(name, startX, startY, w, h),
          ScoutBot(name, startX, startY, w, h),
          LongShotBot(name, startX, startY, w, h) {}

    void think() override {
        JumpBot::think();
        ScoutBot::think();
        LongShotBot::think();
    }

    void fire(Battlefield* battlefield, int x, int y) override {
        LongShotBot::fire(battlefield, x, y);
    }

    void displayStats() const override {
        GenericRobot::displayStats();
        cout << "Upgrade: Jump + Scout + LongShot" << endl;
    }
};

// Jump + Scout + SemiAuto
class JumpScoutSemiAutoBot : public virtual JumpBot, public virtual ScoutBot, public virtual SemiAutoBot {
public:
    JumpScoutSemiAutoBot(const string& name, int startX, int startY, int w, int h)
        : GenericRobot(name, startX, startY, w, h),
          JumpBot(name, startX, startY, w, h),
          ScoutBot(name, startX, startY, w, h),
          SemiAutoBot(name, startX, startY, w, h) {}

    void think() override {
        JumpBot::think();
        ScoutBot::think();
        SemiAutoBot::think();
    }

    void displayStats() const override {
        GenericRobot::displayStats();
        cout << "Upgrade: Jump + Scout + SemiAuto" << endl;
    }
};

// Jump + Scout + ThirtyShot
class JumpScoutThirtyShotBot : public virtual JumpBot, public virtual ScoutBot, public virtual ThirtyShotBot {
public:
    JumpScoutThirtyShotBot(const string& name, int startX, int startY, int w, int h)
        : GenericRobot(name, startX, startY, w, h),
          JumpBot(name, startX, startY, w, h),
          ScoutBot(name, startX, startY, w, h),
          ThirtyShotBot(name, startX, startY, w, h) {}

    void think() override {
        JumpBot::think();
        ScoutBot::think();
        ThirtyShotBot::think();
    }

    void displayStats() const override {
        GenericRobot::displayStats();
        cout << "Upgrade: Jump + Scout + ThirtyShot" << endl;
    }
};

// Jump + LongShot + Scout
class JumpLongShotScoutBot : public virtual JumpBot, public virtual LongShotBot, public virtual ScoutBot {
public:
    JumpLongShotScoutBot(const string& name, int startX, int startY, int w, int h)
        : GenericRobot(name, startX, startY, w, h),
          JumpBot(name, startX, startY, w, h),
          LongShotBot(name, startX, startY, w, h),
          ScoutBot(name, startX, startY, w, h) {}

    void think() override {
        JumpBot::think();
        LongShotBot::think();
        ScoutBot::think();
    }

    void fire(Battlefield* battlefield, int x, int y) override {
        LongShotBot::fire(battlefield, x, y);
    }

    void displayStats() const override {
        GenericRobot::displayStats();
        cout << "Upgrade: Jump + LongShot + Scout" << endl;
    }
};

// Jump + LongShot + Track
class JumpLongShotTrackBot : public virtual JumpBot, public virtual LongShotBot, public virtual TrackBot {
public:
    JumpLongShotTrackBot(const string& name, int startX, int startY, int w, int h)
        : GenericRobot(name, startX, startY, w, h),
          JumpBot(name, startX, startY, w, h),
          LongShotBot(name, startX, startY, w, h),
          TrackBot(name, startX, startY, w, h) {}

    void think() override {
        JumpBot::think();
        LongShotBot::think();
        TrackBot::think();
    }

    void fire(Battlefield* battlefield, int x, int y) override {
        LongShotBot::fire(battlefield, x, y);
    }

    void displayStats() const override {
        GenericRobot::displayStats();
        cout << "Upgrade: Jump + LongShot + Track" << endl;
    }
};

// Jump + SemiAuto + Scout
class JumpSemiAutoScoutBot : public virtual JumpBot, public virtual SemiAutoBot, public virtual ScoutBot {
public:
    JumpSemiAutoScoutBot(const string& name, int startX, int startY, int w, int h)
        : GenericRobot(name, startX, startY, w, h),
          JumpBot(name, startX, startY, w, h),
          SemiAutoBot(name, startX, startY, w, h),
          ScoutBot(name, startX, startY, w, h) {}

    void think() override {
        JumpBot::think();
        SemiAutoBot::think();
        ScoutBot::think();
    }

    void displayStats() const override {
        GenericRobot::displayStats();
        cout << "Upgrade: Jump + SemiAuto + Scout" << endl;
    }
};

// Jump + SemiAuto + Track
class JumpSemiAutoTrackBot : public virtual JumpBot, public virtual SemiAutoBot, public virtual TrackBot {
public:
    JumpSemiAutoTrackBot(const string& name, int startX, int startY, int w, int h)
        : GenericRobot(name, startX, startY, w, h),
          JumpBot(name, startX, startY, w, h),
          SemiAutoBot(name, startX, startY, w, h),
          TrackBot(name, startX, startY, w, h) {}

    void think() override {
        JumpBot::think();
        SemiAutoBot::think();
        TrackBot::think();
    }

    void displayStats() const override {
        GenericRobot::displayStats();
        cout << "Upgrade: Jump + SemiAuto + Track" << endl;
    }
};

// Jump + ThirtyShot + Scout
class JumpThirtyShotScoutBot : public virtual JumpBot, public virtual ThirtyShotBot, public virtual ScoutBot {
public:
    JumpThirtyShotScoutBot(const string& name, int startX, int startY, int w, int h)
        : GenericRobot(name, startX, startY, w, h),
          JumpBot(name, startX, startY, w, h),
          ThirtyShotBot(name, startX, startY, w, h),
          ScoutBot(name, startX, startY, w, h) {}

    void think() override {
        JumpBot::think();
        ThirtyShotBot::think();
        ScoutBot::think();
    }

    void displayStats() const override {
        GenericRobot::displayStats();
        cout << "Upgrade: Jump + ThirtyShot + Scout" << endl;
    }
};

// Jump + ThirtyShot + Track
class JumpThirtyShotTrackBot : public virtual JumpBot, public virtual ThirtyShotBot, public virtual TrackBot {
public:
    JumpThirtyShotTrackBot(const string& name, int startX, int startY, int w, int h)
        : GenericRobot(name, startX, startY, w, h),
          JumpBot(name, startX, startY, w, h),
          ThirtyShotBot(name, startX, startY, w, h),
          TrackBot(name, startX, startY, w, h) {}

    void think() override {
        JumpBot::think();
        ThirtyShotBot::think();
        TrackBot::think();
    }

    void displayStats() const override {
        GenericRobot::displayStats();
        cout << "Upgrade: Jump + ThirtyShot + Track" << endl;
    }
};


#endif
