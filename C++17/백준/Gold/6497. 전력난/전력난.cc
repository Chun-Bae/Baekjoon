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

struct Edge {
    int u, v, weight;
    Edge(int u, int v, int weight) : u(u), v(v), weight(weight) {}
    bool operator<(const Edge& other) const { return weight < other.weight; }
};

int find(int x, vec1& parent) {
    if (parent[x] != x) {
        parent[x] = find(parent[x], parent);
    }
    return parent[x];
}

void unite(int x, int y, vec1& parent, vec1& rank) {
    int rootX = find(x, parent);
    int rootY = find(y, parent);
    if (rootX != rootY) {
        if (rank[rootX] > rank[rootY]) {
            parent[rootY] = rootX;
        } else if (rank[rootX] < rank[rootY]) {
            parent[rootX] = rootY;
        } else {
            parent[rootY] = rootX;
            rank[rootX]++;
        }
    }
}

int main() {
    init();

    while (true) {
        int m, n;
        cin >> m >> n;
        if (m == 0 && n == 0) break;

        vector<Edge> edges;
        int totalCost = 0;

        for (int i = 0; i < n; i++) {
            int x, y, z;
            cin >> x >> y >> z;
            edges.emplace_back(x, y, z);
            totalCost += z;
        }

        sort(edges.begin(), edges.end());

        vec1 parent(m);
        vec1 rank(m, 0);
        for (int i = 0; i < m; i++) parent[i] = i;

        int mstCost = 0;
        for (const auto& edge : edges) {
            if (find(edge.u, parent) != find(edge.v, parent)) {
                unite(edge.u, edge.v, parent, rank);
                mstCost += edge.weight;
            }
        }

        cout << totalCost - mstCost << '\n';
    }

    return 0;
}
