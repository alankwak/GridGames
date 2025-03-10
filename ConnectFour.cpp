#include "ConnectFour.h"

ConnectFour::ConnectFour() : GridGame(6, 7) {}

ConnectFour::ConnectFour(int r, int c) : GridGame(6, 7) {
    resizeRows(r);
    resizeCols(c);
    resetBoard();
}

void ConnectFour::playGame() {
    bool isWinner = false;
    bool p1Turn = true;
    printGrid();
    while(!isWinner) {
        makeMove(p1Turn);
        p1Turn = !p1Turn;

        isWinner = checkForWinner();
    }
    resetBoard();
}

bool ConnectFour::checkForWinner() {
    bool fullBoard = true;
    for(int i = 0; i < getNumRows(); i++) {
        for(int j = 0; j < getNumCols(); j++) {
            if(checkDown(i, j) || checkDownLeft(i, j) || checkDownRight(i, j) || checkRight(i, j)) {
                if(getMarker(i + 1, j + 1) == 'X')
                    cout<<"Player 1 wins!"<<endl;
                else
                    cout<<"Player 2 wins!"<<endl;
                return true;
            }
            if(getMarker(i + 1, j + 1) == ' ') {
                fullBoard = false;
            }
        }
    }
    if(fullBoard) {
        cout<<"It's a draw!"<<endl;
        return true;
    }
    return false;
}

bool ConnectFour::checkRight(int r, int c) {
    if(c <= getNumCols() - 4) {
        char m = getMarker(r + 1, c + 1);
        if(m != ' ' && getMarker(r + 1, c + 2) == m && getMarker(r + 1, c + 3) == m && getMarker(r + 1, c + 4) == m) {
            return true;
        }
    }
    return false;
}

bool ConnectFour::checkDown(int r, int c) {
    if(r <= getNumRows() - 4) {
        char m = getMarker(r + 1, c + 1);
        if(m != ' ' && getMarker(r + 2, c + 1) == m && getMarker(r + 3, c + 1) == m && getMarker(r + 4, c + 1) == m) {
            return true;
        }
    }
    return false;
}

bool ConnectFour::checkDownRight(int r, int c) {
    if(r <= getNumRows() - 4 && c <= getNumCols() - 4) {
        char m = getMarker(r + 1, c + 1);
        if(m != ' ' && getMarker(r + 2, c + 2) == m && getMarker(r + 3, c + 3) == m && getMarker(r + 4, c + 4) == m) {
            return true;
        }
    }
    return false;
}

bool ConnectFour::checkDownLeft(int r, int c) {
    if(r <= getNumRows() - 4 && c >= 3) {
        char m = getMarker(r + 1, c + 1);
        if(m != ' ' && getMarker(r + 2, c) == m && getMarker(r + 3, c - 1) == m && getMarker(r + 4, c - 2) == m) {
            return true;
        }
    }
    return false;
}

void ConnectFour::makeMove(bool isP1Turn) {
    int c;
    int bottomRow;
    bool occ = true;
    while(occ) {
        bottomRow = getNumRows();
        if(isP1Turn) {
            cout << "Player 1: Please choose your move: \nCol: ";
            cin >> c;
        } else {
            cout << "Player 2: Please choose your move: \nCol: ";
            cin >> c;
        }
        if(c <= getNumCols() && c > 0) {
            while (bottomRow > 0) {
                if (getMarker(bottomRow, c) == ' ') {
                    occ = false;
                    break;
                }
                bottomRow--;
            }
            if(bottomRow == 0)
                cout<<"Column is full, please choose a different move"<<endl;
        } else {
            cout<<"Invalid column, please choose a different move"<<endl;
        }

    }

    if(isP1Turn) {
        setMarker(bottomRow - 1, c - 1, 'X');
    } else {
        setMarker(bottomRow - 1, c - 1, 'O');
    }

    printGrid();
}
