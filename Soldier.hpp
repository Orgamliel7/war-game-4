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


class Soldier{
public: //should be protected instead?
    int health_points;
    int damage_per_activity;
    int playerNum;
   // std::pair<int,int> location;


    public:
    Soldier() : health_points(0), damage_per_activity(0), playerNum(0){};
    Soldier(int playerNum, int damage_per_activity, int health_points) : playerNum(playerNum),damage_per_activity(damage_per_activity), health_points(health_points){};

     virtual void basic_attack(std::vector<std::vector<Soldier*>> &board,int PlayerToAttack, std::pair<int,int> placeOfSoldier) = 0;
     virtual void attack(std::vector<std::vector<Soldier*>> &board,int PlayerToAttack, std::pair<int,int> placeOfSoldier) = 0;
     //virtual void specialMove() = 0; // this function will be overrided by type-soldiers and will be used polymorphic
   /* Soldier operator ==(const Soldier&);
   Soldier& operator=(const Soldier& other) // copy assignment
   {
       //std::cout << "TESTTTT!!";
       if (this != &other) { // self-assignment check expected

           this->playerNum = other.playerNum;
           this->health_points = other.health_points;
           this->damage_per_activity = other.damage_per_activity;
       }
       return *this;
   }
    */
    void decreaseHealth(int damage){
        this->health_points -= damage;
    }
    void Heal(int life_points){
        this->health_points += life_points;
    }

};


#endif //UNTITLED5_SOLDIER_HPP
