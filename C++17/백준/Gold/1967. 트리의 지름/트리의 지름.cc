#include <cstring>
#include <iostream>
#include <vector>

using namespace std;

int n;
vector<pair<int, int>> tree[10001];
bool visited[10001];
int maxDistance;
int maxNode;

void init() {
    cin.tie(NULL);
    cout.tie(NULL);
    ios::sync_with_stdio(false);
}

void dfs(int node, int distance) {
    visited[node] = true;

    if (distance > maxDistance) {
        maxDistance = distance;
        maxNode = node;
    }

    for (auto &edge : tree[node]) {
        int nextNode = edge.first;
        int weight = edge.second;
        if (!visited[nextNode]) {
            dfs(nextNode, distance + weight);
        }
    }
}

int main() {
    init();
    cin >> n;

    for (int i = 0; i < n - 1; ++i) {
        int u, v, w;
        cin >> u >> v >> w;
        tree[u].emplace_back(v, w);
        tree[v].emplace_back(u, w);
    }

    memset(visited, false, sizeof(visited));
    maxDistance = 0;
    dfs(1, 0);

    memset(visited, false, sizeof(visited));
    maxDistance = 0;
    dfs(maxNode, 0);

    cout << maxDistance << '\n';

    return 0;
}
