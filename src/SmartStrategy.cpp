// src/SmartStrategy.cpp
#include "../include/SmartStrategy.h"
#include <algorithm>
#include <iostream>
#include <random>

SmartStrategy::SmartStrategy() {
    loadFrequencies();
}

char SmartStrategy::makeChoice() {
    if (recentChoices.size() < N - 1) {
        // Not enough data to predict; use a random choice
        std::random_device rd;
        std::mt19937 gen(rd());
        std::uniform_int_distribution<> distrib(0, 2);
        char choices[] = {'R', 'P', 'S'};
        return choices[distrib(gen)];
    } else {
        return predictNextMove(); // Predict based on history
    }
}

void SmartStrategy::updateHistory(char humanChoice, char computerChoice) {
    recentChoices.push_back(humanChoice);
    recentChoices.push_back(computerChoice);
    // Keep only the last N choices
    while (recentChoices.size() > N) {
        recentChoices.erase(recentChoices.begin());
    }

    // Update frequencies
    std::string sequence = getRecentSequence();
    choiceFrequencies[sequence]++;
}

void SmartStrategy::loadFrequencies() {
    fileManager.loadFrequencies("frequencies.txt", choiceFrequencies);
}

void SmartStrategy::saveFrequencies() {
    fileManager.saveFrequencies("frequencies.txt", choiceFrequencies);
}

std::string SmartStrategy::getRecentSequence() {
    // Convert the last N-1 choices to a string (exclude the very last choice)
    return std::string(recentChoices.begin(), recentChoices.end() - 1);
}

char SmartStrategy::predictNextMove() {
    std::string recentSequence = getRecentSequence(); // Get the last N-1 choices as a string
    char mostProbableChoice = 'R'; // Default choice
    int highestFrequency = 0;

    // Iterate over choiceFrequencies to find the sequence with the highest frequency
    // that starts with the recentSequence
    for (const auto& pair : choiceFrequencies) {
        std::string sequence = pair.first.substr(0, pair.first.size() - 1);
        char choice = pair.first.back();
        int frequency = pair.second;

        if (sequence == recentSequence && frequency > highestFrequency) {
            highestFrequency = frequency;
            mostProbableChoice = choice;
        }
    }

    // Predict the human player's next move based on the most frequent past sequence
    // and choose the winning move against it
    if (highestFrequency == 0) {
        // If no matching sequence found, make a random choice
        std::random_device rd;
        std::mt19937 gen(rd());
        std::uniform_int_distribution<> distrib(0, 2);
        char choices[] = {'R', 'P', 'S'};
        return choices[distrib(gen)];
    } else {
        // Choose the winning move against the predicted move
        if (mostProbableChoice == 'R') return 'P'; // Paper covers rock
        if (mostProbableChoice == 'P') return 'S'; // Scissors cut paper
        if (mostProbableChoice == 'S') return 'R'; // Rock crushes scissors
    }

    // Fallback, should not be reached due to the logic covering all cases
    return 'R';
}

