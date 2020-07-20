#include "Paramedic.hpp"
#include <iostream>
#include "Board.hpp"

namespace WarGame {
    // חובש - יכול ללכת משבצת אחת לכל כיוון. לא יורה, מרפא את כל החיילים של אותו שחקן שנמצאים במשבצת לידו -מחזיר את מספר נקודות-הבריאות שלהם למספר ההתחלת
    void Paramedic::basic_action(Board &board,
                                 std::pair<int, int> placeOfSoldier) {
        int &x = placeOfSoldier.first;
        int &y = placeOfSoldier.second;

        for (int i = -1; i <= 1; ++i) {
            for (int j = -1; j <= 1; ++j) {
                if (inRange(board, placeOfSoldier)) {
                    if (board[{x + i,y + j}] != nullptr &&
                        board[{x + i,y + j}]->playerNum == this->playerNum) {
                        board[{x + i,y + j}]->Heal();
                        std::cout << "Soldier at: " << x + i << "," << y + j << " is Healed!" << " Health raised to:"
                                  << board[{x + i,y + j}]->getHealthPoints() << " MaxHealth is:"
                                  << board[{x + i,y + j}]->MaxHealth
                                  << std::endl;
                    }
                }
            }
        }
    }

    bool Paramedic::inRange(Board &board, std::pair<int, int> placeOfSoldier) {
        int &x = placeOfSoldier.first;
        int &y = placeOfSoldier.second;
        if (x >= board.getRows() || x < 0 || y >= board.getCols() || y < 0) {
            return false;
        }
        return true;
    }
}


