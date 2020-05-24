//
// Created by shaharnik on 19/05/2020.
//
#include "Board.hpp"
#include <iostream>
#include <math.h>

void WarGame::Board::move(uint player_number, std::pair<int, int> source, WarGame::Board::MoveDIR direction)
{
    int &x = source.first;
    int &y = source.second;
    if(this->board[x][y] != nullptr) // there is already a soldier there
    {
        if(this->board[x][y]->playerNum == player_number) // player moves soldier belongs to him
        {
            //move the soldier UP || DOWN || RIGHT || LEFT

            switch (direction)
            {
                case MoveDIR::Down:
                    if(y - 1 >= 0 && board[x][y-1] == nullptr)
                    {
                        this->board[x][y-1] = this->board[x][y];
                        this->board[x][y] = nullptr;
                        int player2attack_num = player2Attack(player_number);
                        this->board[x][y - 1]->specialMove(this->board, player2attack_num, {x,y-1});
                    }else throw std::invalid_argument ("Cant move the player Down to there");
                    break;
                case MoveDIR::Up:
                    if(y + 1 < this->board.size() && board[x][y+1] == nullptr){
                        this->board[x][y+1]=this->board[x][y]; // copy the reference not good
                        this->board[x][y] = nullptr; // src and dest are both get null because have same address
                        int player2attack_num = player2Attack(player_number);
                        this->board[x][y + 1]->specialMove(this->board, player2attack_num, {x,y+1});
                    }else throw std::invalid_argument ("Cant move the player Up to there");
                    break;
                case MoveDIR::Right:
                    if(x + 1 < this->board.size() && board[x+1][y] == nullptr){
                        this->board[x+1][y] = this->board[x][y];
                        this->board[x][y] = nullptr;
                        int player2attack_num = player2Attack(player_number);
                        this->board[x+1][y]->specialMove(this->board, player2attack_num, {x+1,y});
                    }else throw std::invalid_argument ("Cant move the player Right to there");

                    break;

                case MoveDIR::Left:
                    if(x - 1 >= 0 && board[x-1][y] == nullptr){
                        this->board[x-1][y] = this->board[x][y];
                        this->board[x][y] = nullptr;
                        int player2attack_num = player2Attack(player_number);
                        this->board[x-1][y]->specialMove(this->board, player2attack_num, {x-1,y});
                    }else throw std::invalid_argument ("Cant move the player Left to there");

                    break;

                default:
                    break;
            }
        } else{
            throw std::out_of_range ("The soldier is not belong to you.!.");
        }
        // "There is no soldier in: {" + source.first + "," +source.second + "}"
    }else throw std::out_of_range ("Can't Move: There is no soldier in this place.!.");
}
/*
std::pair<int, int> WarGame::Board::Attacking(WarGame::Board& board, uint number, std::pair<int, int> pair) {
    return std::pair<int, int>();
}
 */
int WarGame::Board::player2Attack(int player_number)
{
    if (player_number == 1)
        return 2;
    else // player_number==2
        return 1;
}

// second const says that the method is not changing the state of the object. I.e. the method does not change any member variables.
bool WarGame::Board::has_soldiers(uint player_number) const {
    for (int i = 0; i < board.size(); ++i) {
        for (int j = 0; j < 8; ++j) // need to check how get size of cols vector
        {
            if (board[i][j] != nullptr && board[i][j]->playerNum == player_number) {
                std::cout << "soldier found for player number: " << player_number<<std::endl;
                return true;
            }
        }
    }
    std::cout << "No soldiers for player number: " << player_number<<std::endl;
    return false;
}
// operator for putting soldiers on the game-board during initialization.
Soldier *&WarGame::Board::operator[](std::pair<int, int> location)
{
    if(board[location.first][location.second] != nullptr){
        throw std::invalid_argument ("There is already player standing here!!");
    }
    if(location.first < board.size() && location.second < board.size()){
        return this->board[location.first][location.second];
    }
    else {
        throw std::invalid_argument ("The coordinate isn't in the dimension of the board!!");
    }
}
// operator for reading which soldiers are on the game-board.
// the const mean we don't change the object.
Soldier* WarGame::Board::operator[](std::pair<int, int> location) const {
    return this->board[location.first][location.second];
}



