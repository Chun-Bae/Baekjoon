#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>

using namespace std;

const int MAX = 1000001;

vector<int> tree[MAX];
int ea[MAX][2];
bool visited[MAX];

void init(){
    cin.tie(NULL);
    cout.tie(NULL);
    ios::sync_with_stdio(false);
}

void dfs(int u) {
    visited[u] = true;
    ea[u][0] = 0;
    ea[u][1] = 1;

    for (int v : tree[u]) {
        if (!visited[v]) {
            dfs(v);
            // u는 확인하는 노드, v는 u의 자식 노드
            // u가 얼리어답터가 아닐 때 v는 얼리어답터여야 한다.
            // 즉 자신이 얼리어답터일 필요가 없음, 대신 주변 모두가 얼리어답터여야 함
            ea[u][0] += ea[v][1];
            // u가 얼리어답터일 때 v는 얼리어답터일 수도 있고 아닐 수도 있다.
            ea[u][1] += min(ea[v][0], ea[v][1]);
        }
    }
}

int main() {
    init();

    int N;
    cin >> N;

    for (int i = 0; i < N - 1; i++) {
        int u, v;
        cin >> u >> v;
        tree[u].push_back(v);
        tree[v].push_back(u);
    }

    memset(visited, false, sizeof(visited));

    dfs(1);

    cout << min(ea[1][0], ea[1][1]) << endl;

    return 0;
}