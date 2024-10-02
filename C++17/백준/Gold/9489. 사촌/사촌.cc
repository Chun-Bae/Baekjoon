#include <algorithm>
#include <iostream>
#include <map>
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

int main() {
    init();
    while (true) {
        int n, k;
        cin >> n >> k;
        if (n == 0 && k == 0) break;

        vec1 nodes(n);
        for (int i = 0; i < n; ++i) cin >> nodes[i];

        vec1 parent(n, -1);
        vec1 has_child(n, 0);

        int current_parent_index = 0;
        int i = 1;
        while (i < n) {
            while (current_parent_index < i && has_child[current_parent_index]) current_parent_index++;
            if (current_parent_index >= i) break;

            has_child[current_parent_index] = 1;
            parent[i] = current_parent_index;
            i++;

            while (i < n && nodes[i] == nodes[i - 1] + 1) {
                parent[i] = current_parent_index;
                i++;
            }
        }

        int kIndex = -1;
        for (int idx = 0; idx < n; ++idx) {
            if (nodes[idx] == k) {
                kIndex = idx;
                break;
            }
        }

        if (kIndex == -1 || parent[kIndex] == -1 || parent[parent[kIndex]] == -1) {
            cout << 0 << endl;
            continue;
        }

        int kParent = parent[kIndex];
        int kGrandParent = parent[kParent];

        int cousinCount = 0;
        for (int idx = 0; idx < n; ++idx) {
            if (parent[idx] == -1 || parent[parent[idx]] == -1) continue;
            if (parent[idx] != kParent && parent[parent[idx]] == kGrandParent) {
                cousinCount++;
            }
        }

        cout << cousinCount << endl;
    }

    return 0;
}