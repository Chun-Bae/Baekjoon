#include <algorithm>
#include <cmath>
#include <iostream>
#include <vector>

using namespace std;

const int MAX_LOG = 17;

int N, M;
vector<vector<int>> tree;
vector<vector<int>> parent;
vector<int> visited;
vector<int> depth;

void dfs(int node, int pnode) {
    parent[node][0] = pnode;
    depth[node] = (pnode == 0 ? 0 : depth[pnode] + 1);

    for (int i = 1; i < MAX_LOG; i++) {
        int mid = parent[node][i - 1];
        parent[node][i] = (mid ? parent[mid][i - 1] : 0);
    }

    visited[node] = 1;
    for (int n : tree[node]) {
        if (n == pnode) continue;
        if (!visited[n])
            dfs(n, node);
    }
}

int lift(int v, int k) {
    for (int i = 0; i < MAX_LOG; i++) {
        if (k & (1 << i)) {
            v = parent[v][i];
            if (v == 0) break;
        }
    }
    return v;
}

int lca(int a, int b) {
    if (depth[a] < depth[b]) swap(a, b);
    a = lift(a, depth[a] - depth[b]);

    if (a == b) return a;
    for (int i = MAX_LOG - 1; i >= 0; i--) {
        if (parent[a][i] != parent[b][i]) {
            a = parent[a][i];
            b = parent[b][i];
        }
    }

    return parent[a][0];
}

int main() {
    cin >> N;
    tree.assign(N + 1, {});
    parent.assign(N + 1, vector<int>(MAX_LOG, 0));
    visited.assign(N + 1, 0);
    depth.assign(N + 1, 0);

    for (int i = 0; i < N - 1; i++) {
        int u, v;
        cin >> u >> v;
        tree[u].push_back(v);
        tree[v].push_back(u);
    }

    dfs(1, 0);

    cin >> M;
    while (M--) {
        int a, b;
        cin >> a >> b;
        cout << lca(a, b) << "\n";
    }
    return 0;
}