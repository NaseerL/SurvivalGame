#ifndef PLAYER_H
#define PLAYER_H

#include <sstream>

using namespace std;

class Player {
    public:
    Player(int health,int hunger,int thirst,
            int x,int y);
    int getX() const;
    int getY() const;
    void setX(int newX);
    void setY(int newY);
    int getHunger() const;
    int getThirst() const;
    int getHealth() const;
    void setThirst(unsigned int t);
    void setHunger(unsigned int hu);
    void setHealth(unsigned int he);
    void newTurn();
    string printStats();
    bool isAlive() const;
    
    static const unsigned int DEFAULT_HEALTH = 10;
    static const unsigned int DEFAULT_HUNGER = 10;
    static const unsigned int DEFAULT_THIRST = 10;
    
    private:
    int health;
    int hunger;
    int thirst;
    int x;
    int y;
};

#endif