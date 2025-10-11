#include <iostream>
#include <vector>

using namespace std;

int find(int k, vector<int>& parent) {
    if (parent[k] == k) return k;
    parent[k] = find(parent[k], parent);
    return parent[k];
}

void union_set(int a, int b, vector<int>& parent) {
    a = find(a, parent);
    b = find(b, parent);
    if (a != b) parent[b] = a;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, m;
    cin >> n >> m;
    vector<int> parent(n + 1);
    for (int i = 0; i <= n; i++)
        parent[i] = i;

    for (int i = 0; i < m; i++) {
        int s, a, b;
        cin >> s >> a >> b;
        if (s == 0) {
            union_set(a, b, parent);
        } else {
            find(a, parent) != find(b, parent) ? cout << "NO" : cout << "YES";
            cout << "\n";
        }
    }
    return 0;
}