#include <algorithm>
#include <iostream>
#include <limits>
#include <queue>
#include <vector>

#define INF std::numeric_limits<int>::max()
const int dr[4] = {1, 0, -1, 0};
const int dc[4] = {0, 1, 0, -1};

using namespace std;

struct cmp {
    bool operator()(const pair<int, int>& a, const pair<int, int>& b) {
        return a.second > b.second;
    }
};

int main() {
    for (int t = 1;; t++) {
        int N;
        cin >> N;
        if (N == 0) return 0;

        vector<vector<int>> rupee(N, vector<int>(N));
        vector<vector<pair<int, int>>> adj(N * N);
        vector<int> dist(N * N, INF);
        priority_queue<pair<int, int>, vector<pair<int, int>>, cmp> pq;
        for (int r = 0; r < N; r++) {
            for (int c = 0; c < N; c++) {
                cin >> rupee[r][c];
            }
        }
        for (int i = 0; i < N * N; i++) {
            int cr = i / N;
            int cc = i % N;
            for (int j = 0; j < 4; j++) {
                int nr = cr + dr[j];
                int nc = cc + dc[j];
                if (nr >= 0 && nr < N && nc >= 0 && nc < N) {
                    int cost = rupee[nr][nc];
                    if (cost >= 0) {
                        adj[cr * N + cc].push_back({nr * N + nc, cost});
                    }
                }
            }
        }
        // for (int i = 0; i < N * N; i++) {
        //     printf("(%d, %d): ", i / N, i % N);
        //     if (!adj[i].empty()) {
        //         for (auto e : adj[i]) {
        //             printf("[%d, %d]=%d ", e.first / N, e.first % N, e.second);
        //         }
        //         cout << endl;
        //     }
        // }

        dist[0] = rupee[0][0];
        pq.push({0, rupee[0][0]});
        while (!pq.empty()) {
            auto [cur, d] = pq.top();
            pq.pop();

            if (dist[cur] != d) continue;

            for (auto [next, cost] : adj[cur]) {
                if (dist[next] > cost + d) {
                    dist[next] = cost + d;
                    pq.push({next, cost + d});
                }
            }
        }

        printf("Problem %d: %d\n", t, dist[N * N - 1]);
    }

    return 0;
}