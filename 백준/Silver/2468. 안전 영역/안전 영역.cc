#include <algorithm>
#include <iostream>
#include <queue>
#include <vector>

const int dr[4] = {1, 0, -1, 0};
const int dc[4] = {0, 1, 0, -1};

using namespace std;

int main() {
    int N;
    cin >> N;
    vector<vector<int>> region(N, vector<int>(N));

    int max_depth = 0;
    for (int r = 0; r < N; r++) {
        for (int c = 0; c < N; c++) {
            cin >> region[r][c];
            max_depth = max(max_depth, region[r][c]);
        }
    }

    int safe_cnt = 1;

    for (int submerge = 1; submerge <= max_depth; submerge++) {
        vector<vector<int>> visited(N, vector<int>(N, 0));
        vector<vector<int>> board(N, vector<int>(N, 0));

        for (int r = 0; r < N; r++) {
            for (int c = 0; c < N; c++) {
                if (region[r][c] <= submerge) {
                    board[r][c] = 1;
                }
            }
        }

        int cnt = 0;
        for (int r = 0; r < N; r++) {
            for (int c = 0; c < N; c++) {
                if (board[r][c] == 0 && visited[r][c] == 0) {
                    queue<pair<int, int>> q;

                    int flag = 0;

                    q.push({r, c});
                    while (!q.empty()) {
                        auto [cr, cc] = q.front();
                        q.pop();
                        if (!flag) flag = 1;

                        for (int i = 0; i < 4; i++) {
                            int nr = cr + dr[i];
                            int nc = cc + dc[i];

                            if (nr >= 0 && nr < N && nc >= 0 && nc < N)
                                if (board[nr][nc] == 0 && visited[nr][nc] == 0) {
                                    visited[nr][nc] = 1;
                                    q.push({nr, nc});
                                }
                        }
                    }

                    // printf("--------\n");
                    // for (int a = 0; a < N; a++) {
                    //     for (int b = 0; b < N; b++) {
                    //         cout << visited[a][b] << " ";
                    //     }
                    //     cout << endl;
                    // }
                    if (flag) cnt++;
                }
            }
        }
        safe_cnt = max(cnt, safe_cnt);
    }
    cout << safe_cnt;
    return 0;
}
