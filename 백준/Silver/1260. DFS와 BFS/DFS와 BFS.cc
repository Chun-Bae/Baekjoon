#include <algorithm>
#include <iostream>
#include <queue>
#include <vector>

using namespace std;

int N, M, V;
vector<vector<int>> adj;
vector<int> visited;

void dfs(int cur) {
    cout << cur << " ";
    for (int next : adj[cur]) {
        if (!visited[next]) {
            visited[next] = 1;
            dfs(next);
        }
    }
    return;
}

int main() {
    cin >> N >> M >> V;
    adj.assign(N + 1, {});
    visited.assign(N + 1, 0);

    for (int i = 0; i < M; i++) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    for (int i = 1; i <= N; i++) {
        sort(adj[i].begin(), adj[i].end());
    }
    /// DFS
    visited.assign(N + 1, 0);
    visited[V] = 1;
    dfs(V);
    cout << endl;
    /// BFS
    visited.assign(N + 1, 0);
    queue<int> q;

    q.push(V);
    visited[V] = 1;
    while (!q.empty()) {
        int cur = q.front();
        q.pop();
        cout << cur << " ";

        for (int next : adj[cur]) {
            if (!visited[next]) {
                visited[next] = 1;
                q.push(next);
            }
        }
    }

    return 0;
}