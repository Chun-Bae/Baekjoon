#include <algorithm>
#include <iostream>
#include <unordered_set>
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

const int MAX_N = 10001;

vec1 tree[MAX_N];
int parent[MAX_N];
int depth[MAX_N];

void initialize(int n) {
    for (int i = 1; i <= n; ++i) {
        tree[i].clear();
        parent[i] = 0;
        depth[i] = 0;
    }
}

void dfs(int node, int d) {
    depth[node] = d;
    for (int child : tree[node]) {
        if (depth[child] == 0) {
            parent[child] = node;
            dfs(child, d + 1);
        }
    }
}
int lca(int a, int b) {
    while (depth[a] > depth[b]) a = parent[a];
    while (depth[b] > depth[a]) b = parent[b];
    while (a != b) {
        a = parent[a];
        b = parent[b];
    }
    return a;
}

int main() {
    init();

    int T;
    cin >> T;
    while (T--) {
        int N;
        cin >> N;
        initialize(N);

        unordered_set<int> all_nodes, child_nodes;

        for (int i = 1; i < N; ++i) {
            int A, B;
            cin >> A >> B;
            tree[A].push_back(B);
            tree[B].push_back(A);
            all_nodes.insert(A);
            all_nodes.insert(B);
            child_nodes.insert(B);
        }

        int root = 0;
        for (int node : all_nodes) {
            if (child_nodes.find(node) == child_nodes.end()) {
                root = node;
                break;
            }
        }

        dfs(root, 1);

        int a, b;
        cin >> a >> b;
        cout << lca(a, b) << '\n';
    }
    return 0;
}
