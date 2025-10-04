#include <iostream>
#include <queue>
#include <vector>

#define QUEEN 7
#define MAX_LINE 5

const int dr[4] = {0, 0, 1, -1};
const int dc[4] = {1, -1, 0, 0};

using namespace std;

vector<vector<char>> queen_board(MAX_LINE, vector<char>(MAX_LINE));
vector<vector<bool>> queen_world(MAX_LINE, vector<bool>(MAX_LINE, true));

vector<char> queens(QUEEN);
vector<int> q_idx(QUEEN);

void print_queen() {
    for (int r = 0; r < MAX_LINE; r++) {
        for (int c = 0; c < MAX_LINE; c++) {
            int q = 0;
            for (; q < QUEEN; q++) {
                if (q_idx[q] == r * 5 + c) {
                    cout << queen_board[r][c];
                    break;
                }
            }
            if (q == 7) cout << "-";
        }
        cout << endl;
    }
    cout << endl;
}

bool is_possible(vector<char> queens, int depth) {
    if (depth == 0) return 1;
    if (depth == 1) return 1;
    if (depth == 2) return 1;

    int cnt = 0;
    for (int i = 0; i < depth; i++) {
        if (queens[i] == 'S') cnt++;
    }

    if (depth == 4 && cnt < 1) return 0;
    if (depth == 5 && cnt < 2) return 0;
    if (depth == 6 && cnt < 3) return 0;
    if (depth == 7 && cnt < 4) return 0;

    return 1;
}

bool queen7(int irc) {
    int cnt = 1;
    queue<pair<int, int>> q;

    int ir = irc / 5;
    int ic = irc % 5;

    queen_world[ir][ic] = true;
    q.push({ir, ic});

    while (!q.empty()) {
        auto cur = q.front();
        q.pop();

        int cr = cur.first;
        int cc = cur.second;

        for (int i = 0; i < 4; i++) {
            int nr = cr + dr[i];
            int nc = cc + dc[i];

            bool c1 = (nr >= 0);
            bool c2 = (nr < MAX_LINE);
            bool c3 = (nc >= 0);
            bool c4 = (nc < MAX_LINE);

            if (c1 && c2 && c3 && c4)
                if (queen_world[nr][nc] == false) {
                    queen_world[nr][nc] = true;
                    q.push({nr, nc});
                    cnt++;
                }
        }
    }
    if (cnt == 7) return 1;
    return 0;
}

int pick_queen(int depth) {
    if (!is_possible(queens, depth)) return 0;

    if (depth == QUEEN) {
        queen_world.assign(MAX_LINE, vector<bool>(MAX_LINE, true));

        for (int q = 0; q < QUEEN; q++) {
            int r = q_idx[q] / 5;
            int c = q_idx[q] % 5;
            queen_world[r][c] = false;
        }
        if (queen7(q_idx[0])) {
            // print_queen();
            return 1;
        }
        return 0;
    }

    int result = 0;
    for (int i = 0; i < 25; i++) {
        if (depth > 0 && q_idx[depth - 1] >= i) continue;
        q_idx[depth] = i;
        queens[depth] = queen_board[i / 5][i % 5];
        result += pick_queen(depth + 1);
    }
    return result;
}

int main() {
    for (int r = 0; r < MAX_LINE; r++)
        for (int c = 0; c < MAX_LINE; c++)
            cin >> queen_board[r][c];

    cout << pick_queen(0);
    return 0;
}