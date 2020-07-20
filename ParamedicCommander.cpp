#include "ParamedicCommander.hpp"
#include <iostream>
#include "Board.hpp"

namespace WarGame {
    //  כמו חובש, אבל כשהוא זז, כל החובשים של אותו שחקן מרפאים את החיילים שנמצאים לידם
    void ParamedicCommander::full_action(Board &board, std::pair<int, int> placeOfSoldier) {
        std::cout << "-= Perform paramedicSoldierS basic heal-action =-" << std::endl;
        for (int i = 0; i < board.getRows(); ++i) {
            for (int j = 0; j < board.getCols(); ++j) {
                if (board[{i,j}] != nullptr && board[{i,j}]->playerNum == this->playerNum) { // אם יש חייל שם ששייך אליו
                    if (dynamic_cast<Paramedic *>(board[{i,j}])) {
                        std::cout << "Paramedic at: " << i << "," << j
                                  << " performing basic heal-action by commander order" << std::endl;
                        std::pair<int, int> loc = {i, j};
                        board[{i,j}]->basic_action(board, loc);
                    }
                }
            }
        }
    }
}
