
#include "Board.hpp"
#include <iostream>
#include <math.h>

void WarGame::Board::move(uint player_number, std::pair<int, int> source, WarGame::Board::MoveDIR direction) {
    std::cout << "Player No. " << player_number << " turn" << std::endl;
    int &x = source.first; // רפרנס לשורה
    int &y = source.second; // רפרנס לעמודה
    if (this->board[x][y] != nullptr) // אם יש חייל שאפשר להזיז
    {
        if (this->board[x][y]->playerNum == player_number) // אם החייל שייך ל-שחקן 
        {
            //move the soldier UP || DOWN || RIGHT || LEFT אופציות התזוזה על הלוח
            switch (direction)
            {
                case MoveDIR::Down: // שורה למטה 
                    if (!moveAndAct(x-1,y,x,y)) // אם לא הצלחנו להוריד 
                        throw std::invalid_argument("Cant move the player Down to there");
                    break;
                case MoveDIR::Up: // שורה מעלה
                    if (!moveAndAct(x+1,y,x,y))
                        throw std::invalid_argument("Cant move the player Up there");
                    break;
                case MoveDIR::Right: // עמודה ימינה
                    if (!moveAndAct(x,y+1,x,y))
                        throw std::invalid_argument("Cant move the player Right there");
                    break;
                case MoveDIR::Left: // עמודה שמאלה
                    if (!moveAndAct(x,y-1,x,y))
                        throw std::invalid_argument("Cant move the player Left there");
                    break;

                default:
                    break;
            }
        } else {
            throw std::out_of_range("The soldier is not belong to you.!."); // החייל לא שייך לשחקן הנוכחי
        }
    } else throw std::out_of_range("Can't Move: There is no soldier in this place.!."); // החייל לא יכול לזוז
}
// why needed in h? dont know board if not declared there..
bool WarGame::Board::moveAndAct(int new_x, int new_y, int old_x, int old_y) // תזוזה ופעולה בהתאם לסוג החייל
{
    if (inRange(new_x,new_y) && this->board[new_x][new_y] == nullptr) { // אם אפשר לזוז - נחזיר אמת
        this->board[new_x][new_y] = this->board[old_x][old_y]; // נבצע הוזזה של החייל
        this->board[old_x][old_y] = nullptr; // מחיקת הפוינטר של המיקום הקודם 
        this->board[new_x][new_y]->full_action(*this, {new_x, new_y}); // ביצוע הפעולה של החייל 
        return true;
    } else return false;
}
bool WarGame::Board::inRange(int x, int y) { // פונקציה בוליאנית לבדוק האם אנחנו בטווח הנכון של הלוח ולא חורגים ממנו
    if (x >= this->board.size() || x < 0 || y >= board[x].size() || y < 0) // כל האופציות לחריגה אופציונלית
    {
        return false;
    }
    return true;
}

// בכדי שהמתודה לא תשנה את האובייקט נהפוך אותה לקבועה, ולא משנה שדות 
// second const says that the method is not changing the state of the object. I.e. the method does not change any member variables.
bool WarGame::Board::has_soldiers(uint player_number) const { // ?האם יש חיילים בלוח המשחק
    for (int i = 0; i < board.size(); ++i) {
        for (int j = 0; j < board[i].size(); ++j) // ריצה בפור מקונן על הלוח
        {
            if (board[i][j] != nullptr && board[i][j]->playerNum == player_number) { // אם קיימים מצביע לא ריק ומשבצת השייכת ל-שחקן
                std::cout << "soldier found for player number: " << player_number << std::endl;
                return true;
            }
        }
    }
    std::cout << "No soldiers for player number: " << player_number << std::endl;
    return false;
}

// operator for putting soldiers on the game-board during initialization. העמסת אופרטור לשיבוץ חיילים בלוח כשמאתחלים
WarGame::Soldier *&WarGame::Board::operator[](std::pair<int, int> location) {
   
    if (location.first < Dim.first && location.second < Dim.second) {
        return this->board[location.first][location.second];
    } else {
        throw std::invalid_argument("The coordinate isn't in the dimension of the board!!"); // הקואורדינטה לא בתחום של הלוח
    }
}

// operator for reading which soldiers are on the game-board. העמסת אופרטור לקריאה(!) איזה חיילים בלוח, לכן קבועה 
// const - כדי שלא נוכל לשנות את האובייקט
WarGame::Soldier *WarGame::Board::operator[](std::pair<int, int> location) const {
    if (location.first < Dim.first && location.second < Dim.second) {  // בדיקת תקינות לקוארדינטה
        return this->board[location.first][location.second]; // נחזיר את החייל במשבצת הנ"ל
    } else {
        throw std::invalid_argument("The coordinate isn't in the dimension of the board!!");
    }
}

void WarGame::Board::printBoard() { // פונקציית הדפסה ללוח המשחק
    for (int i = 0; i < this->getRows(); ++i) { // מעבר על הלוח
        std::cout << std::endl;
        for (int j = 0; j < this->getCols(); ++j) {
            if (board[i][j] != nullptr) // בדיקה ששונה ממצביע ריק, כלומר קיים שם חייל
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



