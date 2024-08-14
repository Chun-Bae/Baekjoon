#include <algorithm>
#include <cstring>  // memset을 위한 라이브러리
#include <iostream>
#include <tuple>
#include <vector>

using namespace std;

int dist[501];

bool bellmanFord(int n, vector<tuple<int, int, int>>& edges) {
    fill(dist, dist + n + 1, 0);

    for (int i = 1; i < n; i++) {
        for (auto& edge : edges) {
            int u, v, w;
            tie(u, v, w) = edge;
            if (dist[v] > dist[u] + w) {
                dist[v] = dist[u] + w;
            }
        }
    }

    for (auto& edge : edges) {
        int u, v, w;
        tie(u, v, w) = edge;
        if (dist[v] > dist[u] + w) {
            return true;
        }
    }

    return false;
}

void init() {
    cin.tie(NULL);
    cout.tie(NULL);
    ios::sync_with_stdio(false);
}

int main() {
    init();
    int TC;
    cin >> TC;

    while (TC--) {
        int n, m, w;
        cin >> n >> m >> w;

        vector<tuple<int, int, int>> edges;

        // 도로
        for (int i = 0; i < m; i++) {
            int u, v, t;
            cin >> u >> v >> t;
            edges.push_back(make_tuple(u, v, t));
            edges.push_back(make_tuple(v, u, t));
        }

        // 웜홀
        for (int i = 0; i < w; i++) {
            int u, v, t;
            cin >> u >> v >> t;
            edges.push_back(make_tuple(u, v, -t));
        }

        if (bellmanFord(n, edges)) {
            cout << "YES" << endl;
        } else {
            cout << "NO" << endl;
        }
    }

    return 0;
}
