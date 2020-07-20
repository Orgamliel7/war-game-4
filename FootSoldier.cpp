#include <iostream>
#include "FootSoldier.hpp"
#include "Board.hpp"
#include <math.h>

namespace WarGame {
    // פונקציה לחישוב המרחק
    float distance(int x1, int y1, int x2, int y2) {
        // חישוב מרחק ע"פ הנוסחא
        return sqrt(pow(x2 - x1, 2) +
                    pow(y2 - y1, 2) * 1.0);
    }

    void
    FootSoldier::basic_action(Board &board, std::pair<int, int> placeOfSoldier) {
        std::pair<int, int> placeToAttack;
        float minDistance = std::numeric_limits<float>::max();
        for (int i = 0; i < board.getRows(); ++i) {
            for (int j = 0; j < board.getCols(); ++j) {
                if (board[{i,j}] != nullptr &&
                        board[{i,j}]->playerNum != this->playerNum) {//if enemy soldier has founded
                    {
                        float Dis = distance(placeOfSoldier.first, placeOfSoldier.second, i, j);
                        if (Dis < minDistance)//calculate distance
                        {
                            placeToAttack = {i, j}; //שומר את המיקום של האויב הקרוב ביותר   
                            minDistance = Dis;
                        }

                    }

                }
            }

        }
        if (minDistance < std::numeric_limits<float>::max()) {
            int &x = placeToAttack.first;
            int &y = placeToAttack.second;
            board[{x,y}]->decreaseHealth(this->getDamagePerActivity());
            if (board[{x,y}]->isDead()) {
                std::cout << "EnemeySoldier at: " << x << "," << y << " is Died! (delete and null)" << std::endl;
                delete board[{x,y}];
                board[{x,y}] = nullptr;
            } else {
                std::cout << "perform FootSoldier basic full_action:" << std::endl;
                std::cout << "Reducing health of enemy at: " << x << "," << y << " Health left: "
                          << board[{x,y}]->getHealthPoints() << std::endl;
            }
        }

    }
}
