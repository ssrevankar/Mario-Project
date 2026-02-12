#include "Mario.h"
#include "Level.h"
#include <ctime>


Mario::Mario() {
    m_numCoins = 0;
    m_numLives = 3;
    m_powerLevel = 0;
    m_marioRow = 0;
    m_marioColumn = 0; 
    m_numDefeatedEnemies = 0;
    m_levelWon = false;
}

Mario::Mario(int numCoins, int numLives, int powerLevel) {
    m_numCoins = numCoins;
    m_numLives = numLives;
    m_powerLevel = powerLevel;
    // place Mario at random spot on the grid of level 1
}

int Mario::getRow() {
    return m_marioRow;
}
 
int Mario::getColumn() {
    return m_marioColumn;
}

tuple<int, int> Mario::placeMario(int numRows) {
    srand (time(NULL));
    int randomRow = rand()%numRows;
    int randomColumn = rand()%numRows;

    m_marioRow = randomRow;
    m_marioColumn = randomColumn;

    // cout << "Mario is starting in position (" << m_marioRow << ", " << m_marioColumn << ")." << endl;

    // ofstream OutputFile("log.txt"); // CHANGE TO BOTTOM ONCE I ADD ALL THE PRINTING STUFF IN THE GAME!!!

    ofstream OutputFile;
    OutputFile.open("log.txt", ios_base::app);

    OutputFile << "==========" << endl;

    OutputFile << "Mario is starting in position (" << m_marioRow << ", " << m_marioColumn << ")." << endl;

    OutputFile << "==========" << endl;

    OutputFile.close();

    std::tuple<int, int> tupleCoord(randomRow, randomColumn);
	return tupleCoord;
}

tuple<int, int> Mario::chooseDirection(int numRows) {
    // srand(time(0));
    int randomDirection = rand()%100;
    cout << randomDirection << endl;
    int newRow = 0;
    int newColumn = 0;

    cout << numRows << endl;

    if (randomDirection > 0 && randomDirection <= 25) {
        if (m_marioColumn < numRows-1) {
            // move Mario right
            m_marioColumn += 1;
        } else {
            // Mario's column position is at 0
            m_marioColumn = 0;
        }

    } else if (randomDirection <= 50) {
        if (m_marioColumn > 0) {
            // move Mario left
            m_marioColumn -= 1;
        } else {
            // Mario's column position is at 0
            m_marioColumn = numRows-1;
        }
    } else if (randomDirection <= 75) {
        if (m_marioRow > 0) {
            // move Mario up
            m_marioRow -= 1;
        } else {
            // Mario's row position is at 0
            m_marioRow = numRows-1;
        }
    } else if (randomDirection <= 100) {
        if (m_marioRow < numRows-1) {
            // move Mario down
            m_marioRow += 1;
        } else {
            // Mario's row position is at 0
            m_marioRow = 0;
        }
    }
    // m_marioRow = newRow;
    // m_marioColumn = newColumn;
    cout << m_marioColumn << endl;
    cout << m_marioRow << endl;
    cout << endl;
    std::tuple<int, int> tupleCoord(m_marioRow, m_marioColumn);
    return tupleCoord;

}

bool Mario::interactWithEnvironment(char originalChar) {
    bool marioLost = false;
    
    if (originalChar == 'c') {
        // add coin to Mario
        addCoin();
    } else if (originalChar == 'x') {
        // nothing (but still print)
        doNothing();
    } else if (originalChar == 'm') {
        // Mario's power level goes up
        powerUp();
    } else if (originalChar == 'g') {
        // Mario fights Goomba
        Goomba goombaTest;
        marioLost = goombaTest.fightGoomba();

        if (marioLost == false) {
            m_numDefeatedEnemies++;
        }

    } else if (originalChar == 'k') {
        // Mario fights Koopa
        Koopa KoopaTest;
        marioLost = KoopaTest.fightKoopa();

        if (marioLost == false) {
            m_numDefeatedEnemies++;
        }

    } else if (originalChar == 'b') {
        // Mario fights boss
        // loop until Mario wins against the boss or he loses the game
        Boss BossTest;
        marioLost = BossTest.fightBoss();

        if (marioLost == false) {
            m_numDefeatedEnemies++;
            m_levelWon = true;
        }

    } else if (originalChar == 'w') {
        // Mario goes to the next level
        m_levelWon = true;
    }

    return marioLost;
}

bool Mario::checkGameLost() {
    bool gameLost = false;
    if (m_powerLevel > 0) {
        m_powerLevel--;
    } else {
        if (m_numLives > 0) {
            m_numLives--;
            m_numDefeatedEnemies = 0;
            m_powerLevel = 0;
        } else {
            gameLost = true;
        }

    }

    return gameLost;
}


