#include <algorithm>
#include <deque>
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

const int INF = 1e9;
int n;
vec2 grid;
vec2 dist;
int dx[4] = {-1, 1, 0, 0};
int dy[4] = {0, 0, -1, 1};

void bfs() {
    deque<pair<int, int>> dq;
    dq.push_front({0, 0});
    dist[0][0] = 0;

    while (!dq.empty()) {
        int x = dq.front().first;
        int y = dq.front().second;
        dq.pop_front();

        for (int i = 0; i < 4; i++) {
            int nx = x + dx[i];
            int ny = y + dy[i];

            if (nx >= 0 && nx < n && ny >= 0 && ny < n) {
                int cost = dist[x][y] + (grid[nx][ny] == 0 ? 1 : 0);
                if (cost < dist[nx][ny]) {
                    dist[nx][ny] = cost;
                    if (grid[nx][ny] == 0) {
                        dq.push_back({nx, ny});
                    } else {
                        dq.push_front({nx, ny});
                    }
                }
            }
        }
    }
}

int main() {
    init();

    cin >> n;
    grid.resize(n, vec1(n));
    dist.assign(n, vec1(n, INF));

    for (int i = 0; i < n; i++) {
        string line;
        cin >> line;
        for (int j = 0; j < n; j++) {
            grid[i][j] = line[j] - '0';
        }
    }

    bfs();
    cout << dist[n - 1][n - 1] << endl;
    return 0;
}
