//
// Created by shaharnik on 19/05/2020.
//
#include "Board.hpp"

void WarGame::Board::move(uint player_number, std::pair<int, int> source, WarGame::Board::MoveDIR direction) {

}

bool WarGame::Board::has_soldiers(uint player_number) const {
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
