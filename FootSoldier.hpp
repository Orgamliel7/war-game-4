//
// Created by shaharnik on 19/05/2020.
//

#ifndef UNTITLED5_FOOTSOLDIER_HPP
#define UNTITLED5_FOOTSOLDIER_HPP


#include "Soldier.hpp"
#include <math.h>
#include <iostream>

class FootSoldier : public Soldier {
public:
    //int health_points;
    //int damage_per_activity;
    //int playerNum;
public:

    FootSoldier(int playerNum) : Soldier(playerNum, 10, 100){std::cout << "Foot Soldier built for player:"<<playerNum<<std::endl;};

    void specialMove(std::vector<std::vector<Soldier*>> &board,int PlayerToAttack, std::pair<int,int> placeOfSoldier) // need to check how use override keyword
    {
        std::cout << "perform FootSoldier special move" << std::endl;

        std::pair <int,int> placeToAttack = {0,0};
        int minDistance = INT16_MAX;
        for (int i = 0; i < board.size(); ++i)
        {
            for (int j = 0; j < board[i].size(); ++j)
            {
                if (board[i][j] != nullptr && board[i][j]->playerNum == PlayerToAttack){//if soldier of attacked player found
                    {
                        float Dis = distance(placeOfSoldier.first, placeOfSoldier.second, i, j);
                        if(Dis < minDistance)//calculate distance
                        {
                            placeToAttack = {i,j};//save the place of the closest enemy's soldier
                            minDistance = Dis;
                        }

                    }

                }
            }

        }
        int &x = placeToAttack.first;
        int &y = placeToAttack.second;
        if (minDistance < INT16_MAX){
            board[x][y]->decreaseHealth(10);
            std::cout << "FootSoldier:Attack:Reducing health of enemy at: " << x << "," << y << std::endl;
            std::cout << "EnemeySoldier at: " << x << " ," << y << " Health is: " << board[x][y]->health_points << std::endl;
        }

    }
// Function to calculate distance
    float distance(int x1, int y1, int x2, int y2)
    {
        // Calculating distance
        return sqrt(pow(x2 - x1, 2) +
                    pow(y2 - y1, 2) * 1.0);
    }
};



#endif //UNTITLED5_FOOTSOLDIER_HPP
