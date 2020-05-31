#include "Sniper.hpp"
#include <iostream>
#include "Board.hpp"

namespace WarGame {
    void Sniper::basic_action(Board &board,
                              std::pair<int, int> placeOfSoldier) {
        std::pair<int, int> placeToAttack;
        int maxHealth = 0;
        for (int i = 0; i < board.getRows(); ++i) {
            for (int j = 0; j < board.getCols(); ++j) {
                if (board[{i,j}] != nullptr &&
                        board[{i,j}]->playerNum != this->playerNum) {//if soldier enemy found
                    {
                        if (maxHealth < board[{i,j}]->getHealthPoints()) {
                            placeToAttack = {i, j};//save the place of the healthiest enemy's soldier
                            maxHealth = board[{i,j}]->getHealthPoints();
                        }

                    }

                }
            }

        }
        int &x = placeToAttack.first;
        int &y = placeToAttack.second;
        if (maxHealth > 0) {
            board[{x,y}]->decreaseHealth(this->getDamagePerActivity());
            if (board[{x,y}]->isDead()) {
                std::cout << "EnemeySoldier at: " << x << "," << y << " is Died! (delete and null)" << std::endl;
                delete board[{x,y}];
                board[{x,y}] = nullptr;
            } else {
                std::cout << "perform Sniper full_action:" << std::endl;
                std::cout << "Reducing health of enemy at: " << x << "," << y << " Health left: "
                          << board[{x,y}]->getHealthPoints() << std::endl;
            }
        }
    }
}