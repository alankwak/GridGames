#include "TicTacToe.h"

TicTacToe::TicTacToe() : GridGame(3, 3){
}

void TicTacToe::playGame() {
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

bool TicTacToe::checkForWinner() {
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

bool TicTacToe::checkRight(int r, int c) {
    if(c == 0) {
        char m = getMarker(r + 1, c + 1);
        if(m != ' ' && getMarker(r + 1, 2) == m && getMarker(r + 1, 3) == m) {
            return true;
        }
    }
    return false;
}

bool TicTacToe::checkDown(int r, int c) {
    if(r == 0) {
        char m = getMarker(r + 1, c + 1);
        if(m != ' ' && getMarker(2, c + 1) == m && getMarker(3, c + 1) == m) {
            return true;
        }
    }
    return false;
}

bool TicTacToe::checkDownRight(int r, int c) {
    if(r == 0 && c == 0) {
        char m = getMarker(r + 1, c + 1);
        if(m != ' ' && getMarker(2, 2) == m && getMarker(3, 3) == m) {
            return true;
        }
    }
    return false;
}

bool TicTacToe::checkDownLeft(int r, int c) {
    if(r == 0 && c == 2) {
        char m = getMarker(r + 1, c + 1);
        if(m != ' ' && getMarker(2, 2) == m && getMarker(3, 1) == m) {
            return true;
        }
    }
    return false;
}


void TicTacToe::makeMove(bool isP1Turn) {
    int r;
    int c;
    bool occ = true;
    while(occ) {
        if(isP1Turn) {
            cout << "Player 1: Please choose your move: \nRow: ";
            cin >> r;
            cout << "Col: ";
            cin >> c;
        } else {
            cout << "Player 2: Please choose your move: \nRow: ";
            cin >> r;
            cout << "Col: ";
            cin >> c;
        }
        if(r <= getNumRows() && r > 0 && c <= getNumCols() && c > 0 && getMarker(r, c) == ' ')
            occ = false;
        else
            cout<<"Invalid space, please make a different move"<<endl;
    }

    if(isP1Turn) {
        setMarker(r - 1, c - 1, 'X');
    } else {
        setMarker(r - 1, c - 1, 'O');
    }

    printGrid();
}