bool Mario::checkLevelWon() {
    bool levelWon;
    
    if (m_levelWon == true) {
        levelWon = true;
    } else {
        levelWon = false;
    }

    return levelWon;
}


void Mario::checkDefeatedEnemies() {
    if (m_numDefeatedEnemies == 7) {
        m_numLives++;
        m_numDefeatedEnemies = 0;
    }
}

void Mario::addCoin() {
    m_numCoins++;
    if (m_numCoins == 20) {
        m_numLives++;
    }
    ofstream OutputFile;
    OutputFile.open("log.txt", ios_base::app);
    OutputFile << "Mario collected a coin." << endl;
    OutputFile.close();
}

void Mario::doNothing() {
    ofstream OutputFile;
    OutputFile.open("log.txt", ios_base::app);
    OutputFile << "Mario visited an empty space." << endl;
    OutputFile.close();
}

void Mario::powerUp() {
    m_powerLevel++;
    ofstream OutputFile;
    OutputFile.open("log.txt", ios_base::app);
    OutputFile << "Mario ate a mushroom." << endl;
    OutputFile.close();
}

// void Mario::fightGoomba() {
//     // fight Goomba
//     ofstream OutputFile;
//     OutputFile.open("log.txt", ios_base::app);
//     OutputFile << "Mario encountered a goomba and WON/LOST." << endl;
//     OutputFile.close();
// }

// void Mario::fightKoopa() {
//     // fight Koopa
//     ofstream OutputFile;
//     OutputFile.open("log.txt", ios_base::app);
//     OutputFile << "Mario encountered a koopa and WON/LOST" << endl;
//     OutputFile.close();
// }

void Mario::fightBoss() {
    // fight Boss
    ofstream OutputFile;
    OutputFile.open("log.txt", ios_base::app);
    OutputFile << "Mario encountered a boss and WON/LOST." << endl;
    OutputFile.close();
}

void Mario::warpToNextLevel() {
    // warp to the next level
    ofstream OutputFile;
    OutputFile.open("log.txt", ios_base::app);
    OutputFile << "Mario found a warp pipe." << endl;
    OutputFile.close();
}



void Mario::getNumCoins() {
    ofstream OutputFile;
    OutputFile.open("log.txt", ios_base::app);
    OutputFile << "Mario has " << m_numCoins << " coins." << endl;
    OutputFile.close();
}

void Mario::getNumLives() {
    ofstream OutputFile;
    OutputFile.open("log.txt", ios_base::app);
    OutputFile << "Mario has " << m_numLives << " lives left." << endl;
    OutputFile.close();
}

void Mario::getPowerLevel() {
    ofstream OutputFile;
    OutputFile.open("log.txt", ios_base::app);
    OutputFile << "Mario is at power level " << m_powerLevel << "." << endl;
    OutputFile.close();
}

void Mario::getMarioCoordinates() {
    ofstream OutputFile;
    OutputFile.open("log.txt", ios_base::app);
    OutputFile << "Mario is at position: (" << m_marioRow << ", " << m_marioColumn << ")." <<endl;
    OutputFile.close();
}



int Mario::getMarioRow() {
    return m_marioRow;
}

int Mario::getMarioColumn() {
    return m_marioColumn;
}



// Mario starts at a certain random position

// void Mario::placeMario(int numRows) {
//     bool emptyFound = false;

//     while (emptyFound == false) {
//         // find random position
//         tie(iRow, iColumn) = findRandom(numRows);

//         // check if position is occupied or not
//         if (grid[randomRow][randomColumn] == 'x') {
//             // add coin to position in [randomRow] [randomColumn]
//             grid[randomRow][randomColumn] == 'm';
//             // add to counter
//             counter++;
//             emptyFound = true;
//         }
        
//     }
// }

// tuple<int, int> Mario::findRandom (int numRows) {
//     int randomRow = 0;
//     int randomColumn = 0;

//     random_device randomDevice;

//     default_random_engine randomNumberGenerator(randomDevice());

//     uniform_int_distribution<int> uniformIntegerDistributionRows(0, (numRows - 1));

//     int randomRow = uniformIntegerDistributionRows(randomNumberGenerator);

//     uniform_int_distribution<int> uniformIntegerDistributionColumns(0, (numRows - 1));

//     int randomColumn = uniformIntegerDistributionColumns(randomNumberGenerator);


//     tuple<int, int> tupleCoord = make_tuple(randomRow, randomColumn);

// 	return tupleCoord;
// }




// Mario moves to a direction

// Mario interacts with the environment