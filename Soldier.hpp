
#pragma once
#include <utility>
#include <iostream>
#include <vector>
namespace WarGame {

    class Board;

    class Soldier {
        //change to private
    private:
        int health_points;
        int damage_per_activity;
    public:
        const int MaxHealth; // ToSave Soldier MaxHealth - for healing..
    public:
        int playerNum;


    public:
        Soldier() : health_points(0), damage_per_activity(0), playerNum(0), MaxHealth(0) {};

        Soldier(int playerNum, int damage_per_activity, int health_points) : playerNum(playerNum),
                                                                             damage_per_activity(damage_per_activity),
                                                                             health_points(health_points),
                                                                             MaxHealth(health_points) {};

        virtual void basic_action(WarGame::Board &board,
                                  std::pair<int, int> placeOfSoldier) = 0;

        virtual void
        full_action(Board &board, std::pair<int, int> placeOfSoldier) = 0;

        void decreaseHealth(int damage) {
            this->health_points -= damage;
        }
        int getHealthPoints() const {
            return health_points;
        }

        int getDamagePerActivity() const {
            return damage_per_activity;
        }

        void Heal() {
            this->health_points = MaxHealth;
        }

        bool isDead() {
            if (health_points <= 0)
                return true;
            return false;
        }

    };
}
