//
// Created by shaharnik on 19/05/2020.
//

#ifndef UNTITLED5_FOOTSOLDIER_HPP
#define UNTITLED5_FOOTSOLDIER_HPP


#include "Soldier.hpp"
#include <iostream>

class FootSoldier : public Soldier {
public:
    int health_points;
    int damage_per_activity;
    int playerNum;
public:
    FootSoldier(int playerNum) : health_points(100), damage_per_activity(10), playerNum(playerNum){};

    void specialMove() // need to use override keyword
    {
        std::cout << "perform foot-soldier special move";
    }
};



#endif //UNTITLED5_FOOTSOLDIER_HPP
