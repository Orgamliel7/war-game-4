
#include "FootCommander.hpp"
#include "Board.hpp"
#include <iostream>

//namespace WarGame {
    void WarGame::FootCommander::full_action(Board &board,
                                    std::pair<int, int> placeOfSoldier) {
        std::cout << "perform FootCommander full_action" << std::endl;
        for (int i = 0; i < board.getRows(); ++i) {
            for (int j = 0; j < board.getCols(); ++j) {
                if (board[{i,j}] != nullptr && board[{i,j}]->playerNum ==
                                              this->playerNum) { // if soldier belong to me
                    if (dynamic_cast<FootSoldier *>(board[{i,j}])) {
                        std::cout << "FootSoldier at: " << i << "," << j
                                  << " performing action" << std::endl;
                        std::pair<int, int> loc = {i, j};
                        board[{i,j}]->basic_action(board, loc);
                    }
                }
            }
        }
    };
//}
