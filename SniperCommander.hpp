//
// Created by shaharnik on 25/05/2020.
//

#ifndef UNTITLED5_SNIPERCOMMANDER_HPP
#define UNTITLED5_SNIPERCOMMANDER_HPP

#include "Soldier.hpp"
#include "Sniper.hpp"
#include <iostream>

class SniperCommander : public Sniper {
public:
    SniperCommander(int playerNum) : Sniper(playerNum, 100, 120){};

    void full_action(std::vector<std::vector<Soldier *>> &board, int PlayerToAttack,
                     std::pair<int, int> placeOfSoldier) override // need to check how use override keyword
    {
        std::cout << "perform SniperCommander full_action" << std::endl;
        int &x = placeOfSoldier.first;
        int &y = placeOfSoldier.second;
        board[x][y]->basic_action(board, PlayerToAttack, placeOfSoldier);
        //commander attacked, now his soldiers:
        std::cout << "-= Perform SniperSoldierS basic full_action by commander order =-" << std::endl;
        for (int i = 0; i < board.size(); ++i) {
            for (int j = 0; j < board[i].size(); ++j) {
                if (board[i][j] != nullptr && board[i][j] != this && board[i][j]->playerNum != PlayerToAttack) { // if soldier isn't belong to enemy and isn't the commander himself
                    if (board[i][j] = dynamic_cast<Sniper*>(board[i][j])) {
                        std::cout << "Sniper at: " << i << "," << j
                                  << " performing basic full_action by commander order" << std::endl;
                        std::pair<int, int> loc = {i, j};
                        board[i][j]->basic_action(board, PlayerToAttack, loc);
                    }
                }
            }
        }
    }
};

#endif //UNTITLED5_SNIPERCOMMANDER_HPP
