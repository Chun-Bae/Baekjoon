#include <algorithm>
#include <cmath>
#include <iostream>
#include <vector>

using namespace std;

typedef long long ll;
typedef vector<int> vec1;
typedef vector<vec1> vec2;
typedef vector<vec2> vec3;
const int MAX_N = 40000;
const int LOG = 16;                      // log2(40000)보다 큰 값
vector<pair<int, int>> tree[MAX_N + 1];  // 트리 저장 (연결된 노드와 거리)
int parent[MAX_N + 1][LOG];              // 각 노드의 2^i번째 부모 (이진 점프)
int depth[MAX_N + 1];                    // 각 노드의 깊이
int dist[MAX_N + 1];                     // 루트에서 각 노드까지의 거리
int N, M;

void dfs(int node, int par, int dep, int d) {
    depth[node] = dep;
    parent[node][0] = par;
    dist[node] = d;
    for (auto &edge : tree[node]) {
        int next = edge.first;
        int next_dist = edge.second;
        if (next != par) {
            dfs(next, node, dep + 1, d + next_dist);
        }
    }
}

void buildParent() {
    for (int j = 1; j < LOG; j++) {
        for (int i = 1; i <= N; i++) {
            if (parent[i][j - 1] != -1) {
                parent[i][j] = parent[parent[i][j - 1]][j - 1];
            }
        }
    }
}

int lca(int u, int v) {
    // 항상 u가 더 깊도록 설정
    if (depth[u] < depth[v]) swap(u, v);

    // 깊이 맞추기
    for (int i = LOG - 1; i >= 0; i--) {
        if (depth[u] - depth[v] >= (1 << i)) {
            u = parent[u][i];
        }
    }

    if (u == v) return u;

    for (int i = LOG - 1; i >= 0; i--) {
        if (parent[u][i] != parent[v][i]) {
            u = parent[u][i];
            v = parent[v][i];
        }
    }

    return parent[u][0];
}

void init() {
    cin.tie(NULL);
    cout.tie(NULL);
    ios::sync_with_stdio(false);
}

int main() {
    init();
    cin >> N;
    for (int i = 0; i < N - 1; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        tree[u].emplace_back(v, w);
        tree[v].emplace_back(u, w);
    }

    for (int i = 1; i <= N; i++) {
        for (int j = 0; j < LOG; j++) {
            parent[i][j] = -1;
        }
    }

    dfs(1, -1, 0, 0);

    buildParent();

    cin >> M;
    for (int i = 0; i < M; i++) {
        int u, v;
        cin >> u >> v;
        int ancestor = lca(u, v);
        int distance = dist[u] + dist[v] - 2 * dist[ancestor];
        cout << distance << '\n';
    }

    return 0;
}