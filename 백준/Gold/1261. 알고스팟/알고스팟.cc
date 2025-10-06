#include <algorithm>
#include <deque>
#include <iostream>
#include <limits>
#include <queue>
#include <tuple>
#include <vector>

#define INF std::numeric_limits<int>::max()
const int dr[4] = {1, 0, -1, 0};
const int dc[4] = {0, 1, 0, -1};

using namespace std;

int main() {
    int M, N;
    cin >> M >> N;
    vector<vector<char>> maze(N + 1, vector<char>(M + 1));
    vector<vector<int>> visited(N + 1, vector<int>(M + 1, 0));
    vector<vector<int>> dist(N + 1, vector<int>(M + 1, INF));
    for (int r = 1; r <= N; r++) {
        for (int c = 1; c <= M; c++) {
            cin >> maze[r][c];
        }
    }

    deque<tuple<int, int, int>> dq;

    dq.push_front({1, 1, 0});
    visited[1][1] = 1;
    dist[1][1] = 0;
    while (!dq.empty()) {
        auto cur = dq.front();
        dq.pop_front();

        int cr = get<0>(cur);
        int cc = get<1>(cur);
        int cost = get<2>(cur);

        if (cr == N && cc == M) break;

        for (int i = 0; i < 4; i++) {
            int nr = cr + dr[i];
            int nc = cc + dc[i];

            if (nr >= 1 && nr <= N && nc >= 1 && nc <= M) {
                if (visited[nr][nc] == 0) {
                    if (maze[nr][nc] == '0') {
                        dist[nr][nc] = cost;
                        visited[nr][nc] = 1;
                        dq.push_front({nr, nc, cost});
                    } else {
                        dist[nr][nc] = min(dist[nr][nc], cost + 1);
                        visited[nr][nc] = 1;
                        dq.push_back({nr, nc, cost + 1});
                    }
                }
            }
        }
    }
    // for (int r = 1; r <= N; r++) {
    //     for (int c = 1; c <= M; c++) {
    //         cout << dist[r][c] << " ";
    //     }
    //     cout << endl;
    // }
    cout<<dist[N][M];

    return 0;
}
