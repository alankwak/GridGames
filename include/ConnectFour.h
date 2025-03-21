#pragma once
#include "GridGame.h"

class ConnectFour : public GridGame {
public:
    ConnectFour();
    ConnectFour(int r, int c);

    void playGame() override;
private:
    bool checkForWinner() override;
    bool checkRight(int r, int c);
    bool checkDown(int r, int c);
    bool checkDownRight(int r, int c);
    bool checkDownLeft(int r, int c);
    void makeMove(bool isP1Turn);
};
