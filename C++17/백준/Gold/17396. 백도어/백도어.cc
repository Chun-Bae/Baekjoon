#include <iostream>
#include <limits>
#include <queue>
#include <vector>

using namespace std;

typedef long long ll;
typedef vector<int> vec1;
typedef vector<vec1> vec2;
typedef vector<vec2> vec3;
typedef pair<ll, int> pli;
const ll INF = numeric_limits<ll>::max();

void init() {
    cin.tie(NULL);
    cout.tie(NULL);
    ios::sync_with_stdio(false);
}

int main() {
    init();
    int N, M;
    cin >> N >> M;

    vec1 visible(N);
    for (int i = 0; i < N; i++) {
        cin >> visible[i];
    }

    vector<vector<pair<int, ll>>> graph(N);
    for (int i = 0; i < M; i++) {
        int a, b;
        ll t;
        cin >> a >> b >> t;
        if ((visible[a] == 0 || a == N - 1) && (visible[b] == 0 || b == N - 1)) {
            graph[a].emplace_back(b, t);
            graph[b].emplace_back(a, t);
        }
    }

    priority_queue<pli, vector<pli>, greater<pli>> pq;
    vector<ll> dist(N, INF);
    dist[0] = 0;
    pq.push({0, 0});

    while (!pq.empty()) {
        ll d = pq.top().first;
        int u = pq.top().second;
        pq.pop();

        if (d > dist[u]) continue;

        for (auto &edge : graph[u]) {
            int v = edge.first;
            ll weight = edge.second;

            if (dist[u] + weight < dist[v]) {
                dist[v] = dist[u] + weight;
                pq.push({dist[v], v});
            }
        }
    }

    if (dist[N - 1] == INF) {
        cout << -1 << endl;
    } else {
        cout << dist[N - 1] << endl;
    }

    return 0;
}