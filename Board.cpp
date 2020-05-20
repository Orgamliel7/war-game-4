//
// Created by shaharnik on 19/05/2020.
//
#include "Board.hpp"
#include <iostream>

void WarGame::Board::move(uint player_number, std::pair<int, int> source, WarGame::Board::MoveDIR direction) {

}

// second const says that the method is not changing the state of the object. I.e. the method does not change any member variables.
bool WarGame::Board::has_soldiers(uint player_number) const {
    for (int i = 0; i < board.size(); ++i) {
        for (int j = 0; j < 8; ++j) // need to check how get size of cols vector
        {
            if (board[i][j] != nullptr && board[i][j]->playerNum == player_number) {
                std::cout << "soldier found for player number: " << player_number;
                return true;
            }
        }
    }
    std::cout << "No soldier for player number: " << player_number;
    return false;
}
// operator for putting soldiers on the game-board during initialization.
Soldier *&WarGame::Board::operator[](std::pair<int, int> location)
{
    board[location.first][location.second];
    return board[0][1];
}
// operator for reading which soldiers are on the game-board.
Soldier *WarGame::Board::operator[](std::pair<int, int> location) const {
    return board[0][1];
}
