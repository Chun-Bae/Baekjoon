#include <iostream>
#include <limits>
#include <queue>
#include <vector>

using namespace std;
#define INF 1e9

vector<pair<int, int>> adj[101];
vector<int> items;
vector<int> dist(101, INF);

void dijkstra(int start) {
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    pq.push({0, start});
    dist[start] = 0;
    while (!pq.empty()) {
        int cost = pq.top().first;
        int here = pq.top().second;
        pq.pop();
        if (dist[here] < cost) continue;
        for (int i = 0; i < adj[here].size(); i++) {
            int there = adj[here][i].first;
            int nextDist = cost + adj[here][i].second;
            if (nextDist < dist[there]) {
                dist[there] = nextDist;
                pq.push({nextDist, there});
            }
        }
    }
}

void init() {
    cin.tie(NULL);
    cout.tie(NULL);
    ios::sync_with_stdio(false);
}

int main() {
    init();
    int n, m, r;
    cin >> n >> m >> r;
    items.resize(n + 1);
    for (int i = 1; i <= n; i++) {
        cin >> items[i];
    }
    for (int i = 0; i < r; i++) {
        int a, b, l;
        cin >> a >> b >> l;
        adj[a].push_back({b, l});
        adj[b].push_back({a, l});
    }

    int maxItem = 0;
    for (int i = 1; i <= n; i++) {
        dist = vector<int>(101, INF);
        dijkstra(i);
        int sum = 0;
        for (int j = 1; j <= n; j++) {
            if (dist[j] <= m) {
                sum += items[j];
            }
        }
        maxItem = max(maxItem, sum);
    }

    cout << maxItem << '\n';
    return 0;
}
