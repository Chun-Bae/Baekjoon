#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

typedef long long ll;
typedef vector<int> vec1;
typedef vector<vec1> vec2;
typedef vector<vec2> vec3;

void init() {
    cin.tie(NULL);
    cout.tie(NULL);
    ios::sync_with_stdio(false);
}
bool checkWin(const vector<char>& board, char player) {
    return (board[0] == player && board[1] == player && board[2] == player) || (board[3] == player && board[4] == player && board[5] == player) ||
           (board[6] == player && board[7] == player && board[8] == player) || (board[0] == player && board[3] == player && board[6] == player) ||
           (board[1] == player && board[4] == player && board[7] == player) || (board[2] == player && board[5] == player && board[8] == player) ||
           (board[0] == player && board[4] == player && board[8] == player) || (board[2] == player && board[4] == player && board[6] == player);
}
int main() {
    init();
    string input;
    while (cin >> input) {
        if (input == "end") break;

        vector<char> board(input.begin(), input.end());

        int countX = 0, countO = 0;

        for (char c : board) {
            if (c == 'X')
                countX++;
            else if (c == 'O')
                countO++;
        }

        bool xWins = checkWin(board, 'X');
        bool oWins = checkWin(board, 'O');

        if (countX < countO || countX > countO + 1 || (xWins && countX != countO + 1) || (oWins && countX != countO) || (xWins && oWins) ||
            (xWins == 0 && oWins == 0 && find(board.begin(), board.end(), '.') != board.end())) {
            cout << "invalid" << endl;
        } else {
            cout << "valid" << endl;
        }
    }
    return 0;
}
