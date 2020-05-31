
#pragma once
#include "Soldier.hpp"
#include <iostream>

namespace WarGame {
    class Sniper : public Soldier {
    public:
        Sniper(int playerNum) : Soldier(playerNum, 50, 100) {};

        Sniper(int playerNum, int damage_per_act, int health_points) : Soldier(playerNum, damage_per_act,
                                                                               health_points) {};

        virtual void basic_action(Board &board,
                                  std::pair<int, int> placeOfSoldier) override;

        virtual void full_action(Board &board,
                                 std::pair<int, int> placeOfSoldier) override

        {
            this->basic_action(board, placeOfSoldier);
        }
    };
}
