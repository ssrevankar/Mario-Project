#include "Level.h"
#include "Mario.h"
#include <iostream>
#include <stdlib.h>

// Once the file is read, a world with the appropriate number of levels is constructed.
// Each level should be populated using the specifications provided.
// In addition, a level boss should be placed randomly, as well as a warp pipe (for all but the last level).
// Mario is placed at a random position in the first level with PL0 and the simulation begins until the game is won or lost.

// method for creating grid
// (dimension of grid given by user input)
// overloaded constructor

Level::Level() {
    m_rows = 0;
    m_levelNum = 0;
}

Level::Level(int numRows, int levelNum) {
    m_rows = numRows;
    m_levelNum = levelNum;
}

Level::~Level() {
    for(int i = 0; i < m_rows; ++i){
        delete [] grid[i];
    }
    delete [] grid;
}

void Level::initializeGrid() {

    grid = new char* [m_rows];

    for (int i = 0; i < m_rows; ++i){ //making a row x column grid
        grid[i] = new char[m_rows];
    }
    
    
    for (int iRow = 0; iRow < m_rows; iRow++)
	{
		for (int iColumn = 0; iColumn < m_rows; iColumn++ )
		{
			/*?? assign 'x' (empty space) to all element in 2-D array */
			grid[iRow][iColumn] = 'x';

		}
	}
}


char Level::getChar(int row, int column) {
    return grid[row][column];
}

// method for populating grid
// for COINS
// void Level::placeCoin(int numRows, float percentageCoins) {
//     int counter = 0;
//     bool emptyFound = false;
//     int numPlacestoPut = (numRows*numRows) * (percentageCoins / 100); // FIND A WAY TO ROUND IT TO WHOLE NUMBER
//     while (counter <= numPlacestoPut) {
//         // whatever goes here to place the coin on a random position in the grid (a method called chooseCoinPosition ???)
//         // choose a random position (0 to numRows-1 for row and column)

//         while (emptyFound == false) {
//             // find random position
//             tie(int randomRow, int randomColumn) = findRandom(numRows);

//             // check if position is occupied or not
//             if (this->a_cGrid[randomRow][randomColumn] == 'x') {
//                 // add coin to position in [randomRow] [randomColumn]
//                 this->a_cGrid[randomRow][randomColumn] == 'c';
//                 // add to counter
//                 counter++;
//                 emptyFound = true;
//             }

        
//         // if position is not occupied, place the coin
//         // if position is occupied, loop again
        
//         }
        
//     }
// }

// tuple<int, int> Level::findRandom (int numRows) {
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

void Level::randomGrid(int coinPercentage, int nothingPercentage, int koopaPercentage, int goombaPercentage, int mushroomPercentage) {

    int coinNum = coinPercentage;
    int nothingNum = coinNum + nothingPercentage;
    int koopaNum = nothingNum + koopaPercentage;
    int goombaNum = koopaNum + goombaPercentage;
    int mushroomNum = goombaNum + mushroomPercentage;

    bool bossPlaced = false;
    bool warppipePlaced = false;
    
    for (int iRow = 0; iRow < m_rows; ++iRow){ //loops through each spot in grid
        for (int iColumn = 0; iColumn < m_rows; ++iColumn){
            int randomSpace = rand()%100;
            if (randomSpace > 0 && randomSpace <= coinNum) {
                grid[iRow][iColumn] = 'c';
            } else if (randomSpace <= nothingNum) {
                if (!bossPlaced) {
                    grid[iRow][iColumn] = 'b';
                    bossPlaced = true;
                } else if (!warppipePlaced) {
                    grid[iRow][iColumn] = 'w';
                    warppipePlaced = true;
                }
            } else if (randomSpace <= koopaNum) {
                grid[iRow][iColumn] = 'k';
            } else if (randomSpace <= goombaNum) {
                grid[iRow][iColumn] = 'g';
            } else if (randomSpace <= mushroomNum) {
                grid[iRow][iColumn] = 'm';
            }
        }
    }
}

