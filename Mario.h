// Mario has:
    // coins
    // lives
    // power
    // movement

// are these member variables???



// every 20 coins = 1 extra life
// (have to check after every movement)

#ifndef MARIO_H
#define MARIO_H

#include <iostream>
#include <tuple>
#include <fstream>
#include <stdlib.h>

#include "Level.h"
#include "Goomba.h"
#include "Koopa.h"
#include "Boss.h"

using namespace std;

class Mario {
    public:
        Mario();
        Mario(int numCoins, int numLives, int powerLevel);
        tuple<int, int> chooseDirection(int numRows);
        tuple<int, int> placeMario(int numRows);
        void addCoin();
        void doNothing();
        void powerUp();
        void fightGoomba();
        void fightKoopa();
        void fightBoss();
        void warpToNextLevel();

        bool interactWithEnvironment(char originalChar);

        void getNumCoins();
        void getNumLives();
        void getPowerLevel();
        void getMarioCoordinates();
        
        //Functions to access member variables
        int getRow();
        int getColumn();
        int getChar();

        int getMarioRow();
        int getMarioColumn();

        void checkDefeatedEnemies();
        bool checkGameLost();
        bool checkLevelWon();

    private:
        int m_numCoins;
        int m_numLives;
        int m_powerLevel;
        int m_marioRow;
        int m_marioColumn;

        int m_numDefeatedEnemies;

        bool m_levelWon;  
};

#endif
