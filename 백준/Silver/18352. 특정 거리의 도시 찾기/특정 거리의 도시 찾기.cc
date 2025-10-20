#include <algorithm>
#include <iostream>
#include <limits>
#include <queue>
#include <vector>

const int INF = std::numeric_limits<int>::max();
using namespace std;

struct cmp {
    bool operator()(pair<int, int> a, pair<int, int> b) {
        return a.second > b.second;
    }
};

int main() {
    int N, M, K, X;
    cin >> N >> M >> K >> X;

    vector<vector<pair<int, int>>> city(N + 1, vector<pair<int, int>>());
    vector<int> dist(N + 1, INF);
    priority_queue<pair<int, int>, vector<pair<int, int>>, cmp> pq;

    for (int i = 0; i < M; i++) {
        int A, B;
        cin >> A >> B;
        city[A].push_back({B, 1});
    }

    dist[X] = 0;
    pq.push({X, 0});
    while (!pq.empty()) {
        auto [cur, cost] = pq.top();
        pq.pop();

        if (dist[cur] != cost) continue;

        for (auto [next, d] : city[cur]) {
            if (dist[next] > cost + d) {
                dist[next] = cost + d;
                pq.push({next, cost + d});
            }
        }
    }

    vector<int> target;
    for (int i = 1; i <= N; i++) {
        if (dist[i] == K) target.push_back(i);
    }
    if (target.size()) {
        for (int t : target) {
            cout << t << '\n';
        }
    } else {
        cout << -1;
    }

    return 0;
}