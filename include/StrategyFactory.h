// include/StrategyFactory.h
#ifndef STRATEGY_FACTORY_H
#define STRATEGY_FACTORY_H

#include "RandomStrategy.h"
#include "SmartStrategy.h"

class StrategyFactory {
public:
    static Strategy* createStrategy(int choice) {
        switch (choice) {
            case 1:
                return new RandomStrategy();
            case 2:
                return new SmartStrategy();
            default:
                return nullptr;
        }
    }
};

#endif // STRATEGY_FACTORY_H
