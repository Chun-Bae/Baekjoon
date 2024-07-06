#include <algorithm>
#include <iostream>
#include <queue>
#include <vector>

#define INF 987654321
using namespace std;

vector<pair<int, int>> graph[801];
int N, E;

void init() {
    cin.tie(NULL);
    cout.tie(NULL);
    ios::sync_with_stdio(false);
}

void dijkstra(int start, vector<int>& dist) {
    fill(dist.begin(), dist.end(), INF);
    dist[start] = 0;
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    pq.push({0, start});
    while (!pq.empty()) {
        int cur = pq.top().second;
        int curDist = pq.top().first;
        pq.pop();
        if (curDist > dist[cur]) {
            continue;
        }
        for (auto& edge : graph[cur]) {
            int next = edge.first;
            int cost = edge.second;
            if (dist[next] > dist[cur] + cost) {
                dist[next] = dist[cur] + cost;
                pq.push({dist[next], next});
            }
        }
    }
}

int main() {
    init();
    cin >> N >> E;
    for (int i = 0; i < E; i++) {
        int a, b, c;
        cin >> a >> b >> c;
        graph[a].push_back({b, c});
        graph[b].push_back({a, c});
    }
    int v1, v2;
    cin >> v1 >> v2;

    vector<int> dist1(N + 1, INF);
    vector<int> distV1(N + 1, INF);
    vector<int> distV2(N + 1, INF);

    dijkstra(1, dist1);
    dijkstra(v1, distV1);
    dijkstra(v2, distV2);

    int path1 = dist1[v1] + distV1[v2] + distV2[N];
    int path2 = dist1[v2] + distV2[v1] + distV1[N];

    if (dist1[v1] == INF || distV1[v2] == INF || distV2[N] == INF) {
        path1 = INF;
    }
    if (dist1[v2] == INF || distV2[v1] == INF || distV1[N] == INF) {
        path2 = INF;
    }

    int result = min(path1, path2);
    if (result >= INF) {
        cout << -1 << '\n';
    } else {
        cout << result << '\n';
    }
    return 0;
}
