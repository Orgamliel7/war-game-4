
#include "Board.hpp"
#include <iostream>
#include <math.h>

void WarGame::Board::move(uint player_number, std::pair<int, int> source, WarGame::Board::MoveDIR direction) {
    std::cout << "Player No. " << player_number << " turn" << std::endl;
    int &x = source.first;
    int &y = source.second;
    if (this->board[x][y] != nullptr) // אם יש חייל שאפשר להזיז
    {
        if (this->board[x][y]->playerNum == player_number) // אם החייל שייך ל-שחקן 
        {
            //move the soldier UP || DOWN || RIGHT || LEFT
            switch (direction)
            {
                case MoveDIR::Down:
                    if (!moveAndAct(x-1,y,x,y)) // אם לא הצלחנו להוריד 
                        throw std::invalid_argument("Cant move the player Down to there");
                    break;
                case MoveDIR::Up:
                    if (!moveAndAct(x+1,y,x,y))
                        throw std::invalid_argument("Cant move the player Up there");
                    break;
                case MoveDIR::Right:
                    if (!moveAndAct(x,y+1,x,y))
                        throw std::invalid_argument("Cant move the player Right there");
                    break;
                case MoveDIR::Left:
                    if (!moveAndAct(x,y-1,x,y))
                        throw std::invalid_argument("Cant move the player Left there");
                    break;

                default:
                    break;
            }
        } else {
            throw std::out_of_range("The soldier is not belong to you.!.");
        }
    } else throw std::out_of_range("Can't Move: There is no soldier in this place.!.");
}
// why needed in h? dont know board if not declared there..
bool WarGame::Board::moveAndAct(int new_x, int new_y, int old_x, int old_y)
{
    if (inRange(new_x,new_y) && this->board[new_x][new_y] == nullptr) {
        this->board[new_x][new_y] = this->board[old_x][old_y];
        this->board[old_x][old_y] = nullptr;
        this->board[new_x][new_y]->full_action(*this, {new_x, new_y});
        return true;
    } else return false;
}
bool WarGame::Board::inRange(int x, int y) {
    if (x >= this->board.size() || x < 0 || y >= board[x].size() || y < 0)
    {
        return false;
    }
    return true;
}

// second const says that the method is not changing the state of the object. I.e. the method does not change any member variables.
bool WarGame::Board::has_soldiers(uint player_number) const {
    for (int i = 0; i < board.size(); ++i) {
        for (int j = 0; j < board[i].size(); ++j)
        {
            if (board[i][j] != nullptr && board[i][j]->playerNum == player_number) {
                std::cout << "soldier found for player number: " << player_number << std::endl;
                return true;
            }
        }
    }
    std::cout << "No soldiers for player number: " << player_number << std::endl;
    return false;
}

// operator for putting soldiers on the game-board during initialization.
WarGame::Soldier *&WarGame::Board::operator[](std::pair<int, int> location) {
    /*if (board[location.first][location.second] != nullptr) {
        throw std::invalid_argument("There is already player standing here!!");
    }
     */
    if (location.first < Dim.first && location.second < Dim.second) {
        return this->board[location.first][location.second];
    } else {
        throw std::invalid_argument("The coordinate isn't in the dimension of the board!!");
    }
}

// operator for reading which soldiers are on the game-board.
// const - כדי שלא נוכל לשנות את האובייקט
WarGame::Soldier *WarGame::Board::operator[](std::pair<int, int> location) const {
    if (location.first < Dim.first && location.second < Dim.second) {
        return this->board[location.first][location.second];
    } else {
        throw std::invalid_argument("The coordinate isn't in the dimension of the board!!");
    }
}

void WarGame::Board::printBoard() { // פונקציית הדפסה ללוח המשחק
    for (int i = 0; i < this->getRows(); ++i) { // 
        std::cout << std::endl;
        for (int j = 0; j < this->getCols(); ++j) {
            if (board[i][j] != nullptr)
                std::cout << board[i][j]->playerNum << " ";
            else
                std::cout << "0 ";
        }
    }
    std::cout << std::endl;
}

int WarGame::Board::getRows() { // פונקציה שמחזירה את מספר השורות
    return this->Dim.first;
}

int WarGame::Board::getCols() { // פונקציה שמחזירה את מספר העמודות
    return this->Dim.second;;
}



