// src/main.cpp
#include "../include/GameEngine.h"
#include "../include/HumanPlayer.h"
#include "../include/ComputerPlayer.h"
#include "../include/RandomStrategy.h"
#include "../include/SmartStrategy.h"
#include "../include/StrategyFactory.h"
#include <iostream>
#include <memory>

int main() {
    std::cout << "Choose strategy for computer player:\n";
    std::cout << "1. Random Strategy\n";
    std::cout << "2. Smart Strategy\n";
    std::cout << "Enter choice (1 or 2): ";
    int choice;
    std::cin >> choice;

    Strategy* strategy = StrategyFactory::createStrategy(choice);
	if (strategy == nullptr) {
		std::cerr << "Invalid choice. Exiting...\n";
		return 1;
	}

    HumanPlayer* human = new HumanPlayer();
    GameEngine game(human, strategy);

    game.playGame();

    // Cleanup
    delete strategy;
    delete human;

    return 0;
}
