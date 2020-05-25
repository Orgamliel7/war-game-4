//
// Created by shaharnik on 25/05/2020.
//

#ifndef UNTITLED5_SNIPER_HPP
#define UNTITLED5_SNIPER_HPP

#include "Soldier.hpp"
#include <iostream>

class Sniper : public Soldier {
public:
    Sniper(int playerNum) : Soldier(playerNum, 50, 100) {};
    Sniper(int playerNum, int damage_per_act, int health_points) : Soldier(playerNum, damage_per_act, health_points) {};

    virtual void basic_action(std::vector<std::vector<Soldier *>> &board, int PlayerToAttack,
                              std::pair<int, int> placeOfSoldier) override // need to check how use override keyword
    {
        std::pair<int, int> placeToAttack = {0, 0};
        int maxHealth = 0;
        for (int i = 0; i < board.size(); ++i) {
            for (int j = 0; j < board[i].size(); ++j) {
                if (board[i][j] != nullptr &&
                    board[i][j]->playerNum == PlayerToAttack) {//if soldier of attacked player found
                    {
                        if (maxHealth < board[i][j]->health_points) {
                            placeToAttack = {i, j};//save the place of the healthiest enemy's soldier
                            maxHealth = board[i][j]->health_points;
                        }

                    }

                }
            }

        }
        int &x = placeToAttack.first;
        int &y = placeToAttack.second;
        if (maxHealth > 0) {
            board[x][y]->decreaseHealth(50);
            if (board[x][y]->health_points <= 0) {
                std::cout << "EnemeySoldier at: " << x << "," << y << " is Died! (delete and null)" << std::endl;
                delete board[x][y];
                board[x][y] = nullptr;
            } else {
                std::cout << "perform Sniper full_action:" << std::endl;
                std::cout << "Reducing health of enemy at: " << x << "," << y << " Health left: "
                          << board[x][y]->health_points << std::endl;
            }
        }
    }
    virtual void full_action(std::vector<std::vector<Soldier *>> &board, int PlayerToAttack,
                             std::pair<int, int> placeOfSoldier) override // need to check how use override keyword
    {
        board[placeOfSoldier.first][placeOfSoldier.second]->basic_action(board, PlayerToAttack, placeOfSoldier);
    }
};

#endif //UNTITLED5_SNIPER_HPP
