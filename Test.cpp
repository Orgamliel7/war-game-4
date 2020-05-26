//
// Created by tzach on 26/05/2020.
//
#include <iostream>
#include "doctest.h"
#include "Board.hpp"
#include "DemoGame.hpp"
#include "FootSoldier.hpp"
#include "FootCommander.hpp"
#include "Sniper.hpp"
#include "SniperCommander.hpp"
#include "Paramedic.hpp"
#include "ParamedicCommander.hpp"

using namespace WarGame;
TEST_CASE ("Test of create soldiers") {
    Board board(6, 6);

            CHECK(board.has_soldiers(1) == false);
            CHECK(board.has_soldiers(2) == false);

    //adding soldiers
    board[{0, 1}] = new FootSoldier(1);
    board[{0, 3}] = new FootCommander(1);
    board[{0, 2}] = new FootSoldier(1);
    board[{0, 4}] = new FootSoldier(1);
    board[{0, 5}] = new Sniper(1);

    board[{3, 1}] = new FootSoldier(2);
    board[{3, 2}] = new FootCommander(2);
    board[{3, 3}] = new FootSoldier(2);
    board[{5, 5}] = new FootSoldier(2);
    board[{5, 4}] = new Paramedic(2);

            CHECK(board[{1, 1}] == nullptr);
            CHECK(board[{1, 2}] == nullptr);
            CHECK(board[{2, 3}] == nullptr);
            CHECK(board[{2, 2}] == nullptr);
            CHECK(board[{2, 3}] == nullptr);
            CHECK(board[{2, 4}] == nullptr);
            CHECK(board[{2, 5}] == nullptr);
            CHECK(board[{3, 2}] == nullptr);
            CHECK(board[{4, 2}] == nullptr);
            CHECK(board[{5, 2}] == nullptr);
            CHECK(board[{5, 3}] == nullptr);

            CHECK(board[{3, 2}]->health_points == 150);
            CHECK(board[{0, 3}]->health_points == 150);
            CHECK(board[{0, 5}]->health_points == 100);
            CHECK(board[{0, 4}]->health_points == 100);
            CHECK(board[{5, 4}]->health_points == 100);
            CHECK(board[{0, 1}]->health_points == 100);
            CHECK(board[{0, 2}]->health_points == 100);
            CHECK(board[{3, 1}]->health_points == 100);
            CHECK(board[{3, 3}]->health_points == 100);

            CHECK(board[{5, 5}]->damage_per_activity == 10);
            CHECK(board[{5, 4}]->damage_per_activity == 10);
            CHECK(board[{0, 4}]->damage_per_activity == 10);
            CHECK(board[{0, 5}]->damage_per_activity == 50);
            CHECK(board[{0, 1}]->damage_per_activity == 10);
            CHECK(board[{0, 2}]->damage_per_activity == 10);
            CHECK(board[{3, 1}]->damage_per_activity == 10);
            CHECK(board[{3, 3}]->damage_per_activity == 10);
            CHECK(board[{3, 2}]->damage_per_activity == 20);
            CHECK(board[{0, 3}]->damage_per_activity == 20);
            CHECK(board[{5, 5}]->damage_per_activity == 10);
            CHECK(board[{5, 4}]->damage_per_activity == 10);
            CHECK(board[{0, 4}]->damage_per_activity == 10);
            CHECK(board[{0, 5}]->damage_per_activity == 50);
            CHECK(board[{0, 1}]->damage_per_activity == 10);
            CHECK(board[{0, 2}]->damage_per_activity == 10);
            CHECK(board[{3, 1}]->damage_per_activity == 10);
            CHECK(board[{3, 3}]->damage_per_activity == 10);
            CHECK(board[{3, 2}]->damage_per_activity == 20);
            CHECK(board[{0, 3}]->damage_per_activity == 20);


            CHECK(board.has_soldiers(1) == true);
            CHECK(board.has_soldiers(2) == true);

            CHECK_THROWS((board[{3, 3}] == nullptr));
            CHECK_THROWS((board[{2, 2}] != nullptr));
            CHECK_THROWS((board[{1, 1}] != nullptr));

    board.move(1, {0, 1}, Board::MoveDIR::Up);
            CHECK(board[{0, 1}] == nullptr);
            CHECK(board[{1, 1}] != nullptr);
    board.move(2, {3, 1}, Board::MoveDIR::Down);
            CHECK(board[{3, 1}] == nullptr);
            CHECK(board[{2, 1}] != nullptr);
            CHECK(board.has_soldiers(2) == true);

    board.move(2, {5, 5}, Board::MoveDIR::Down);
            CHECK(board[{5, 5}] == nullptr);
            CHECK(board[{4, 1}] != nullptr);
            CHECK(board.has_soldiers(2) == true);

    board.move(1, {0, 5}, Board::MoveDIR::Right);
            CHECK(board[{0, 5}] == nullptr);
            CHECK(board[{1, 5}] != nullptr);
            CHECK(board.has_soldiers(1) == true);

    board.move(1, {0, 1}, Board::MoveDIR::Up);
            CHECK(board[{0, 1}] == nullptr);
            CHECK(board[{1, 1}] != nullptr);
    board.move(1, {1, 1}, Board::MoveDIR::Right);
            CHECK(board[{1, 1}] == nullptr);
            CHECK(board[{1, 2}] != nullptr);
            CHECK(board.has_soldiers(1) == true);
    board.move(2, {3, 2}, Board::MoveDIR::Down);
            CHECK(board[{3, 2}] == nullptr);
            CHECK(board[{2, 2}] != nullptr);
    board.move(1, {0, 2}, Board::MoveDIR::Up);
            CHECK(board[{0, 2}]->health_points > board[{3, 2}]->health_points);
    board.move(2, {2, 2}, Board::MoveDIR::Right);
            CHECK(board[{0, 3}]->health_points == board[{3, 2}]->health_points);
            CHECK(board[{2, 2}] == nullptr);
            CHECK(board[{2, 3}] != nullptr);
    board.move(1, {1, 2}, Board::MoveDIR::Left);
            CHECK(board[{0, 1}]->health_points == board[{0, 1}]->health_points);
            CHECK(board[{1, 2}] == nullptr);
            CHECK(board[{1, 1}] != nullptr);
    board.move(2, {2, 3}, Board::MoveDIR::Left);
            CHECK(board[{2, 2}] == nullptr);
            CHECK(board[{2, 3}] != nullptr);
            CHECK_THROWS((board[{0, 1}]->health_points < board[{0, 3}]->health_points));
            CHECK_THROWS((board[{3, 3}]->health_points != board[{0, 2}]->health_points));
            CHECK_THROWS((board[{0, 3}]->health_points > board[{3, 2}]->health_points));
            CHECK(board[{0, 1}]->health_points < board[{0, 2}]->health_points);
            CHECK(board[{3, 3}]->health_points > board[{0, 3}]->health_points);
            CHECK(board[{3, 3}]->health_points == board[{0, 2}]->health_points);
            CHECK(board.has_soldiers(1) == true);

}

