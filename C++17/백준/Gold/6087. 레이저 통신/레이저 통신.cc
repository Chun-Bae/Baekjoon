#include <algorithm>
#include <iostream>
#include <queue>
#include <tuple>
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
const int dx[] = {0, 1, 0, -1};
const int dy[] = {1, 0, -1, 0};

int W, H;
char grid[100][100];
int dist[100][100][4];
vector<pair<int, int>> lasers;

struct Node {
    int x, y, dir, mirrors;

    bool operator<(const Node& other) const { return mirrors > other.mirrors; }
};

int bfs() {
    priority_queue<Node> pq;

    int sx = lasers[0].first, sy = lasers[0].second;
    int ex = lasers[1].first, ey = lasers[1].second;

    for (int i = 0; i < H; i++) {
        for (int j = 0; j < W; j++) {
            for (int d = 0; d < 4; d++) {
                dist[i][j][d] = INF;
            }
        }
    }

    for (int d = 0; d < 4; d++) {
        int nx = sx + dx[d], ny = sy + dy[d];
        if (nx >= 0 && nx < H && ny >= 0 && ny < W && grid[nx][ny] != '*') {
            pq.push({nx, ny, d, 0});
            dist[nx][ny][d] = 0;
        }
    }

    while (!pq.empty()) {
        Node cur = pq.top();
        pq.pop();

        int x = cur.x, y = cur.y, dir = cur.dir, mirrors = cur.mirrors;

        if (x == ex && y == ey) return mirrors;

        int nx = x + dx[dir], ny = y + dy[dir];
        if (nx >= 0 && nx < H && ny >= 0 && ny < W && grid[nx][ny] != '*') {
            if (dist[nx][ny][dir] > mirrors) {
                dist[nx][ny][dir] = mirrors;
                pq.push({nx, ny, dir, mirrors});
            }
        }

        for (int nd = 0; nd < 4; nd++) {
            if (nd == dir) continue;
            nx = x + dx[nd], ny = y + dy[nd];
            if (nx >= 0 && nx < H && ny >= 0 && ny < W && grid[nx][ny] != '*') {
                if (dist[nx][ny][nd] > mirrors + 1) {
                    dist[nx][ny][nd] = mirrors + 1;
                    pq.push({nx, ny, nd, mirrors + 1});
                }
            }
        }
    }

    return INF;
}

int main() {
    init();
    cin >> W >> H;

    for (int i = 0; i < H; i++) {
        for (int j = 0; j < W; j++) {
            cin >> grid[i][j];
            if (grid[i][j] == 'C') {
                lasers.push_back({i, j});
            }
        }
    }

    cout << bfs() << endl;
    return 0;
}