// src/GameEngine.cpp
#include "../include/GameEngine.h"
#include "../include/HumanPlayer.h"
#include "../include/ComputerPlayer.h"
#include <iostream>

// Constructor
GameEngine::GameEngine(Player* human, Strategy* strategy)
    : humanPlayer(human), computerPlayer(nullptr), strategy(strategy), scoreHuman(0), scoreComputer(0) {
    this->computerPlayer = new ComputerPlayer(strategy);
}

// Destructor
GameEngine::~GameEngine() {
    delete humanPlayer;
    delete computerPlayer;
}

// The method to play one round of the game
char GameEngine::playRound() {
    char humanChoice = humanPlayer->makeChoice();
    strategy->updateState(humanChoice);
    char computerChoice = computerPlayer->makeChoice();

    std::cout << "Human: " << humanChoice << " vs Computer: " << computerChoice << std::endl;

    // Determine the winner
    if ((humanChoice == 'R' && computerChoice == 'S') ||
        (humanChoice == 'S' && computerChoice == 'P') ||
        (humanChoice == 'P' && computerChoice == 'R')) {
        std::cout << "Human wins this round!" << std::endl;
        scoreHuman++;
        return 'H'; // Human wins
    } else if (humanChoice == computerChoice) {
        std::cout << "Round tied!" << std::endl;
        return 'T'; // Tie
    } else {
        std::cout << "Computer wins this round!" << std::endl;
        scoreComputer++;
        return 'C'; // Computer wins
    }
}

// The method to play the game for 20 rounds
void GameEngine::playGame() {
    std::cout << "Starting the Rock-Paper-Scissors game!" << std::endl;

    for (int round = 1; round <= 20; ++round) {
        std::cout << "Round " << round << std::endl;
        playRound();
    }

    std::cout << "Final score - Human: " << scoreHuman << " Computer: " << scoreComputer << std::endl;

    if (scoreHuman > scoreComputer) {
        std::cout << "Human wins the game!" << std::endl;
    } else if (scoreHuman < scoreComputer) {
        std::cout << "Computer wins the game!" << std::endl;
    } else {
        std::cout << "The game is a tie!" << std::endl;
    }
}
