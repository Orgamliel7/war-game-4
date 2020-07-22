#include <iostream>
#include "FootSoldier.hpp"
#include "Board.hpp"
#include <math.h>

namespace WarGame {
    // פונקציה לחישוב המרחק
    float distance(int x1, int y1, int x2, int y2) {
        // חישוב מרחק ע"פ הנוסחא
        return sqrt(pow(x2 - x1, 2) +
                    pow(y2 - y1, 2) * 1.0);
    }
// (חייל זה יכול ללכת משבצת אחת לכל כיוון. יורה על החייל של האויב שנמצא הכי קרוב אליו (אם יש כמה - הוא יורה על אחד מהם שרירותית
    void
    FootSoldier::basic_action(Board &board, std::pair<int, int> placeOfSoldier) { // מקבל רפרנס ללוח וקוארדינטה של מיקום החייל
        float minDistance = std::numeric_limits<float>::max();
        for (int i = 0; i < board.getRows(); ++i) {
            for (int j = 0; j < board.getCols(); ++j) {
                if (board[{i,j}] != nullptr && board[{i,j}]->playerNum != this->playerNum) {//אם מצאנו חייל מכוחות האויב, כלומר - המשבצת לא ריקה ושייכת לשחקן השני
                    {
                        float Dis = distance(placeOfSoldier.first, placeOfSoldier.second, i, j); // נשמור את המרחק שבין שני החיילים
                        if (Dis < minDistance)//אם המרחק קטן ממש מהמרחק המינימלי
                        {
                            placeToAttack = {i, j}; //שומר את המיקום של האויב הקרוב ביותר   
                            minDistance = Dis; 
                        }

                    }

                }
            }

        }
        if (minDistance < std::numeric_limits<float>::max()) { // יש אפשרות להתקיף 
            int &x = placeToAttack.first; // ניצור רפרנס לשורה של האויב
            int &y = placeToAttack.second; // ניצור רפרנס לעמודה של האויב
            board[{x,y}]->decreaseHealth(this->getDamagePerActivity()); // נפחית לחייל נקודות בריאות
            if (board[{x,y}]->isDead()) { // אם האויב נהרג 
                std::cout << "EnemeySoldier at: " << x << "," << y << " is Died! (delete and null)" << std::endl;
                delete board[{x,y}]; // שחרור הזיכרון של אותו אויב
                board[{x,y}] = nullptr;
            } else { // אם שרד את הפגיעה
                std::cout << "perform FootSoldier basic full_action:" << std::endl;
                std::cout << "Reducing health of enemy at: " << x << "," << y << " Health left: "
                          << board[{x,y}]->getHealthPoints() << std::endl; // הפחתת נק' הבריאות של האויב והדפסתם למסך 
            }
        }

    }
}
