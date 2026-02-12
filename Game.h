#ifndef GAME_H
#define GAME_H

#include <iostream>
#include <random>
#include <fstream>
#include <tuple>
#include <sstream>

#include "Level.h"
#include "Mario.h"

using namespace std;

class Game {
    public:
        Game();
        Game(int numLevels);
        virtual ~Game();
        void makeLevels(int numRows, int coinPercentage, int nothingPercentage, int koopaPercentage, int goombaPercentage, int mushroomPercentage);
        void placeMario();
        void printLevels();
        Level** getLevelGrid();
        
    private:
	    int m_numLevels;
        Level **levelGrid;

};

#endif