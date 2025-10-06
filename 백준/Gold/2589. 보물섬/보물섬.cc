#include <algorithm>
#include <iostream>
#include <queue>
#include <tuple>
#include <vector>

const int dr[4] = {1, 0, -1, 0};
const int dc[4] = {0, 1, 0, -1};
using namespace std;

int main() {
    int L, W;
    cin >> L >> W;
    vector<vector<char>> treasure(L + 1, vector<char>(W + 1));
    vector<vector<bool>> visited(L + 1, vector<bool>(W + 1, 0));

    for (int r = 1; r <= L; r++) {
        for (int c = 1; c <= W; c++) {
            cin >> treasure[r][c];
        }
    }
    int max_dist = 0;

    for (int r = 1; r <= L; r++) {
        for (int c = 1; c <= W; c++) {
            if (treasure[r][c] != 'L') continue;
            queue<tuple<int, int, int>> q;

            visited.assign(L + 1, vector<bool>(W + 1, 0));
            visited[r][c] = 1;
            q.push({r, c, 0});
            while (!q.empty()) {
                auto [cr, cc, dist] = q.front();
                q.pop();

                for (int i = 0; i < 4; i++) {
                    int nr = cr + dr[i];
                    int nc = cc + dc[i];

                    if (nr >= 1 && nr <= L && nc >= 1 && nc <= W) {
                        if (visited[nr][nc] == 0 && treasure[nr][nc] == 'L') {
                            visited[nr][nc] = 1;
                            max_dist = max(dist + 1, max_dist);
                            q.push({nr, nc, dist + 1});
                        }
                    }
                }
            }
        }
    }
    cout << max_dist;

    return 0;
}