#include <iostream>
#include <vector>

using namespace std;

vector<int> parent;

void init() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
}

int find(int x) {
    if (parent[x] != x) {
        parent[x] = find(parent[x]);
    }
    return parent[x];
}

bool unionSets(int x, int y) {
    int rootX = find(x);
    int rootY = find(y);

    if (rootX != rootY) {
        parent[rootY] = rootX;
        return false;
    }
    return true; 
}

int main() {
    int n, m;
    cin >> n >> m;

    parent.resize(n);

    for (int i = 0; i < n; ++i) {
        parent[i] = i;
    }

    int cycleTurn = 0;
    for (int i = 1; i <= m; ++i) {
        int u, v;
        cin >> u >> v;

        if (unionSets(u, v)) {
            cycleTurn = i;
            break;
        }
    }

    cout << cycleTurn << '\n';

    return 0;
}
