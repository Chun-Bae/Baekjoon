#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#define INF 1000000000

using namespace std;

vector<pair<int, int>> adj[1001];
vector<int> dist(1001, INF);
vector<int> parent(1001, -1);

void init() {
    cin.tie(NULL);
    cout.tie(NULL);
    ios::sync_with_stdio(false);
}

void dijkstra(int start) {
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    pq.push({0, start});
    dist[start] = 0;
    while (!pq.empty()) {
        int cost = pq.top().first;
        int here = pq.top().second;
        pq.pop();
        if (dist[here] < cost) continue;
        for (auto &edge : adj[here]) {
            int there = edge.first;
            int nextDist = cost + edge.second;
            if (dist[there] > nextDist) {
                dist[there] = nextDist;
                pq.push({nextDist, there});
                parent[there] = here;
            }
        }
    }
}

vector<int> getPath(int start, int end) {
    vector<int> path;
    for (int v = end; v != start; v = parent[v]) {
        path.push_back(v);
    }
    path.push_back(start);
    reverse(path.begin(), path.end());
    return path;
}

int main() {
    init();
    int n, m;
    cin >> n >> m;
    for (int i = 0; i < m; i++) {
        int a, b, c;
        cin >> a >> b >> c;
        adj[a].push_back({b, c});
            }
    int start, end;
    cin >> start >> end;
    dijkstra(start);
    cout << dist[end] << '\n';
    vector<int> path = getPath(start, end);
    cout << path.size() << '\n';
    for (int city : path) {
        cout << city << " ";
    }
    cout << '\n';
    return 0;
}
