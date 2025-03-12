#pragma once
#include <vector>
#include <iostream>

using namespace std;

class GridGame {
public:
    GridGame(int r, int c);
    ~GridGame();

    int getNumRows();
    int getNumCols();
    char getMarker(int r, int c);

    virtual void playGame() = 0;
    void printGrid();
private:
    vector <vector <char*>> grid;
    char* p_emptySpace;
    char* p_p1;
    char* p_p2;
protected:
    void resizeRows(int r);
    void resizeCols(int c);
    void setMarker(int r, int c, char m);
    virtual bool checkForWinner() = 0;
    void resetBoard();
};