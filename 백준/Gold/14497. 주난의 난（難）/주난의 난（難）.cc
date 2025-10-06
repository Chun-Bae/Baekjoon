#include <deque>
#include <iostream>
#include <tuple>
#include <vector>

const int dr[4] = {1, 0, -1, 0};
const int dc[4] = {0, 1, 0, -1};

using namespace std;

int main() {
    int N, M;
    cin >> N >> M;
    int x1, y1, x2, y2;
    cin >> x1 >> y1 >> x2 >> y2;
    vector<vector<char>> classroom(N + 1, vector<char>(M + 1));
    vector<vector<int>> visited(N + 1, vector<int>(M + 1, 0));
    vector<vector<int>> dist(N + 1, vector<int>(M + 1));
    deque<tuple<int, int, int>> dq;
    pair<int, int> junan;
    pair<int, int> culprit;

    for (int r = 1; r <= N; r++) {
        for (int c = 1; c <= M; c++) {
            cin >> classroom[r][c];
            if (classroom[r][c] == '#')
                culprit = {r, c};
            if (classroom[r][c] == '*')
                junan = {r, c};
        }
    }
    auto [sr, sc] = junan;
    auto [cpr, cpc] = culprit;

    visited[sr][sc] = 1;
    dist[sr][sc] = 1;
    dq.push_front({sr, sc, 0});

    while (!dq.empty()) {
        auto [cr, cc, cost] = dq.front();
        dq.pop_front();


        for (int i = 0; i < 4; i++) {
            int nr = cr + dr[i];
            int nc = cc + dc[i];

            if (nr >= 1 && nr <= N && nc >= 1 && nc <= M)
                if (visited[nr][nc] == 0) {
                    visited[nr][nc] = 1;

                    if (classroom[nr][nc] == '0') {
                        dist[nr][nc] = cost;
                        dq.push_front({nr, nc, cost});
                    } else {
                        dist[nr][nc] = cost + 1;
                        dq.push_back({nr, nc, cost + 1});
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
    cout << dist[cpr][cpc];

    return 0;
}