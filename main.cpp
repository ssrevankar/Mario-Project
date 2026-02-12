#include "Game.h"
#include "Level.h"
#include "Mario.h"
#include "Goomba.h"
#include "Koopa.h"
#include "Boss.h"

int main (int argc, char* argv[]) {

    int numLevels, numRows, numLives, coinPercentage, nothingPercentage, koopaPercentage, goombaPercentage, mushroomPercentage;
    bool marioLost;
    bool gameLost = false;
    bool levelWon = false;

    // string inputFile;
    // cout << "Enter the name of the input file: ";
    // cin >> inputFile;

    string inputFile = argv[1];

    ifstream inputNumbers;
    string line;

    cout << "Opening original text file." << endl;
    inputNumbers.open(inputFile);

   if (!inputNumbers.is_open()) {
      cout << "Could not open file." << endl;
   }

    // Read file and assign values to variables
    while (getline(inputNumbers, line)) {
      // Assign first line vlalue to numLevels
      numLevels = stoi(line);
      // Assign second line value to numRows
      getline(inputNumbers, line);
      numRows = stoi(line);
      // Assign third line value to numLives
      getline(inputNumbers, line);
      numLives = stoi(line);
      // Assign fourth line value to coinPercentage
      getline(inputNumbers, line);
      coinPercentage = stoi(line);
      // Assign fifth line value to nothingPercentage
      getline(inputNumbers, line);
      nothingPercentage = stoi(line);
      // Assign sixth line value to koopaPercentage
      getline(inputNumbers, line);
      koopaPercentage = stoi(line);
      // Assign seventh line value to goombaPercentage
      getline(inputNumbers, line);
      goombaPercentage = stoi(line);
      // Assign eighth line value to mushroomPercentage
      getline(inputNumbers, line);
      mushroomPercentage = stoi(line);
    }
    

    // Print out all of the variables with the name of the variables
    cout << "numLevels: " << numLevels << endl;
    cout << "numRows: " << numRows << endl;
    cout << "numLives: " << numLives << endl;
    cout << "coinPercentage: " << coinPercentage << endl;
    cout << "nothingPercentage: " << nothingPercentage << endl;
    cout << "koopaPercentage: " << koopaPercentage << endl;
    cout << "goombaPercentage: " << goombaPercentage << endl;
    cout << "mushroomPercentage: " << mushroomPercentage << endl;


   if (!inputNumbers.eof()) {
      cout << "Input failure before reaching end of file." << endl;
   }

    inputNumbers.close();

    Game gameTest(numLevels);
    Mario marioTest;
    gameTest.makeLevels(numRows, coinPercentage, nothingPercentage, koopaPercentage, goombaPercentage, mushroomPercentage);
    gameTest.printLevels();

    int marioRow = 0;
    int marioColumn = 0;

    ofstream OutputFile("log.txt");

    tie(marioRow, marioColumn) = marioTest.placeMario(numRows);
    cout << "Mario is starting in position: (" << marioRow << ", " << marioColumn << ")" << endl;

    Level **levelGrid = gameTest.getLevelGrid();

    for (int i = 0; i < numLevels; i++) {
        cout << "ITERATION NO. " << i << endl;
        Level* levelTest = levelGrid[i];


        cout << "ACCESSED GRID" << endl;

        char originalChar = levelTest->placeMarioRandomly(marioRow, marioColumn);
        levelTest->printGrid();

    
        // Mario chooses a random direction to move to
        // for (int i = 0; i < 20; ++i) {
        while (!gameLost && !levelWon) {
        // while (!gameLost) {
            
            cout << "NEW DIRECTION" << endl;

            levelTest->getLevelNum();
            marioTest.getMarioCoordinates();
            marioTest.getPowerLevel();
            marioLost = marioTest.interactWithEnvironment(originalChar);

            if (marioLost == true) {
                gameLost = marioTest.checkGameLost();
            }


            cout << "ACCESSING LIVES AND COINS" << endl;
            marioTest.getNumLives();
            marioTest.getNumCoins();

        // originalChar = levelTest->getChar(marioRow,marioColumn);

        // Resassigning

       
            if (marioTest.checkLevelWon() == true) {
                levelWon = true;
                // break;
            }

            cout << "REASSIGNING ROW AND COLUMN" << endl;
            marioRow = marioTest.getMarioRow();
            marioColumn  = marioTest.getMarioColumn();

            // if (gameLost == true) {
            //     ofstream OutputFile;
            //     OutputFile.open("log.txt", ios_base::app);
            //     OutputFile << "YOU LOSE!!!";
            //     OutputFile.close();
            // }

            // if (gameWon == true) {
            //     ofstream OutputFile;
            //     OutputFile.open("log.txt", ios_base::app);
            //     OutputFile << "YOU WIN!!!";
            //     OutputFile.close();
            // }
        

            // cout << originalChar << endl;

            int newRow;
            int newColumn;

            //   bool marioLost = true;

            tie(newRow, newColumn) = marioTest.chooseDirection(numRows);

            // cout << newRow << endl;
            // cout << newColumn << endl;
            // cout << " " << endl;

            char previousChar = originalChar;

            cout << "MOVE MARIO" << endl;
            originalChar = levelTest->moveMario(marioLost, marioRow, marioColumn, newRow, newColumn, previousChar);
            cout << "STOPPED MARIO" << endl;
            levelTest->printGrid();
            cout << "PRINT GRID" << endl;
        }
        continue;

    }

    
    // Level* levelTest = levelGrid[0];
    // Level* levelTest = gameTest.levelGrid[0];

    


    // for loop that goes LevelList
    //    while loop that goes through the level until mario loses health, boss is beaten, warp pipe
    //    is reached, or mario runs out of lives

    return 0;
}