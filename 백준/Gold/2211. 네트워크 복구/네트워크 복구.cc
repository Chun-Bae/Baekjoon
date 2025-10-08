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
    int N, M;
    cin >> N >> M;
    vector<vector<pair<int, int>>> adj(N + 1);
    vector<int> dist(N + 1, INF);
    vector<int> parent(N + 1);
    priority_queue<pair<int, int>, vector<pair<int, int>>, cmp> pq;

    for (int i = 1; i <= N; i++) {
        parent[i] = i;
    }

    for (int i = 0; i < M; i++) {
        int A, B, C;
        cin >> A >> B >> C;
        adj[A].push_back({B, C});
        adj[B].push_back({A, C});
    }

    dist[1] = 0;
    pq.push({1, 0});

    while (!pq.empty()) {
        auto [cur, d] = pq.top();
        pq.pop();

        if (dist[cur] != d) continue;

        for (auto [next, cost] : adj[cur]) {
            if (dist[next] > cost + d) {
                parent[next] = cur;
                dist[next] = cost + d;
                pq.push({next, cost + d});
            }
        }
    }
    cout << N - 1 << endl;
    for (int i = 2; i <= N; i++) {
        printf("%d %d\n", parent[i], i);
    }
}