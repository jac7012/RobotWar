/**********|**********|**********|
 Program: jumpBot.h
 Course: OOPDS
 Trimester: 2510
 Name: Lim E Jac
 ID: 242UC245BG
 Lecture Section: TC1L
 Tutorial Section: TT2L
 Email: LIM.E.JAC@student.mmu.edu.my
 Phone: 017-7026113
 **********|**********|**********/

#ifndef JUMPBOT_H
#define JUMPBOT_H

#include "genericrobot.h"
#include "battlefield.h"
#include "Constants.h"
#include "trackbot.h"
#include "thirtyshotbot.h"
#include "SemiAutoBot.h"
#include "HideBot.h"
#include "scoutbot.h"
#include "LongShotBot.h"

using namespace std;

class JumpBot : public virtual GenericRobot {
private:
    int jumpCount;
    
public:
    JumpBot(const string& name, int startX, int startY, int w, int h, Battlefield* battlefield)
        : GenericRobot(name, startX, startY, w, h, battlefield), jumpCount(3) {
        chooseMovingUpgrade("JumpBot");
    }

    // Add a virtual fire method to allow overrides in derived classes
    virtual void fire(Battlefield* battlefield, int x, int y) {}

    void jump(Battlefield& battlefield, int targetX, int targetY) {
        if (jumpCount > 0) {
            if (targetX >= 0 && targetX < battlefield.getWidth() && 
                targetY >= 0 && targetY < battlefield.getHeight()) {
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
    JumpLongShotBot(const string& name, int startX, int startY, int w, int h, Battlefield* battlefield)
        : GenericRobot(name, startX, startY, w, h, battlefield),
          JumpBot(name, startX, startY, w, h, battlefield),
          LongShotBot(name, startX, startY, w, h, battlefield) {}
    void fire(Battlefield* battlefield, int x, int y) override {
        LongShotBot::fire(x, y);
    }
    void displayStats() const override {
        cout << "Upgrade: Jump + LongShot" << endl;
        JumpBot::displayStats();
        LongShotBot::displayStats();
    }
};

// Jump + Scout
class JumpScoutBot : public virtual JumpBot, public virtual ScoutBot {
public:
    JumpScoutBot(const string& name, int startX, int startY, int w, int h, Battlefield* battlefield)
        : GenericRobot(name, startX, startY, w, h, battlefield),
          JumpBot(name, startX, startY, w, h, battlefield),
          ScoutBot(name, startX, startY, w, h, battlefield) {}
    void displayStats() const override {
        cout << "Upgrade: Jump + Scout" << endl;
        JumpBot::displayStats();
        ScoutBot::displayStats();
    }
};

// Jump + Track
class JumpTrackBot : public virtual JumpBot, public virtual TrackBot {
public:
    JumpTrackBot(const string& name, int startX, int startY, int w, int h, Battlefield* battlefield)
        : GenericRobot(name, startX, startY, w, h, battlefield),
          JumpBot(name, startX, startY, w, h, battlefield),
          TrackBot(name, startX, startY, w, h, battlefield) {}
    void displayStats() const override {
        cout << "Upgrade: Jump + Track" << endl;
        JumpBot::displayStats();
        TrackBot::displayStats();
    }
};

// Jump + ThirtyShot
class JumpThirtyShotBot : public virtual JumpBot, public virtual ThirtyShotBot {
public:
    JumpThirtyShotBot(const string& name, int startX, int startY, int w, int h, Battlefield* battlefield)
        : GenericRobot(name, startX, startY, w, h, battlefield),
          JumpBot(name, startX, startY, w, h, battlefield),
          ThirtyShotBot(name, startX, startY, w, h, battlefield) {}
    void displayStats() const override {
        cout << "Upgrade: Jump + ThirtyShot" << endl;
        JumpBot::displayStats();
        ThirtyShotBot::displayStats();
    }
};

// Jump + SemiAuto
class JumpSemiAutoBot : public virtual JumpBot, public virtual SemiAutoBot {
public:
    JumpSemiAutoBot(const string& name, int startX, int startY, int w, int h, Battlefield* battlefield)
        : GenericRobot(name, startX, startY, w, h, battlefield),
          JumpBot(name, startX, startY, w, h, battlefield),
          SemiAutoBot(name, startX, startY, w, h, battlefield) {}
    void displayStats() const override {
        cout << "Upgrade: Jump + SemiAuto" << endl;
        JumpBot::displayStats();
        SemiAutoBot::displayStats();
    }
};

// Jump + Track + ThirtyShot
class JumpTrackThirtyShotBot : public virtual JumpBot, public virtual TrackBot, public virtual ThirtyShotBot {
public:
    JumpTrackThirtyShotBot(const string& name, int startX, int startY, int w, int h, Battlefield* battlefield)
        : GenericRobot(name, startX, startY, w, h, battlefield),
          JumpBot(name, startX, startY, w, h, battlefield),
          TrackBot(name, startX, startY, w, h, battlefield),
          ThirtyShotBot(name, startX, startY, w, h, battlefield) {}
    void displayStats() const override {
        cout << "Upgrade: Jump + Track + ThirtyShot" << endl;
        JumpBot::displayStats();
        TrackBot::displayStats();
        ThirtyShotBot::displayStats();
    }
};

// Jump + Track + SemiAuto
class JumpTrackSemiAutoBot : public virtual JumpBot, public virtual TrackBot, public virtual SemiAutoBot {
public:
    JumpTrackSemiAutoBot(const string& name, int startX, int startY, int w, int h, Battlefield* battlefield)
        : GenericRobot(name, startX, startY, w, h, battlefield),
          JumpBot(name, startX, startY, w, h, battlefield),
          TrackBot(name, startX, startY, w, h, battlefield),
          SemiAutoBot(name, startX, startY, w, h, battlefield) {}
    void displayStats() const override {
        cout << "Upgrade: Jump + Track + SemiAuto" << endl;
        JumpBot::displayStats();
        TrackBot::displayStats();
        SemiAutoBot::displayStats();
    }
};

// Jump + Track + LongShot
class JumpTrackLongShotBot : public virtual JumpBot, public virtual TrackBot, public virtual LongShotBot {
public:
    JumpTrackLongShotBot(const string& name, int startX, int startY, int w, int h, Battlefield* battlefield)
        : GenericRobot(name, startX, startY, w, h, battlefield),
          JumpBot(name, startX, startY, w, h, battlefield),
          TrackBot(name, startX, startY, w, h, battlefield),
          LongShotBot(name, startX, startY, w, h, battlefield) {}
    void fire(Battlefield* battlefield, int x, int y) override {
        LongShotBot::fire(x, y);
    }
    void displayStats() const override {
        cout << "Upgrade: Jump + Track + LongShot" << endl;
        JumpBot::displayStats();
        TrackBot::displayStats();
        LongShotBot::displayStats();
    }
};

// Jump + Scout + LongShot
class JumpScoutLongShotBot : public virtual JumpBot, public virtual ScoutBot, public virtual LongShotBot {
public:
    JumpScoutLongShotBot(const string& name, int startX, int startY, int w, int h, Battlefield* battlefield)
        : GenericRobot(name, startX, startY, w, h, battlefield),
          JumpBot(name, startX, startY, w, h, battlefield),
          ScoutBot(name, startX, startY, w, h, battlefield),
          LongShotBot(name, startX, startY, w, h, battlefield) {}
    void fire(Battlefield* battlefield, int x, int y) override {
        LongShotBot::fire(x, y);
    }
    void displayStats() const override {
        cout << "Upgrade: Jump + Scout + LongShot" << endl;
        JumpBot::displayStats();
        ScoutBot::displayStats();
        LongShotBot::displayStats();
    }
};

// Jump + Scout + SemiAuto
class JumpScoutSemiAutoBot : public virtual JumpBot, public virtual ScoutBot, public virtual SemiAutoBot {
public:
    JumpScoutSemiAutoBot(const string& name, int startX, int startY, int w, int h, Battlefield* battlefield)
        : GenericRobot(name, startX, startY, w, h, battlefield),
          JumpBot(name, startX, startY, w, h, battlefield),
          ScoutBot(name, startX, startY, w, h, battlefield),
          SemiAutoBot(name, startX, startY, w, h, battlefield) {}
    void displayStats() const override {
        cout << "Upgrade: Jump + Scout + SemiAuto" << endl;
        JumpBot::displayStats();
        ScoutBot::displayStats();
        SemiAutoBot::displayStats();
    }
};

// Jump + Scout + ThirtyShot
class JumpScoutThirtyShotBot : public virtual JumpBot, public virtual ScoutBot, public virtual ThirtyShotBot {
public:
    JumpScoutThirtyShotBot(const string& name, int startX, int startY, int w, int h, Battlefield* battlefield)
        : GenericRobot(name, startX, startY, w, h, battlefield),
          JumpBot(name, startX, startY, w, h, battlefield),
          ScoutBot(name, startX, startY, w, h, battlefield),
          ThirtyShotBot(name, startX, startY, w, h, battlefield) {}
    void displayStats() const override {
        cout << "Upgrade: Jump + Scout + ThirtyShot" << endl;
        JumpBot::displayStats();
        ScoutBot::displayStats();
        ThirtyShotBot::displayStats();
    }
};

// Jump + LongShot + Scout
class JumpLongShotScoutBot : public virtual JumpBot, public virtual LongShotBot, public virtual ScoutBot {
public:
    JumpLongShotScoutBot(const string& name, int startX, int startY, int w, int h, Battlefield* battlefield)
        : GenericRobot(name, startX, startY, w, h, battlefield),
          JumpBot(name, startX, startY, w, h, battlefield),
          LongShotBot(name, startX, startY, w, h, battlefield),
          ScoutBot(name, startX, startY, w, h, battlefield) {}
    void fire(Battlefield* battlefield, int x, int y) override {
        LongShotBot::fire(x, y);
    }
    void displayStats() const override {
        cout << "Upgrade: Jump + LongShot + Scout" << endl;
        JumpBot::displayStats();
        LongShotBot::displayStats();
        ScoutBot::displayStats();
    }
};

// Jump + LongShot + Track
class JumpLongShotTrackBot : public virtual JumpBot, public virtual LongShotBot, public virtual TrackBot {
public:
    JumpLongShotTrackBot(const string& name, int startX, int startY, int w, int h, Battlefield* battlefield)
        : GenericRobot(name, startX, startY, w, h, battlefield),
          JumpBot(name, startX, startY, w, h, battlefield),
          LongShotBot(name, startX, startY, w, h, battlefield),
          TrackBot(name, startX, startY, w, h, battlefield) {}
    void fire(Battlefield* battlefield, int x, int y) override {
        LongShotBot::fire(x, y);
    }
    void displayStats() const override {
        cout << "Upgrade: Jump + LongShot + Track" << endl;
        JumpBot::displayStats();
        LongShotBot::displayStats();
        TrackBot::displayStats();
    }
};

// Jump + SemiAuto + Scout
class JumpSemiAutoScoutBot : public virtual JumpBot, public virtual SemiAutoBot, public virtual ScoutBot {
public:
    JumpSemiAutoScoutBot(const string& name, int startX, int startY, int w, int h, Battlefield* battlefield)
        : GenericRobot(name, startX, startY, w, h, battlefield),
          JumpBot(name, startX, startY, w, h, battlefield),
          SemiAutoBot(name, startX, startY, w, h, battlefield),
          ScoutBot(name, startX, startY, w, h, battlefield) {}
    void displayStats() const override {
        cout << "Upgrade: Jump + SemiAuto + Scout" << endl;
        JumpBot::displayStats();
        SemiAutoBot::displayStats();
        ScoutBot::displayStats();
    }
};

// Jump + SemiAuto + Track
class JumpSemiAutoTrackBot : public virtual JumpBot, public virtual SemiAutoBot, public virtual TrackBot {
public:
    JumpSemiAutoTrackBot(const string& name, int startX, int startY, int w, int h, Battlefield* battlefield)
        : GenericRobot(name, startX, startY, w, h, battlefield),
          JumpBot(name, startX, startY, w, h, battlefield),
          SemiAutoBot(name, startX, startY, w, h, battlefield),
          TrackBot(name, startX, startY, w, h, battlefield) {}
    void displayStats() const override {
        cout << "Upgrade: Jump + SemiAuto + Track" << endl;
        JumpBot::displayStats();
        SemiAutoBot::displayStats();
        TrackBot::displayStats();
    }
};

// Jump + ThirtyShot + Scout
class JumpThirtyShotScoutBot : public virtual JumpBot, public virtual ThirtyShotBot, public virtual ScoutBot {
public:
    JumpThirtyShotScoutBot(const string& name, int startX, int startY, int w, int h, Battlefield* battlefield)
        : GenericRobot(name, startX, startY, w, h, battlefield),
          JumpBot(name, startX, startY, w, h, battlefield),
          ThirtyShotBot(name, startX, startY, w, h, battlefield),
          ScoutBot(name, startX, startY, w, h, battlefield) {}
    void displayStats() const override {
        cout << "Upgrade: Jump + ThirtyShot + Scout" << endl;
        JumpBot::displayStats();
        ThirtyShotBot::displayStats();
        ScoutBot::displayStats();
    }
};

// Jump + ThirtyShot + Track
class JumpThirtyShotTrackBot : public virtual JumpBot, public virtual ThirtyShotBot, public virtual TrackBot {
public:
    JumpThirtyShotTrackBot(const string& name, int startX, int startY, int w, int h, Battlefield* battlefield)
        : GenericRobot(name, startX, startY, w, h, battlefield),
          JumpBot(name, startX, startY, w, h, battlefield),
          ThirtyShotBot(name, startX, startY, w, h, battlefield),
          TrackBot(name, startX, startY, w, h, battlefield) {}
    void displayStats() const override {
        cout << "Upgrade: Jump + ThirtyShot + Track" << endl;
        JumpBot::displayStats();
        ThirtyShotBot::displayStats();
        TrackBot::displayStats();
    }
};


#endif
