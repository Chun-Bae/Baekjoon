#include <algorithm>
#include <iostream>
#include <vector>
#define INF 1e9

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

int main() {
    init();
    int N, W, P;
    cin >> N >> W >> P;

    vec2 dist(N + 1, vec1(N + 1, INF));

    for (int i = 1; i <= N; i++) {
        dist[i][i] = 0;
    }

    for (int i = 0; i < W; i++) {
        int u, v, time;
        cin >> u >> v >> time;
        dist[u][v] = time;
        dist[v][u] = time;
    }

    for (int k = 1; k <= N; k++) {
        for (int i = 1; i <= N; i++) {
            for (int j = 1; j <= N; j++) {
                dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
            }
        }
    }
    for (int i = 0; i < P; i++) {
        int source, destination;
        cin >> source >> destination;
        cout << dist[source][destination] << endl;
    }

    return 0;
}