#include <iostream>
#include <queue>
#include <vector>
using namespace std;

#define INF 1e9
#define MAX 100000

vector<int> dist(MAX + 1, INF);
priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;

int dijkstra(int start, int target) {
    dist[start] = 0;
    pq.push({0, start});

    while (!pq.empty()) {
        int current_dist = pq.top().first;
        int current = pq.top().second;
        pq.pop();

        if (current == target) return current_dist;
        if (current_dist > dist[current]) continue;

        vector<pair<int, int>> neighbors;
        if (current - 1 >= 0) neighbors.push_back({current_dist + 1, current - 1});
        if (current + 1 <= MAX) neighbors.push_back({current_dist + 1, current + 1});
        if (current * 2 <= MAX) neighbors.push_back({current_dist, current * 2});

        for (auto& neighbor : neighbors) {
            int next_dist = neighbor.first;
            int next = neighbor.second;

            if (next_dist < dist[next]) {
                dist[next] = next_dist;
                pq.push({next_dist, next});
            }
        }
    }

    return -1;
}

int main() {
    int N, K;
    cin >> N >> K;
    cout << dijkstra(N, K) << endl;

    return 0;
}
