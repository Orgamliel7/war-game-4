//
// Created by shaharnik on 19/05/2020.
//

#ifndef UNTITLED5_SOLDIER_HPP
#define UNTITLED5_SOLDIER_HPP


#include <utility>
#include <iostream>
#include <vector>
//#include "Board.hpp"
#pragma once


class Soldier {
public: //should be protected instead?
    int health_points;
    int damage_per_activity;
    int playerNum;
    const int MaxHealth; // ToSave Soldier MaxHealth - for healing..
    // std::pair<int,int> location;


public:
    Soldier() : health_points(0), damage_per_activity(0), playerNum(0), MaxHealth(0) {};

    Soldier(int playerNum, int damage_per_activity, int health_points) : playerNum(playerNum),
                                                                         damage_per_activity(damage_per_activity),
                                                                         health_points(health_points), MaxHealth(health_points) {};

    virtual void basic_action(std::vector<std::vector<Soldier *>> &board, int PlayerToAttack,
                              std::pair<int, int> placeOfSoldier) = 0;

    virtual void
    full_action(std::vector<std::vector<Soldier *>> &board, int PlayerToAttack, std::pair<int, int> placeOfSoldier) = 0;

    void decreaseHealth(int damage) {
        this->health_points -= damage;
    }

    void Heal() {
        this->health_points = MaxHealth;
    }

};


#endif //UNTITLED5_SOLDIER_HPP
