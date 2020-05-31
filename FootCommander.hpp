
#pragma once
#include "FootSoldier.hpp"
#include <iostream>


namespace WarGame {
    class Board;
    class FootCommander : public FootSoldier {
    public:
        FootCommander(int playerNum) : FootSoldier(playerNum, 20, 150) {
            std::cout << "Foot Commander built for player:" << playerNum << std::endl;
        };

        void full_action(Board &board,
                         std::pair<int, int> placeOfSoldier) override;

    };
}
