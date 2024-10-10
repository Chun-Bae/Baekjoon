#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

typedef long long ll;
typedef vector<int> vec1;
typedef vector<vec1> vec2;
typedef vector<vec2> vec3;

void init() {
    cin.tie(NULL);
    cout.tie(NULL);
    ios::sync_with_stdio(false);
}
vec1 parent(201);

int find(int u) {
    if (parent[u] != u) parent[u] = find(parent[u]);
    return parent[u];
}

void union_sets(int u, int v) {
    u = find(u);
    v = find(v);
    if (u != v) parent[u] = v;
}

int main() {
    init();
    int N, M;
    cin >> N >> M;

    for (int i = 1; i <= N; ++i) parent[i] = i;

    for (int i = 1; i <= N; ++i) {
        for (int j = 1; j <= N; ++j) {
            int connected;
            cin >> connected;
            if (connected == 1) union_sets(i, j);
        }
    }

    vec1 plan(M);
    for (int i = 0; i < M; ++i) cin >> plan[i];

    bool possible = true;
    int root = find(plan[0]);
    for (int i = 1; i < M; ++i) {
        if (find(plan[i]) != root) {
            possible = false;
            break;
        }
    }

    cout << (possible ? "YES" : "NO") << endl;

    return 0;
}