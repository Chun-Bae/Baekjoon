#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>

using namespace std;

struct Edge {
    int x, y, cost;
    bool operator<(const Edge &other) const {
        return cost < other.cost;
    }
};

vector<int> parent;

int find(int x) {
    if (x != parent[x])
        parent[x] = find(parent[x]);
    return parent[x];
}

void unite(int x, int y) {
    x = find(x);
    y = find(y);
    if (x != y) {
        parent[y] = x;
    }
}

void init(){
    cin.tie(NULL);
    cout.tie(NULL);
    ios::sync_with_stdio(false);
}


int main() {
    init();
    int N, M;
    cin >> N >> M;

    vector<Edge> edges(M);
    for (int i = 0; i < M; ++i) {
        cin >> edges[i].x >> edges[i].y >> edges[i].cost;
    }

    sort(edges.begin(), edges.end());

    parent.resize(N + 1);
    iota(parent.begin(), parent.end(), 0);

    int mst_cost = 0;
    int max_edge_cost = 0;
    int edges_used = 0;

    for (const auto &edge : edges) {
        if (find(edge.x) != find(edge.y)) {
            unite(edge.x, edge.y);
            mst_cost += edge.cost;
            max_edge_cost = edge.cost;
            edges_used++;
            if (edges_used == N - 1) break;
        }
    }

    mst_cost -= max_edge_cost;

    cout << mst_cost << '\n';

    return 0;
}
