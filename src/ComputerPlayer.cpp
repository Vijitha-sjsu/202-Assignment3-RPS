#include "ComputerPlayer.h"

ComputerPlayer::ComputerPlayer(Strategy* strategy) : strategy(strategy) {}

char ComputerPlayer::makeChoice() {
    return strategy->makeChoice();
}
