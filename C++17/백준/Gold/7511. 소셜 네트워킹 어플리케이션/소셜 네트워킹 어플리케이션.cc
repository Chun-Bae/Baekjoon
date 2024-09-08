#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

typedef long long ll;
typedef vector<int> vec1;
typedef vector<vec1> vec2;
typedef vector<vec2> vec3;

int find(vec1& parent, int u) {
    if (u == parent[u]) {
        return u;
    }
    return parent[u] = find(parent, parent[u]);
}
void unionSets(vec1& parent, vec1& rank, int u, int v) {
    u = find(parent, u);
    v = find(parent, v);

    if (u != v) {
        if (rank[u] > rank[v]) {
            parent[v] = u;
        } else if (rank[u] < rank[v]) {
            parent[u] = v;
        } else {
            parent[v] = u;
            rank[u]++;
        }
    }
}

bool sameSet(vec1& parent, int u, int v) { return find(parent, u) == find(parent, v); }

void init() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
}

int main() {
    init();
    int T;
    cin >> T;

    for (int testCase = 1; testCase <= T; ++testCase) {
        int n;
        cin >> n;

        int k;
        cin >> k;

        vec1 parent(n);
        vec1 rank(n, 1);

        for (int i = 0; i < n; ++i) {
            parent[i] = i;
        }

        for (int i = 0; i < k; ++i) {
            int a, b;
            cin >> a >> b;
            unionSets(parent, rank, a, b);
        }

        int m;
        cin >> m;

        cout << "Scenario " << testCase << ":\n";
        for (int i = 0; i < m; ++i) {
            int u, v;
            cin >> u >> v;
            if (sameSet(parent, u, v)) {
                cout << 1 << "\n";
            } else {
                cout << 0 << "\n";
            }
        }
        cout << endl;
    }

    return 0;
}
