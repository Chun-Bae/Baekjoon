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
    int h1, h2, weight;
};

int findParent(int node, vector<int>& parent) {
    if (parent[node] == node) return node;
    return parent[node] = findParent(parent[node], parent);
}

bool unionNodes(int a, int b, vector<int>& parent, vector<int>& rank) {
    int rootA = findParent(a, parent);
    int rootB = findParent(b, parent);

    if (rootA != rootB) {
        if (rank[rootA] > rank[rootB]) {
            parent[rootB] = rootA;
        } else if (rank[rootA] < rank[rootB]) {
            parent[rootA] = rootB;
        } else {
            parent[rootB] = rootA;
            rank[rootA]++;
        }
        return true;
    }
    return false;
}

bool canCarryGold(int mid, int s, int e, const vector<Edge>& edges, int n) {
    vector<int> parent(n + 1);
    vector<int> rank(n + 1, 0);

    for (int i = 1; i <= n; ++i) parent[i] = i;

    for (const auto& edge : edges) {
        if (edge.weight >= mid) {
            unionNodes(edge.h1, edge.h2, parent, rank);
        }
    }

    return findParent(s, parent) == findParent(e, parent);
}

int main() {
    init();
    int n, m;
    cin >> n >> m;

    int s, e;
    cin >> s >> e;

    vector<Edge> edges(m);
    for (int i = 0; i < m; ++i) {
        cin >> edges[i].h1 >> edges[i].h2 >> edges[i].weight;
    }

    sort(edges.begin(), edges.end(), [](const Edge& a, const Edge& b) { return a.weight > b.weight; });

    int left = 1, right = 1'000'000, result = 0;

    while (left <= right) {
        int mid = (left + right) / 2;
        if (canCarryGold(mid, s, e, edges, n)) {
            result = mid;
            left = mid + 1;
        } else {
            right = mid - 1;
        }
    }

    cout << result << "\n";
    return 0;
}
