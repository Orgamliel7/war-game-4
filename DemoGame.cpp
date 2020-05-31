/**
 * This is a game that demonstrates how to use the Board class.
 * You can modify it and build your own games.
 * 
 * @author Oz Levi 
 * @author Erel Segal-Halevi
 * @since  2020-05
 */

#include "DemoGame.hpp"
#include "FootSoldier.hpp"
#include "FootCommander.hpp"
#include "Sniper.hpp"
#include "Paramedic.hpp"
#include "SniperCommander.hpp"
#include "ParamedicCommander.hpp"

#include <cassert>

namespace WarGame {

		DemoGame::DemoGame(): board (8, 8) {
			// Add soldiers for player 1:
			assert(!board.has_soldiers(1));
			board[{0,1}] = new FootSoldier(1);
			board[{0,3}] = new Paramedic(1);
			board[{0,5}] = new Sniper(1);
            board[{0,7}] = new SniperCommander(1);
			assert(board.has_soldiers(1));

			// Add soldiers for player 2:
			assert(!board.has_soldiers(2));
			board[{7,1}] = new Sniper(2);
			board[{7,3}] = new FootCommander(2);
			board[{7,5}] = new Paramedic(2);
            board[{7,7}] = new ParamedicCommander(2);
			assert(board.has_soldiers(2));

			// In your game, you can put more soldier types, such as the sniper and the paramedic types.
		}

		uint DemoGame::play()
		{
		    std::cout << "Game Starting:" << std::endl;
            board.printBoard();
			board.move(1, {0,1}, Board::MoveDIR::Up);      // FootSoldier of player 1 moves forward and attacks.
			if (!board.has_soldiers(2)) return 1;



			board.move(2, {7,1}, Board::MoveDIR::Down);    // FootSoldier of player 2 moves forward and attacks.
			if (!board.has_soldiers(1)) return 2;
            board.printBoard();
            // why player at (0,3) removed?!
			board.move(1, {0,3}, Board::MoveDIR::Up);      // FootCommander of player 1 moves forward, and all soldiers of player 1 full_action.
			if (!board.has_soldiers(2)) return 1;
            board.printBoard();
            /*

            board.move(2, {7,3}, Board::MoveDIR::Left);    // FootCommander of player 2 moves left, and all soldiers of player 2 full_action.
            if (!board.has_soldiers(1)) return 2;

            board.printBoard();
            /// Write more moves here..
            board.move(1, {1,3}, Board::MoveDIR::Down);      // FootCommander of player 1 moves forward, and all soldiers of player 1 full_action.
            if (!board.has_soldiers(2)) return 1;

            board.printBoard();


*/
			// If no player won, return "tie":
			std::cout << "tie" << std::endl;
			return 0;
		}
	    DemoGame::~DemoGame() {
        for (int iRow=0; iRow<numRows; ++iRow) {
            for (int iCol=0; iCol<numCols; ++iCol) {
                Soldier* soldier = board[{iRow,iCol}];
                if (soldier)
                    delete soldier;
            }
        }
    }
}
