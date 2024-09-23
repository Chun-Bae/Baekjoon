#include <algorithm>
#include <iostream>
#include <vector>
#define MAX_TASTE 1000000
using namespace std;

void init() {
    cin.tie(NULL);
    cout.tie(NULL);
    ios::sync_with_stdio(false);
}

typedef long long ll;
typedef vector<int> vec1;
typedef vector<vec1> vec2;
typedef vector<vec2> vec3;

class SegmentTree {
   public:
    vec1 tree;
    int size;

    SegmentTree(int n) {
        size = n;
        tree.resize(4 * n, 0);
    }

    void addCandy(int node, int start, int end, int idx, int diff) {
        if (idx < start || idx > end) return;

        tree[node] += diff;
        if (start != end) {
            int mid = (start + end) / 2;
            addCandy(2 * node, start, mid, idx, diff);
            addCandy(2 * node + 1, mid + 1, end, idx, diff);
        }
    }

    int findCandy(int node, int start, int end, int k) {
        if (start == end) return start;

        int mid = (start + end) / 2;

        if (tree[2 * node] >= k) {
            // left
            return findCandy(2 * node, start, mid, k);
        } else {
            // right
            // k - tree[2 * node] : left subtree에서 빼준 값
            return findCandy(2 * node + 1, mid + 1, end, k - tree[2 * node]);
        }
    }
};

int main() {
    init();

    SegmentTree segTree(MAX_TASTE);

    int n;
    cin >> n;

    while (n--) {
        int A;
        cin >> A;

        if (A == 1) {
            int B;
            cin >> B;
            int taste = segTree.findCandy(1, 1, MAX_TASTE, B);
            cout << taste << "\n";
            segTree.addCandy(1, 1, MAX_TASTE, taste, -1);
        } else if (A == 2) {
            int B, C;
            cin >> B >> C;
            segTree.addCandy(1, 1, MAX_TASTE, B, C);
        }
    }

    return 0;
}
