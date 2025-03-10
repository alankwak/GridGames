#pragma once
#include "GridGame.h"

class TicTacToe : public GridGame {
public:
    TicTacToe();

    void playGame();
private:
    bool checkForWinner();
    bool checkRight(int r, int c);
    bool checkDown(int r, int c);
    bool checkDownRight(int r, int c);
    bool checkDownLeft(int r, int c);
    void makeMove(bool isP1Turn);
};