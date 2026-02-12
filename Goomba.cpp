#include "Goomba.h"

Goomba::Goomba() {

}

bool Goomba::fightGoomba() {
    // srand (time(NULL));
    int randomNumber = rand()%100;
    bool marioLost;

    ofstream OutputFile;
    OutputFile.open("log.txt", ios_base::app);
    
    if (randomNumber <= 80) {
        // Mario wins - keep going
        marioLost = false;
        OutputFile << "Mario encountered a goomba and WON." << endl;


    } else {
        // Mario loses - his power level is decreased by 1, the Goomba stays in the position, and Mario moves on.
        // If Mario loses while at PL0, a life is lost.
        // If Mario has another life, he continues at the same location, with PL0.
        // Otherwise, the simulation ends, and the game is lost.
        marioLost = true;
        OutputFile << "Mario encountered a goomba and LOST." << endl;
    }

    OutputFile.close();
    
    return marioLost;

}