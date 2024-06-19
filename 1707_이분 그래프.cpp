#include <iostream>
#include <vector>
using namespace std;

typedef long long ll;

#define RED 1
#define BLACK 2

vector<vector<int>> graph;
vector<int> visit;
bool bipartite;

void DFS(int node, int color) {
    visit[node] = color;
    // graph[node]: node에 대한 인접 정점들의 리스트를 모두 순회
    for (int next : graph[node]) {
        if (visit[next] == 0) {
            DFS(next, 3 - color);  // 3-color로 반대 색을 계산
        // 인접한 정점들이랑 지금 정점이랑 같은 색이면 안됌.
        } else if (visit[next] == color) {
            bipartite = false;
            return;
        }
    }
}

void init() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
}

int main() {
    init();

    int K;
    cin >> K;
    while (K--) {
        int V, E;
        cin >> V >> E;

        graph.assign(V + 1, vector<int>());
        visit.assign(V + 1, 0);
        bipartite = true;

        for (int i = 0; i < E; i++) {
            int u, v;
            cin >> u >> v;
            graph[u].push_back(v);
            graph[v].push_back(u);
        }

        for (int i = 1; i <= V; i++) {
            if (visit[i] == 0) {
                DFS(i, RED);
                if (!bipartite) break;
            }
        }

        bipartite ? cout << "YES\n" : cout << "NO\n";
    }
    return 0;
}
