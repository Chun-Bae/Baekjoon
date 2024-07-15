#include <algorithm>
#include <climits>
#include <iostream>
#include <queue>
#include <tuple>
#include <vector>

using namespace std;

const int INF = INT_MAX;
const vector<pair<int, int>> directions[] = {
    {{-1, 0}, {1, 0}},                  // 3K+1 번째 이동 (상, 하)
    {{0, -1}, {0, 1}},                  // 3K+2 번째 이동 (좌, 우)
    {{-1, 0}, {1, 0}, {0, -1}, {0, 1}}  // 3K 번째 이동 (상, 하, 좌, 우)
};
int N, M;
pair<int, int> S, E;
vector<vector<int>> labyrinth;

void dijkstra() {
    vector<vector<vector<int>>> dist(N + 1, vector<vector<int>>(M + 1, vector<int>(3, INF)));
    priority_queue<tuple<int, int, int, int>, vector<tuple<int, int, int, int>>, greater<>> pq;

    dist[S.first][S.second][0] = 0;
    pq.push(make_tuple(0, S.first, S.second, 0));

    while (!pq.empty()) {
        int current_dist, x, y, state;
        tie(current_dist, x, y, state) = pq.top();
        pq.pop();

        if (current_dist > dist[x][y][state]) continue;

        for (const auto& dir : directions[state]) {
            int nx = x + dir.first;
            int ny = y + dir.second;
            int nstate = (state + 1) % 3;

            if (nx >= 1 && nx <= N && ny >= 1 && ny <= M && labyrinth[nx][ny] != -1) {
                int new_dist = current_dist + labyrinth[nx][ny];

                if (new_dist < dist[nx][ny][nstate]) {
                    dist[nx][ny][nstate] = new_dist;
                    pq.push(make_tuple(new_dist, nx, ny, nstate));
                }
            }
        }
    }

    int result = min({dist[E.first][E.second][0], dist[E.first][E.second][1], dist[E.first][E.second][2]});
    if (result == INF) {
        cout << -1 << endl;
    } else {
        cout << result << endl;
    }
}

void init() {
    cin.tie(NULL);
    cout.tie(NULL);
    ios::sync_with_stdio(false);
}

int main() {
    init();
    cin >> N >> M;
    cin >> S.first >> S.second >> E.first >> E.second;

    labyrinth.resize(N + 1, vector<int>(M + 1));

    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= M; j++) {
            cin >> labyrinth[i][j];
        }
    }
    dijkstra();
    return 0;
}