#pragma once
#include "GridGame.h"

class TicTacToe : public GridGame {
public:
    TicTacToe();

    void playGame() override;
private:
    bool checkForWinner() override;
    bool checkRight(int r, int c);
    bool checkDown(int r, int c);
    bool checkDownRight(int r, int c);
    bool checkDownLeft(int r, int c);
    void makeMove(bool isP1Turn);
};