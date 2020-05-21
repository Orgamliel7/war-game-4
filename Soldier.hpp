//
// Created by shaharnik on 19/05/2020.
//

#ifndef UNTITLED5_SOLDIER_HPP
#define UNTITLED5_SOLDIER_HPP


#include <utility>

class Soldier{
public: //should be protected instead?
    int health_points;
    int damage_per_activity;
    int playerNum;
   // std::pair<int,int> location;


    public:
    Soldier() : health_points(0), damage_per_activity(0), playerNum(0){};
    Soldier(int playerNum, int damage_per_activity, int health_points) : playerNum(playerNum),damage_per_activity(damage_per_activity), health_points(health_points){};
    //Soldier(int playerNum, std::pair<int,int> loc) : playerNum(playerNum), location(loc){};
    void virtual specialMove() = 0; // this function will be overrided by type-soldiers and will be used polymorphic
   // Soldier operator ==(const Soldier&);
   Soldier& operator=(const Soldier& other) // copy assignment
   {
       if (this != &other) { // self-assignment check expected

           this->playerNum = other.playerNum;
           this->health_points = other.health_points;
           this->damage_per_activity = other.damage_per_activity;
       }
       return *this;
   }
};
/*
Base* b = new Derived;
if(Derived* d = dynamic_cast<Derived*>(b))
{
    std::cout << "downcast from b to d successful\n";
    d->name(); // safe to call
}

delete b1;
delete b2;
 */

#endif //UNTITLED5_SOLDIER_HPP