TEST_CASE ("There is no soldier") {
    Board board(8, 1);
            CHECK_THROWS(board.move(1, {0, 2}, Board::MoveDIR::Up));
            CHECK_THROWS(board.move(1, {0, 4}, Board::MoveDIR::Up));
            CHECK_THROWS(board.move(1, {3, 4}, Board::MoveDIR::Up));
    board.move(1, {1, 2}, Board::MoveDIR::Up);
            CHECK_THROWS(board.move(1, {1, 2}, Board::MoveDIR::Up));
    board.move(2, {7, 1}, Board::MoveDIR::Down);
            CHECK_THROWS(board.move(2, {7, 1}, Board::MoveDIR::Down));
    board.move(2, {6, 5}, Board::MoveDIR::Left);
            CHECK_THROWS(board.move(2, {6, 5}, Board::MoveDIR::Down));
    board.move(2, {6, 2}, Board::MoveDIR::Down);
            CHECK_THROWS(board.move(2, {6, 2}, Board::MoveDIR::Down));
}


TEST_CASE ("Commanders checks") {
    Board board(8, 8);

            CHECK(board.has_soldiers(1) == false);
            CHECK(board.has_soldiers(2) == false);

    //adding soldiers
    board[{0, 0}] = new SniperCommander(1);
    board[{0, 1}] = new FootCommander(1);
    board[{0, 2}] = new ParamedicCommander(1);
    board[{0, 3}] = new SniperCommander(1);
    board[{0, 4}] = new FootCommander(1);


    board[{7, 1}] = new FootCommander(2);
    board[{7, 4}] = new ParamedicCommander(2);
    board[{7, 5}] = new SniperCommander(2);
    board[{7, 2}] = new FootCommander(2);
    board[{7, 3}] = new SniperCommander(2);


            CHECK(board.has_soldiers(1) == true);
            CHECK(board.has_soldiers(2) == true);

            CHECK(board[{7, 1}]->damage_per_activity == 20);
            CHECK(board[{7, 4}]->damage_per_activity == 100);
            CHECK(board[{7, 5}]->damage_per_activity == 50);
            CHECK(board[{7, 2}]->damage_per_activity == 20);
            CHECK(board[{7, 3}]->damage_per_activity == 50);
            CHECK(board[{7, 1}]->damage_per_activity == 20);
            CHECK(board[{7, 4}]->damage_per_activity == 100);
            CHECK(board[{7, 5}]->damage_per_activity == 50);
            CHECK(board[{7, 2}]->damage_per_activity == 20);
            CHECK(board[{7, 3}]->damage_per_activity == 50);

            CHECK(board[{7, 1}]->health_points == 150);
            CHECK(board[{7, 4}]->health_points == 200);
            CHECK(board[{7, 5}]->health_points == 120);
            CHECK(board[{7, 2}]->health_points == 150);
            CHECK(board[{7, 3}]->health_points == 120);
            CHECK(board[{7, 1}]->health_points == 150);
            CHECK(board[{7, 4}]->health_points == 200);
            CHECK(board[{7, 5}]->health_points == 120);
            CHECK(board[{7, 2}]->health_points == 150);
            CHECK(board[{7, 3}]->health_points == 120);


            CHECK(board[{0, 0}]->damage_per_activity == 100);
            CHECK(board[{0, 1}]->damage_per_activity == 20);
            CHECK(board[{0, 2}]->damage_per_activity == 100);
            CHECK(board[{0, 3}]->damage_per_activity == 100);
            CHECK(board[{0, 4}]->damage_per_activity == 20);
            CHECK(board[{0, 0}]->damage_per_activity == 100);
            CHECK(board[{0, 1}]->damage_per_activity == 20);
            CHECK(board[{0, 2}]->damage_per_activity == 100);
            CHECK(board[{0, 3}]->damage_per_activity == 100);
            CHECK(board[{0, 4}]->damage_per_activity == 20);

            CHECK(board[{0, 0}]->health_points == 120);
            CHECK(board[{0, 1}]->health_points == 150);
            CHECK(board[{0, 2}]->health_points == 200);
            CHECK(board[{0, 3}]->health_points == 120);
            CHECK(board[{0, 4}]->health_points == 150);
            CHECK(board[{0, 0}]->health_points == 120);
            CHECK(board[{0, 1}]->health_points == 150);
            CHECK(board[{0, 2}]->health_points == 200);
            CHECK(board[{0, 3}]->health_points == 120);
            CHECK(board[{0, 4}]->health_points == 150);

}
