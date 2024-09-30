#include <climits>
#include <iostream>
#include <tuple>
#include <vector>

using namespace std;

typedef long long ll;
typedef vector<int> vec1;
typedef vector<vec1> vec2;
typedef vector<vec2> vec3;

void init() {
    cin.tie(NULL);
    cout.tie(NULL);
    ios::sync_with_stdio(false);
}

const ll INF = LLONG_MAX;
int N, M;
vector<tuple<int, int, int>> edges;
vector<ll> dist;

bool bellmanFord(int start) {
    dist[start] = 0;

    for (int i = 0; i < N - 1; ++i) {
        for (auto& edge : edges) {
            int u, v, w;
            tie(u, v, w) = edge;
            if (dist[u] != INF && dist[u] + w < dist[v]) {
                dist[v] = dist[u] + w;
            }
        }
    }

    for (auto& edge : edges) {
        int u, v, w;
        tie(u, v, w) = edge;
        if (dist[u] != INF && dist[u] + w < dist[v]) {
            return false;  
        }
    }

    return true;  
}

int main() {
    init();
    cin >> N >> M;
    dist.resize(N + 1, INF);

    for (int i = 0; i < M; ++i) {
        int A, B, C;
        cin >> A >> B >> C;
        edges.push_back({A, B, C});
    }

    if (!bellmanFord(1)) {
        cout << -1 << endl;
    } else {
        for (int i = 2; i <= N; ++i) {
            if (dist[i] == INF) {
                cout << -1 << endl;
            } else {
                cout << dist[i] << endl;
            }
        }
    }

    return 0;
}