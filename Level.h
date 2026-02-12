#ifndef LEVEL_H
#define LEVEL_H

#include <iostream>
#include <random>
#include <fstream>
#include <tuple>

#include "Mario.h"

using namespace std;

class Level {
    public:
        Level();
        Level(int numRows, int levelNum);
        virtual ~Level();
        void initializeGrid();
        void randomGrid(int coinPercentage, int nothingPercentage, int koopaPercentage, int goombaPercentage, int mushroomPercentage);
        void printGrid();
        char placeMarioRandomly(int randomRow, int randomColumn);
        void getLevelNum();
        char moveMario(bool marioLost, int originalRow, int originalColumn, int randomRow, int randomColumn, char previousChar);
        
        // void printString(string stringLine);
        // tuple<int, int> findRandom (int numRows);

        char getChar(int row, int column);
    private:
	    int m_rows;
        int m_levelNum;
        char **grid;

};

#endif