void Level::printGrid() {
    // creating new file

    // ofstream OutputFile("log.txt");
    ofstream OutputFile;
    OutputFile.open("log.txt", ios_base::app);

    for (int iRow = 0; iRow < m_rows; ++iRow) {
        OutputFile << endl;
        for (int iColumn = 0; iColumn < m_rows; ++iColumn) {
            OutputFile << grid[iRow][iColumn];
        }
    }

    OutputFile << endl << "==========" << endl;;

    OutputFile.close();
}

// void Level::printString(string stringLine) {
//     ofstream OutputFile;
//     OutputFile.open("log.txt", ios_base::app);
//     OutputFile << stringLine << endl;
//     OutputFile.close();
    
// }

char Level::placeMarioRandomly(int randomRow, int randomColumn) {
    // int randomRow = 0;
	  // int randomColumn = 0;
    
    // std::tie(randomRow, randomColumn) = placeMario();

    char originalChar = grid[randomRow][randomColumn];

    cout << "Original character: " << originalChar << endl;
    
    grid[randomRow][randomColumn] = 'H';

    return originalChar;

}

//     bool marioPlaced = false;
    
//     while (!marioPlaced) {
//         for (int iRow = 0; iRow < m_rows; ++iRow) { //loops through each spot in grid
//             for (int iColumn = 0; iColumn < m_rows; ++iColumn) {
//                 if (grid[iRow][iColumn] == 'x') {
//                     grid[iRow][iColumn] == 'H';
//                     marioPlaced = true;
//                 }
//             }
//         }
//     }
    
    
// }

void Level::getLevelNum() {
    ofstream OutputFile;
    OutputFile.open("log.txt", ios_base::app);
    OutputFile << "Level: " << m_levelNum << "." << endl;
    OutputFile.close();
}


char Level::moveMario(bool marioLost, int originalRow, int originalColumn, int randomRow, int randomColumn, char previousChar) {
    
    if (previousChar == 'c' || previousChar == 'm' || !marioLost) {
      this->grid[originalRow][originalColumn] = 'x';

    } else {
      this->grid[originalRow][originalColumn] = previousChar;
    }


    // // Mario Wins
    // if (marioLost) {
    //     this->grid[originalRow][originalColumn] = 'x';
    // } 
    

    // char originalChar = grid[originalRow][originalColumn];
    char originalChar = grid[randomRow][randomColumn];

    // cout << "Original character: " << originalChar << endl; // DELETE LATER
    
    // this->grid[originalRow][originalColumn] = 'x';
    this->grid[randomRow][randomColumn] = 'H';


    return originalChar;
}


// Mario interacts with environment


// int main () {

//     // start of level
//     Level levelTest(4, 1);
//     levelTest.initializeGrid();
//     levelTest.randomGrid(20, 20, 20, 20, 20);

//     levelTest.printGrid();

//     // place Mario in grid
//     Mario marioTest;
//     // marioTest.placeMario(4);

//     int marioRow;
//     int marioColumn;
//     tie(marioRow, marioColumn) = marioTest.placeMario(4);

//     char originalChar = levelTest.placeMarioRandomly(marioRow, marioColumn);
//     levelTest.printGrid();

   
//     // Mario chooses a random direction to move to
//     for (int i = 0; i < 10; ++i)
//     {
      
//       levelTest.getLevelNum();
//       marioTest.getMarioCoordinates();
//       marioTest.getPowerLevel();
//       marioTest.interactWithEnvironment(originalChar);

//       marioTest.getNumLives();
//       marioTest.getNumCoins();

//       // originalChar = levelTest.getChar(marioRow,marioColumn);

//       // Resassigning
//       marioRow = marioTest.m_marioRow;
//       marioColumn  = marioTest.m_marioColumn;
      

//       cout << originalChar << endl;

//       int newRow;
//       int newColumn;

//       bool marioLost = false;
//       tie(newRow, newColumn) = marioTest.chooseDirection(4);

//       // cout << newRow << endl;
//       // cout << newColumn << endl;
//       // cout << " " << endl;

//       originalChar = levelTest.moveMario(marioLost, marioRow, marioColumn, newRow, newColumn);
//       levelTest.printGrid();
//     }

//     return 0;
// }



