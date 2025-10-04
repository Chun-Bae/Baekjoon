#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

vector<int> parent;

int find(int x) {
    if (parent[x] == x) return x;
    return parent[x] = find(parent[x]);
}

void union_set(int a, int b) {
    a = find(a);
    b = find(b);
    if (a != b) parent[b] = a;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, m;
    cin >> n >> m;

    parent.resize(n + 1);
    for (int i = 0; i <= n; i++)
        parent[i] = i;

    for (int i = 0; i < m; i++) {
        int mode, a, b;
        cin >> mode >> a >> b;

        switch (mode) {
            case 0:
                union_set(a, b);
                break;
            case 1:
                if (find(a) != find(b))
                    cout << "NO\n";
                else
                    cout << "YES\n";
                break;
        }
    }

    return 0;
}