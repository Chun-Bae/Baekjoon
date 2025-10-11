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
        if (n == pnode) continue;  // 역방향 차단
        if (!visited[n])
            dfs(n, node);
    }
}

int lift(int v, int k) {
    // 노드 v를 k=13만큼 올릴 때,
    // 13=1101(2)
    // 아래와 &연산
    // i=0 0001 OK 1칸 위로
    // i=1 0010 X
    // i=2 0100 OK 4칸 위로
    // i=3 1000 OK 8칸 위로
    for (int i = 0; i < MAX_LOG; i++) {
        if (k & (1 << i)) {
            v = parent[v][i];
            // 루트보다 더 위에 있을 때
            if (v == 0) break;
        }
    }
    return v;
}

int lca(int a, int b) {
    if (depth[a] < depth[b]) swap(a, b);
    // 깊이 맞추기
    a = lift(a, depth[a] - depth[b]);
    if (a == b) return a;

    // 작은 트리에서 큰 수는 조상이 0으로 되니까 같은 취급으로 금방 분기를 넘어감
    // 같은 depth 8에서 시작하면 2^16 ,.. ,2^15는 0으로 공통취급이므로
    // 4: 8->4, 2: 4->2, 1: 2->1 순으로 내려와서 만나짐. (공통조상이 루트라고 가정하면)
    for (int i = MAX_LOG - 1; i >= 0; i--) {
        if (parent[a][i] != parent[b][i]) {
            a = parent[a][i];
            b = parent[b][i];
        }
    }
    // 부모가 서로 같은 시점에서 멈추기 떄문에 바로 위가 공통 조상임
    // 4,2,1 지수 특성상 바로 이전에서 멈춤
    // 만약 8칸 올리고 4칸 올린 게 정답이었다면, 2칸도 넘어가고 1칸도 넘어갔다는 말인데,
    // 여기서 1이 넘어갔다는 건 바로 위가 부모 노드라는 거임
    // 위 예시에서 8칸 올리고 4칸 올렸는데, 1이상 남아있다면, 2칸,1칸 올리는 작업도 진행이
    // 되었을 거임. 그래서 결론적으로는 공통조상은 1칸만 남는다.
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
        cout << lca(a, b) << '\n';
    }
    return 0;
}