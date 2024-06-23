#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

typedef long long ll;

vector<vector<int>> graph;
vector<int> discovered;
vector<pair<int, int>> isCutEdge;

int counter;

void init() {
    cin.tie(NULL);
    cout.tie(NULL);
    ios::sync_with_stdio(false);
}

int dfs(int here, int parent) {
    discovered[here] = counter++;
    int ret = discovered[here];

    // 다음 정점들 중에서 부모 정점은 제외,
    // 이미 방문한 정점은 ret 값 갱신 후 continue
    // 위의 두 행위는 같은 사이클에 속하는 정점들을 최소값으로 갱신하는 행위임

    // 그게 아니면 dfs 호출
    for (int next : graph[here]) {
        // 역방향 간선은 무시
        if (next == parent) continue;
        // 이미 방문한 정점이라면 최소방문순서를 갱신
        if (discovered[next]) {
            ret = min(ret, discovered[next]);
            continue;
        }
        int subtree = dfs(next, here);
        // 서브트리의 방문순서가 현재 정점의 방문순서보다 크다면
        if (subtree > discovered[here]) isCutEdge.push_back({min(here, next), max(here, next)});

        ret = min(ret, subtree);
    }
    // 현재 정점에 최소방문순서를 반환
    return ret;
}

int main() {
    init();
    int V, E;
    cin >> V >> E;
    graph.resize(V + 1);
    discovered.resize(V + 1);
    for (int i = 1; i <= E; i++) {
        int A, B;
        cin >> A >> B;
        graph[A].push_back(B);
        graph[B].push_back(A);
    }
    for (int i = 1; i <= V; i++)
        if (!discovered[i]) dfs(i, 0);

    sort(isCutEdge.begin(), isCutEdge.end());
    cout << isCutEdge.size() << "\n";
    for (const auto& edge : isCutEdge) cout << edge.first << " " << edge.second << "\n";
    return 0;
}