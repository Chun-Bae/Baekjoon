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
vec1 tree[50];

int delete_node;
int leaf_count = 0;

void dfs(int node) {
    if (node == delete_node) return;

    if (tree[node].empty()) {
        leaf_count++;
        return;
    }

    bool has_child = false;
    for (int child : tree[node]) {
        if (child != delete_node) {
            has_child = true;
            dfs(child);
        }
    }

    if (!has_child) leaf_count++;
}
int main() {
    init();
    int N;
    cin >> N;

    vec1 parent(N);
    int root = -1;

    for (int i = 0; i < N; i++) {
        cin >> parent[i];
        if (parent[i] == -1)
            root = i;
        else
            tree[parent[i]].push_back(i);
    }

    cin >> delete_node;

    if (root != delete_node) dfs(root);

    cout << leaf_count << endl;
    return 0;
}