#ifndef NEWROBOT_H
#define NEWROBOT_H

#include <string>
#include <vector>
#include "Battlefield.h"

using namespace std;

struct Position {
    int robotPositionX;
    int robotPositionY;
};

class Robot {
protected:
    string name;
    Position pos;
    int health;
    int shells;
    int lives;
    bool alive;
    int fieldWidth;
    int fieldHeight;
    bool hidden = false; // Indicates if the robot is hidden
    bool alive = true; // Indicates if the robot is alive

public:
    Robot(string n, int x, int y, int w, int h)
        : name(n), fieldWidth(w), fieldHeight(h) {
        pos.robotPositionX = x;
        pos.robotPositionY = y;
        health = 100;
        shells = 10;
        lives = 3;
        alive = true;
    }

    virtual ~Robot() {}

    virtual void think() = 0;
    virtual void look() = 0;
    virtual void move() = 0;
    virtual void fire() = 0;
    virtual void displayAction() = 0;

    string getName() const {
        return name;
    }

    Position getPosition() const {
        return pos;
    }

    bool isLives() const {
        return alive;
    }

    void takeDamage(int damage) {
        health -= damage;
        if (health <= 0) {
            lives--;
            if (lives <= 0) {
                alive = false;
            }
        }
    }
    void hide() { hidden = true; }
    void reveal() { hidden = false; }
    bool isHidden() const { return hidden; }
    
    // For upgrades
    virtual bool canUpgrade() const = 0;
    virtual void upgrade(const string& upgradeType) = 0;
    };

    class MovingRobot : public virtual Robot {
protected:
    int moveRange;
    int jumpCount;
    int hideCount;
    
public:
    MovingRobot(const string& name, int x, int y) 
        :  moveRange(1), jumpCount(0), hideCount(0) {}
    
    virtual void move(Battlefield& battlefield, int dx, int dy) = 0;
    virtual bool canJump() const { return jumpCount > 0; }
    virtual void jump(Battlefield& battlefield, int x, int y) = 0;
    virtual bool canHide() const { return hideCount > 0; }
    virtual void toggleHide() = 0;
};

class ShootingRobot : public virtual Robot {
protected:
    int shells;
    int fireRange;
    bool semiAuto;
    
public:
    ShootingRobot(const string& name, int x, int y) 
        : shells(10), fireRange(1), semiAuto(false) {}
    
    virtual bool canFire() const { return shells > 0; }
    virtual void fire(Battlefield& battlefield, int dx, int dy) = 0;
    virtual int getShells() const { return shells; }
};

class SeeingRobot : public virtual Robot {
protected:
    int visionRange;
    int scoutCount;
    int trackers;
    vector<pair<int, int>> trackedRobots;
    
public:
    SeeingRobot(const string& name, int x, int y) 
        : visionRange(1), scoutCount(0), trackers(0) {}
    
    virtual vector<pair<int, int>> look(Battlefield& battlefield, int dx, int dy) = 0;
    virtual bool canScout() const { return scoutCount > 0; }
    virtual void scout(Battlefield& battlefield) = 0;
    virtual bool canTrack() const { return trackers > 0; }
    virtual void track(Battlefield& battlefield, const string& targetName) = 0;
};
class ThinkingRobot : public virtual Robot {
protected:
    vector<string> upgrades;
    
public:
    ThinkingRobot(const string& name, int x, int y) ;
    
    virtual void analyze(Battlefield& battlefield) = 0;
    virtual void decideAction(Battlefield& battlefield) = 0;
    virtual vector<string> getAvailableUpgrades() const = 0;
};


#endif // NEWROBOT_H
