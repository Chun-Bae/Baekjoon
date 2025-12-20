#include <iostream>
#include <queue>
#include <tuple>
#include <vector>

using namespace std;

const int dr[4] = {1, 0, -1, 0};
const int dc[4] = {0, 1, 0, -1};

int main() {
    // 정의
    int N, M;
    vector<vector<char>> board;
    vector<vector<vector<vector<bool>>>> visited;

    pair<int, int> red;
    pair<int, int> blue;
    pair<int, int> hole;

    queue<pair<int, int>> qr;
    queue<pair<int, int>> qb;
    queue<int> qcnt;

    // 입력
    cin >> N >> M;
    board.assign(N, vector<char>(M, 0));
    visited.assign(N, vector<vector<vector<bool>>>(
        M, vector<vector<bool>>(N, vector<bool>(M, false))));

    for (int r = 0; r < N; r++) {
        for (int c = 0; c < M; c++) {
            cin >> board[r][c];
            if (board[r][c] == 'R') {
                red = {r, c};
                board[r][c] = '.';
            }
            if (board[r][c] == 'B') {
                blue = {r, c};
                board[r][c] = '.';
            }
            if (board[r][c] == 'O')
                hole = {r, c};
        }
    }

    qr.push(red);
    qb.push(blue);
    qcnt.push(1);

    visited[red.first][red.second][blue.first][blue.second] = true;

    auto move = [&](pair<int, int> cur, int dir) {
        int r = cur.first;
        int c = cur.second;
        int dist = 0;
        while (true) {
            int nr = r + dr[dir];
            int nc = c + dc[dir];
            if (board[nr][nc] == '#')
                break;
            r = nr;
            c = nc;
            dist++;
            if (board[r][c] == 'O')
                return make_tuple(make_pair(r, c), dist, true);
        }
        return make_tuple(make_pair(r, c), dist, false);
    };

    while (!qr.empty()) {
        // crr = current red row
        // crc = current red column
        // cbr = current blue row
        // cbc = current blue column
        auto [crr, crc] = qr.front();
        qr.pop();
        auto [cbr, cbc] = qb.front();
        qb.pop();
        int cnt = qcnt.front();
        qcnt.pop();

        if (cnt > 10)
            break;

        for (int i = 0; i < 4; i++) {
            auto [nred, rdist, redHole] = move({crr, crc}, i);
            auto [nblue, bdist, blueHole] = move({cbr, cbc}, i);

            if (blueHole)
                continue;
            if (redHole) {
                cout << cnt;
                return 0;
            }

            // 겹치면 더 많이 움직인 구슬을 한 칸 뒤로
            if (nred == nblue) {
                if (rdist > bdist) {
                    nred.first -= dr[i];
                    nred.second -= dc[i];
                } else {
                    nblue.first -= dr[i];
                    nblue.second -= dc[i];
                }
            }

            if (!visited[nred.first][nred.second][nblue.first][nblue.second]) {
                visited[nred.first][nred.second][nblue.first][nblue.second] = true;
                qr.push(nred);
                qb.push(nblue);
                qcnt.push(cnt + 1);
            }
        }
    }

    cout << -1;
    return 0;
}