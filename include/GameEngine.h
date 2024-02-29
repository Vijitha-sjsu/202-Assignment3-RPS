// include/GameEngine.h
#ifndef GAMEENGINE_H
#define GAMEENGINE_H

#include "Player.h"
#include "Strategy.h"

class GameEngine {
private:
    Player* humanPlayer;
    Player* computerPlayer;
    Strategy* strategy;
    int scoreHuman;
    int scoreComputer;

    // Helper method to play a single round
    char playRound();

public:
    // Constructor and destructor
    GameEngine(Player* human, Strategy* strategy);
    ~GameEngine();

    // Method to play the game
    void playGame();

    // Additional methods as necessary
};

#endif // GAMEENGINE_H
