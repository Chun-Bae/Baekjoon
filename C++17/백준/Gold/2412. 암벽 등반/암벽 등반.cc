#include <algorithm>
#include <cmath>
#include <iostream>
#include <queue>
#include <map>
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
struct Position {
    int x, y;
    int moves;
};
int main() {
    init();
    int n, T;
    cin >> n >> T;

    vector<pair<int, int>> points(n);
    for (int i = 0; i < n; i++) {
        cin >> points[i].first >> points[i].second;
    }

    map<int, vector<int>> y_map;
    for (const auto& point : points) {
        y_map[point.second].push_back(point.first);
    }

    queue<Position> q;
    map<int, map<int, bool>> visited;

    q.push({0, 0, 0});
    visited[0][0] = true;

    while (!q.empty()) {
        Position pos = q.front();
        q.pop();

        if (pos.y >= T) {
            cout << pos.moves << endl;
            return 0;
        }

        for (int dy = -2; dy <= 2; dy++) {
            int new_y = pos.y + dy;
            if (y_map.find(new_y) == y_map.end()) continue;

            for (int nx : y_map[new_y]) {
                if (abs(pos.x - nx) <= 2 && !visited[nx][new_y]) {
                    q.push({nx, new_y, pos.moves + 1});
                    visited[nx][new_y] = true;
                }
            }
        }
    }

    cout << -1 << endl;
    return 0;
}