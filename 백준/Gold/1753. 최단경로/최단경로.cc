#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#define INF 1e9

using namespace std;

void init() {
    cin.tie(NULL);
    cout.tie(NULL);
    ios::sync_with_stdio(false);
}

void dijkstra(int start, int V, vector<vector<pair<int, int>>> &adj) {
    vector<int> dist(V + 1, INF);
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    pq.push({0, start});
    dist[start] = 0;

    while (!pq.empty()) {
        int cost = pq.top().first;
        int cur = pq.top().second;
        pq.pop();

        if (dist[cur] < cost) continue;

        for (auto &edge : adj[cur]) {
            int next = edge.first;
            int nextDist = cost + edge.second;

            if (nextDist < dist[next]) {
                dist[next] = nextDist;
                pq.push({nextDist, next});
            }
        }
    }

    for (int i = 1; i <= V; i++) {
        if (dist[i] == INF)
            cout << "INF" << '\n';
        else
            cout << dist[i] << '\n';
    }
}

int main() {
    init();
    int V, E;
    int K;
    cin >> V >> E;
    cin >> K;

    vector<vector<pair<int, int>>> adj(V + 1);
    for (int i = 0; i < E; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        adj[u].push_back({v, w});
    }
    
    dijkstra(K, V, adj);

    return 0;
}
