#include <algorithm>
#include <iostream>
#include <limits>
#include <queue>
#include <vector>
#define INF std::numeric_limits<int>::max()

using namespace std;

struct cmp {
    bool operator()(const pair<int, int>& a, const pair<int, int>& b) {
        return a.second > b.second;
    }
};

int main() {
    int N, M, K, X;
    cin >> N >> M >> K >> X;
    vector<vector<pair<int, int>>> adj(N + 1);
    vector<int> dist(N + 1, INF);
    priority_queue<pair<int, int>, vector<pair<int, int>>, cmp> pq;
    for (int i = 0; i < M; i++) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back({v, 1});
    }

    dist[X] = 0;

    pq.push({X, 0});
    while (!pq.empty()) {
        auto [cur, cost] = pq.top();
        pq.pop();

        if (dist[cur] != cost) continue;

        for (auto [next, d] : adj[cur]) {
            if (dist[next] > d + cost) {
                dist[next] = d + cost;
                pq.push({next, d + cost});
            }
        }
    }
    bool found = false;
    for (int i = 1; i <= N; i++) {
        if (dist[i] == K) {
            found = true;
            cout << i << "\n";
        }
    }
    if (!found) {
        cout << -1;
    }

    return 0;
}
