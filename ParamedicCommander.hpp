
#pragma once
#include "Paramedic.hpp"
#include <iostream>

namespace WarGame {
    class ParamedicCommander : public Paramedic {
    public:
        ParamedicCommander(int playerNum) : Paramedic(playerNum, 100, 200) {};

        void full_action(Board &board,
                         std::pair<int, int> placeOfSoldier) override;

    };
}
