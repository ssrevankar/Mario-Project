#include "Game.h"
#include "Level.h"
#include "Mario.h"

// START OF GAME

    // make levels based on number of levels given in user input
        // make a for loop to make levels until loop reaches numLevels
        // BUILD AN ARRAY OF LEVELS

Game::Game() {
    m_numLevels = 0;
}

Game::Game(int numLevels) {
    m_numLevels = numLevels;
}

Game::~Game() {
    for(int i = 0; i < m_numLevels; ++i){
        delete [] levelGrid[i];
    }
}

void Game::makeLevels (int numRows, int coinPercentage, int nothingPercentage, int koopaPercentage, int goombaPercentage, int mushroomPercentage) {
    levelGrid = new Level* [m_numLevels];     // created an array of Level objects with numLevels levels
    // Level levelGrid[m_numLevels];
    for (int i = 0; i < m_numLevels; ++i) {
        // Level *level = new Level(numRows);   // create Level object using overlaoded constructor (using dimension from user input)
        Level* level = new Level(numRows, i);
        // Level level(numRows);
        level->initializeGrid();
        level->randomGrid(coinPercentage, nothingPercentage, koopaPercentage, goombaPercentage, mushroomPercentage);
        // level->printGrid();
        levelGrid[i] = level;   // add new Level object to index of array
    }
}

void Game::printLevels() {

    for (int i = 0; i < m_numLevels; ++i) {
        levelGrid[i]->printGrid();
    }

}

Level** Game::getLevelGrid() {
    return levelGrid;
}

// void Game::placeMario() {
//     levelGrid[i]
// }

// void Game::placeMario() {
//     levelGrid[0].placeMarioRandomly(); // NOT SURE IF THIS WORKS
// }


// void Game::processFile(string inputFile) {
//     ifstream inputNumbers;
//     string line;

//     cout << "Opening original text file." << endl;
//     inputNumbers.open(inputFile);

//    if (!inputNumbers.is_open()) {
//       cout << "Could not open file." << endl;
//    }

//    int numLevels;
//    while (getline(inputNumbers, numLevels)) {
//        istringstream ss(line);

//         int numLevels, numRows, numLives, coinPercentage, nothingPercentage, koopaPercentage, goombaPercentage, mushroomPercentage;

//         ss >> numLevels >> numRows >> numLives >> coinPercentage >> nothingPercentage >> koopaPercentage >> goombaPercentage >> mushroomPercentage;
//    }

// //    inputNumbers >> originalText;

// //    while (getline(InputText, originalText)) {
// //       cout << "Original English sentence: " << originalText << endl;
// //       InputText >> originalText;
// //    }

//     // while (getline(inputNumbers, line)) {
//     // std::istringstream iss(line);
//     // int a, b;
//     // if (!(iss >> a >> b)) { break;
//     // }

// }

//    if (!InputText.eof()) {
//       cout << "Input failure before reaching end of file." << endl;
//    }

//    cout << "Closing file." << endl;

//    InputText.close();
// }

    


 

    // read user input for dimension
    // Level1.makeGrid(dimension of grid)???

    // read user input for number of lives
    // create lives objects or simply add to a variable???

    // populate grid
    // placeRandomly method that places the different things at random places???
    // (has to read in probability too)
    // make the objects in this class or in level???
    // Level1.placerandomly(object, probability) ???

    // place boss
    // place warp pipe (EXCEPT FOR LAST LEVEL)
    // place Mario in first level


    
// Direction chosen randomly
// Mario's position in the grid changes



// IGNORE

   // (make level objects)
    // (make empty level objects using default constructor???)
    // (or make empty grid using first user input with overloaded constructor???)