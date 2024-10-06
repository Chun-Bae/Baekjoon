#include <algorithm>
#include <climits>
#include <iostream>
#include <queue>
#include <vector>

using namespace std;

typedef long long ll;
typedef vector<int> vec1;
typedef vector<vec1> vec2;
typedef vector<vec2> vec3;
typedef pair<int, int> pii;

void init() {
    cin.tie(NULL);
    cout.tie(NULL);
    ios::sync_with_stdio(false);
}
int N, M;
vector<vector<pii>> graph;

vec1 dijkstra(int start) {
    vec1 dist(N + 1, INT_MAX);
    priority_queue<pii, vector<pii>, greater<pii>> pq;

    dist[start] = 0;
    pq.push({0, start});

    while (!pq.empty()) {
        int currentDist = pq.top().first;
        int currentNode = pq.top().second;
        pq.pop();

        if (currentDist > dist[currentNode]) continue;

        for (auto &neighbor : graph[currentNode]) {
            int nextNode = neighbor.first;
            int weight = neighbor.second;

            if (dist[currentNode] + weight < dist[nextNode]) {
                dist[nextNode] = dist[currentNode] + weight;
                pq.push({dist[nextNode], nextNode});
            }
        }
    }

    return dist;
}

int main() {
    init();
    cin >> N >> M;
    graph.resize(N + 1);

    for (int i = 0; i < M; i++) {
        int A, B, C;
        cin >> A >> B >> C;
        graph[A].push_back({B, C});
        graph[B].push_back({A, C});
    }

    vec1 dist = dijkstra(1);

    cout << dist[N] << '\n';
    return 0;
}