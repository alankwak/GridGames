#include <limits>
#include "TicTacToe.h"
#include "ConnectFour.h"

using namespace std;

int main() {
    cout<<"Which game would you like to play?"
          "\n\t1 - TicTacToe"
          "\n\t2 - ConnectFour"<<endl;
    string gameType;
    while(gameType != "1" && gameType != "2") {
        cin >> gameType;
    }
    if(gameType=="1") {
        bool playing = true;
        TicTacToe t;
        while(playing) {
            t.playGame();
            cout << "Play again? y/n\n";
            string i;
            cin >> i;
            if (tolower(i[0]) != 'y')
                playing = false;
        }
    }
    else if(gameType=="2"){
        bool playing = true;
        int c = -1, r = -1;
        cout<<"What size board would you like to play with? (standard is 7 cols x 6 rows)"
              "\nNumber of columns: ";
        while(true) {
            if(cin >> c && c > 0) {
                break;
            }
            else {
                cout<<"Please make sure the number of columns is valid (integer > 0). \nNumber of columns: ";
                cin.clear();
                cin.ignore( numeric_limits<streamsize>::max(), '\n');
            }
        }
        cout<<"Number of rows: ";
        while(true) {
            if(cin >> r && r > 0) {
                break;
            }
            else {
                cout<<"Please make sure the number of rows is valid (integer > 0). \nNumber of rows: ";
                cin.clear();
                cin.ignore( numeric_limits<streamsize>::max(), '\n');
            }
        }
        ConnectFour cf(r, c);
        while(playing) {
            cf.playGame();
            cout << "Play again? y/n\n";
            string i;
            cin >> i;
            if (tolower(i[0]) != 'y')
                playing = false;
        }
    }

    return 0;
}
