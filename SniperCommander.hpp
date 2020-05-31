
#pragma once
#include "Sniper.hpp"
#include <iostream>
namespace WarGame {
    class Board;
    class SniperCommander : public Sniper {
    public:
        SniperCommander(int playerNum) : Sniper(playerNum, 100, 120) {};

        void full_action(Board &board,
                         std::pair<int, int> placeOfSoldier) override;
    };
}
