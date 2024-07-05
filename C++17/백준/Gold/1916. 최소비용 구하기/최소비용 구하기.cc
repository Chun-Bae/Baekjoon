#include <iostream>
#include <queue>
#include <vector>
#include <limits>

using namespace std;

vector<pair<int, int>> city[1001];
int N, M;

void dijkstra(int start, vector<int>& dist) {
    dist[start] = 0;
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    pq.push({0, start});

    while (!pq.empty()) {
        int curr = pq.top().second;
        int currDist = pq.top().first;
        pq.pop();

        if (currDist > dist[curr]) {
            continue;
        }

        for (auto& edge : city[curr]) {
            int next = edge.first;
            int cost = edge.second;
            if (dist[next] > dist[curr] + cost) {
                dist[next] = dist[curr] + cost;
                pq.push({dist[next], next});
            }
        }
    }
}

void init(){
    cin.tie(NULL);
    cout.tie(NULL);
    ios::sync_with_stdio(false);
}

int main(){
    init();
    cin >> N >> M;
    for (int i = 0; i < M; i++) {
        int a, b, c;
        cin >> a >> b >> c;
        city[a].push_back({b, c});
    }
    int start, end;
    cin >> start >> end;

    vector<int> dist(N + 1, numeric_limits<int>::max());
    dijkstra(start, dist);

    cout << dist[end] << '\n';
    return 0;
}
