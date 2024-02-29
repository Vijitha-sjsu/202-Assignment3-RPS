#ifndef COMPUTERPLAYER_H
#define COMPUTERPLAYER_H

#include "Strategy.h"
#include "Player.h"

class ComputerPlayer : public Player {
private:
    Strategy* strategy;
public:
    ComputerPlayer(Strategy* strategy);
    char makeChoice() override;
};

#endif // COMPUTERPLAYER_H
