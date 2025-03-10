#include "GridGame.h"

GridGame::GridGame(int r, int c) {
    resizeRows(r);
    resizeCols(c);
    p_emptySpace = new char(' ');
    p_p1 = new char('X');
    p_p2 = new char('O');
    resetBoard();
}

GridGame::~GridGame() {
    delete p_p1;
    delete p_p2;
    delete p_emptySpace;
}


void GridGame::resizeRows(int r) {
    if(r > 0) {
        int prevSize = grid.size();
        grid.resize(r);
        for(int i = prevSize; i < grid.size(); i++)
            grid[i].resize(grid[0].size());
    } else {
        cout<<"Error sizing grid: please make sure row sizes are greater than zero"<<endl;
    }
}

void GridGame::resizeCols(int c) {
    if(c > 0)
        for(int i = 0; i < grid.size(); i++)
            grid[i].resize(c);
    else
        cout<<"Error sizing grid: please make sure column sizes are greater than zero"<<endl;
}

void GridGame::printGrid() {
    cout<<"  ";
    for(int i = 0; i < grid[0].size(); i++) {
        cout<<i + 1<<"  ";
    }
    cout<<endl;
    for(int i = 0; i < grid.size(); i++) {
        cout<<i + 1<<" ";
        for(int j = 0; j < grid[i].size() - 1; j++) {
            cout<<*grid[i][j]<<" |";
        }
        cout<<*grid[i][grid[i].size() - 1]<<endl;

        if(i != grid.size() - 1) {
            cout<<"  ";
            for(int j = 0; j < grid[i].size() - 1; j++) {
                cout<<"--|";
            }
            cout<<"--"<<endl;
        }
    }
}

int GridGame::getNumRows() {
    return grid.size();
}

int GridGame::getNumCols() {
    return grid[0].size();
}

char GridGame::getMarker(int r, int c) {
    return *grid[r - 1][c - 1];
}

void GridGame::setMarker(int r, int c, char m) {
    if(m == 'X')
        grid[r][c] = p_p1;
    else if(m == 'O')
        grid[r][c] = p_p2;
}

void GridGame::resetBoard() {
    for(int i = 0; i < grid.size(); i++) {
        for(int j = 0; j < grid[i].size(); j++) {
            grid[i][j] = p_emptySpace;
        }
    }
}
