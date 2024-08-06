#include <iostream>
#include <vector>

using namespace std;

void init() {
    cin.tie(NULL);
    cout.tie(NULL);
    ios::sync_with_stdio(false);
}

int find(vector<int>& parent, int x) {
    if (parent[x] == x) return x;
    return parent[x] = find(parent, parent[x]);
}

void unite(vector<int>& parent, int x, int y) {
    int rootX = find(parent, x);
    int rootY = find(parent, y);
    if (rootX != rootY) parent[rootY] = rootX;
}

int main() {
    init();
    int G, P;
    cin >> G >> P;

    vector<int> parent(G + 1);
    for (int i = 1; i <= G; ++i) parent[i] = i;

    int docked_planes = 0;

    for (int i = 0; i < P; ++i) {
        int gi;
        cin >> gi;

        int root = find(parent, gi);
        if (root == 0) {
            break;
        }

        docked_planes++;
        unite(parent, root - 1, root);
    }

    cout << docked_planes << '\n';

    return 0;
}
