#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

typedef long long ll;

void init() {
    cin.tie(NULL);
    cout.tie(NULL);
    ios::sync_with_stdio(false);
}

int Count(const vector<string>& board, int startX, int startY, bool startW) {
    int reCount = 0;
    char color = startW ? 'W' : 'B';

    for (int i = 0; i < 8; ++i) {
        for (int j = 0; j < 8; ++j) {
            if (board[startX + i][startY + j] != color) {
                ++reCount;
            }
            color = (color == 'W') ? 'B' : 'W';
        }
        color = (color == 'W') ? 'B' : 'W';
    }
    return reCount;
}

int main() {
    init();
    int N, M;
    cin >> N >> M;
    vector<string> board(N);

    for (int i = 0; i < N; ++i) {
        cin >> board[i];
    }

    int minC = 64;

    for (int i = 0; i <= N - 8; ++i) {
        for (int j = 0; j <= M - 8; ++j) {
            int reWhite = Count(board, i, j, true);
            int reBlack = Count(board, i, j, false);
            minC = min(minC, min(reWhite, reBlack));
        }
    }

    cout << minC << endl;
    return 0;
}
