#include <iostream>
#include <vector>

using namespace std;

vector<vector<int>> adj;
vector<int> subtree_size;

void init() {
    cin.tie(NULL);
    cout.tie(NULL);
    ios::sync_with_stdio(false);
}

void dfs(int node, int parent) {
    subtree_size[node] = 1; 
    for (int child : adj[node]) {
        if (child != parent) {
            dfs(child, node);
            subtree_size[node] += subtree_size[child];
        }
    }
}

int main() {
    init();
    int N, R, Q;
    cin >> N >> R >> Q;
    adj.resize(N + 1);
    subtree_size.resize(N + 1, 0);

    for (int i = 0; i < N - 1; i++) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    dfs(R, -1);

    for (int i = 0; i < Q; i++) {
        int U;
        cin >> U;
        cout << subtree_size[U] << "\n";
    }

    return 0;
}
