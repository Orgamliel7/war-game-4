//
// Created by shaharnik on 19/05/2020.
//

#ifndef UNTITLED5_SOLDIER_HPP
#define UNTITLED5_SOLDIER_HPP


#include <utility>

class Soldier{
public:
    int playerNum;
    std::pair<int,int> location;


    public:
    void virtual specialMove() = 0; // this function will be overrided by type-soldiers and will be used polymorphic
};


#endif //UNTITLED5_SOLDIER_HPP
