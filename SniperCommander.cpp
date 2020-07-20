#include "SniperCommander.hpp"
#include <iostream>
#include "Board.hpp"

namespace WarGame {
    //כמו צלף, אבל כשהוא זז, לא רק הוא יורה אלא כל הצלפים של אותו שחקן יורים
    void SniperCommander::full_action(Board &board,
                     std::pair<int, int> placeOfSoldier) {
        for (int i = 0; i < board.getRows(); ++i) {
            for (int j = 0; j < board.getCols(); ++j) {
                if (board[{i, j}] != nullptr &&
                    board[{i, j}]->playerNum == this->playerNum)
                { // if soldier belong to me
                    if (dynamic_cast<Sniper *>(board[{i, j}]))
                    {
                        std::cout << "Sniper at: " << i << "," << j
                                  << " performing basic_action by commander order" << std::endl;
                        std::pair<int, int> loc = {i, j};
                        board[{i, j}]->basic_action(board, loc);
                    }
                }
            }
        }
    }
}
