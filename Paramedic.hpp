//
// Created by shaharnik on 25/05/2020.
//

#ifndef UNTITLED5_PARAMEDIC_HPP
#define UNTITLED5_PARAMEDIC_HPP

#include "Soldier.hpp"
#include <iostream>

class Paramedic : public Soldier {
public:
    Paramedic(int playerNum) : Soldier(playerNum, 50, 100) {
        std::cout << "Paramedic built for player:" << playerNum << std::endl;

    };

    Paramedic(int playerNum, int damage_per_act, int health_points) : Soldier(playerNum, damage_per_act,
                                                                              health_points) {};

    virtual void basic_action(std::vector<std::vector<Soldier *>> &board, int PlayerToAttack,
                              std::pair<int, int> placeOfSoldier) override // need to check how use override keyword
    {
        int &x = placeOfSoldier.first;
        int &y = placeOfSoldier.second;
        if (x + 1 < board.size() && board[x + 1][y] != nullptr &&
            board[x + 1][y]->playerNum != PlayerToAttack) // Up heal
        {
            board[x + 1][y]->Heal();
            std::cout << "Soldier at: " << x + 1 << "," << y << " is Healed!" << " Health raised to:"
                      << board[x + 1][y]->health_points << " MaxHealth is:" << board[x + 1][y]->MaxHealth << std::endl;
        }
        if (x - 1 >= 0 && board[x - 1][y] != nullptr && board[x - 1][y]->playerNum != PlayerToAttack) // Down heal
        {
            board[x - 1][y]->Heal();
            std::cout << "Soldier at: " << x - 1 << "," << y << " is Healed!" << " Health raised to:"
                      << board[x - 1][y]->health_points << " MaxHealth is:" << board[x - 1][y]->MaxHealth << std::endl;
        }
        if (y + 1 < board[x].size() && board[x][y + 1] != nullptr &&
            board[x][y + 1]->playerNum != PlayerToAttack) // right heal
        {
            board[x][y + 1]->Heal();
            std::cout << "Soldier at: " << x << "," << y + 1 << " is Healed!" << " Health raised to:"
                      << board[x][y + 1]->health_points << " MaxHealth is:" << board[x][y + 1]->MaxHealth << std::endl;
        }
        if (y - 1 >= 0 && board[x][y - 1] != nullptr && board[x][y - 1]->playerNum != PlayerToAttack) // left heal
        {
            board[x][y - 1]->Heal();
            std::cout << "Soldier at: " << x << "," << y - 1 << " is Healed!" << " Health raised to:"
                      << board[x][y - 1]->health_points << " MaxHealth is:" << board[x][y - 1]->MaxHealth << std::endl;
        }
        if (y - 1 >= 0 && x-1>=0 &&board[x-1][y - 1] != nullptr && board[x-1][y - 1]->playerNum != PlayerToAttack) // left heal
        {
            board[x-1][y - 1]->Heal();
            std::cout << "Soldier at: " << x-1 << "," << y - 1 << " is Healed!" << " Health raised to:"
                      << board[x][y - 1]->health_points << " MaxHealth is:" << board[x-1][y - 1]->MaxHealth << std::endl;
        }
        if (y + 1 >= 0 && x-1>=0&& board[x-1][y +1] != nullptr && board[x-1][y + 1]->playerNum != PlayerToAttack) // left heal
        {
            board[x-1][y + 1]->Heal();
            std::cout << "Soldier at: " << x-1<< "," << y + 1 << " is Healed!" << " Health raised to:"
                      << board[x-1][y + 1]->health_points << " MaxHealth is:" << board[x-1][y + 1]->MaxHealth << std::endl;
        }
        if (y + 1 >= 0 && x+1>=0&& board[x+1][y + 1] != nullptr && board[x+1][y + 1]->playerNum != PlayerToAttack) // left heal
        {
            board[x+1][y +1]->Heal();
            std::cout << "Soldier at: " << x+1 << "," << y +1 << " is Healed!" << " Health raised to:"
                      << board[x+1][y + 1]->health_points << " MaxHealth is:" << board[x+1][y + 1]->MaxHealth << std::endl;
        }
        if (y - 1 >= 0 && x+1>=0 && board[x+1][y - 1] != nullptr && board[x+1][y - 1]->playerNum != PlayerToAttack) // left heal
        {
            board[x+1][y - 1]->Heal();
            std::cout << "Soldier at: " << x+1 << "," << y - 1 << " is Healed!" << " Health raised to:"
                      << board[x+1][y - 1]->health_points << " MaxHealth is:" << board[x+1][y - 1]->MaxHealth << std::endl;
        }
    }

    virtual

    void full_action(std::vector<std::vector<Soldier *>> &board, int PlayerToAttack,
                     std::pair<int, int> placeOfSoldier)
    override
    {
        board[placeOfSoldier.first][placeOfSoldier.second]->
                basic_action(board, PlayerToAttack, placeOfSoldier
        );
    }
};

#endif //UNTITLED5_PARAMEDIC_HPP
