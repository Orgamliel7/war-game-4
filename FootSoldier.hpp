
#pragma once
#include "Soldier.hpp"
#include <iostream>
#include <limits>

namespace WarGame {
    class FootSoldier : public Soldier {

    public:

        FootSoldier(int playerNum) : Soldier(playerNum, 10, 100) {
            std::cout << "Foot Soldier built for player:" << playerNum << std::endl;
        };

        FootSoldier(int playerNum, int damage_per_act, int health_points) : Soldier(playerNum, damage_per_act,
                                                                                    health_points) {};

        void
        basic_action(Board &board, std::pair<int, int> placeOfSoldier) override;

        void full_action(Board &board,
                         std::pair<int, int> placeOfSoldier) override
        {
            // apply basic full_action for foot soldier
            this->basic_action(board, placeOfSoldier);
        }

    };
}
