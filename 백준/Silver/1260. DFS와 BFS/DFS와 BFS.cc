#include <algorithm>
#include <iostream>
#include <vector>
#include <queue>

using namespace std;

void bfs(vector<vector<int>> adj, int* visited, int V) {
    queue<int> q;
    q.push(V);
    visited[V] = 1;
    while (!q.empty()) {
        int target = q.front();
        printf("%d ", target);
        q.pop();

        for (auto s : adj[target]) {
            if (visited[s] == 0) {
                q.push(s);
                visited[s] = 1;
            }
        }
    }
}

void dfs(vector<vector<int>> adj, int* visited, int target) {
    if(visited[target]==1) return;
    visited[target]=1;
    printf("%d ",target);
    for(auto s : adj[target]){
        dfs(adj,visited,s);
    }
}

int main() {
    int N, M, V;
    int visited_b[1001] = {};
    int visited_d[1001] = {};
    vector<vector<int>> adj(1001);

    cin >> N >> M >> V;
    for (int i = 0; i < M; i++) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    for (int i = 1; i <= N; i++) {
        sort(adj[i].begin(), adj[i].end());
    }

    dfs(adj, visited_d, V);
    cout<<endl;
    bfs(adj, visited_b, V);

    return 0;
}