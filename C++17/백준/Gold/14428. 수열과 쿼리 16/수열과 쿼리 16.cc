#include <algorithm>
#include <iostream>
#include <vector>
#define INF 1e9+1
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
class SegmentTree {
   public:
    int n;
    vector<pair<int, int>> tree;

    SegmentTree(const vector<int>& arr) {
        n = arr.size();
        tree.resize(4 * n);
        build(arr, 1, 0, n - 1);
    }

    void build(const vector<int>& arr, int node, int start, int end) {
        if (start == end) {
            tree[node] = {arr[start], start};
        } else {
            int mid = (start + end) / 2;
            build(arr, 2 * node, start, mid);
            build(arr, 2 * node + 1, mid + 1, end);
            tree[node] = min(tree[2 * node], tree[2 * node + 1]);
        }
    }
    void update(int idx, int value) { update(idx - 1, value, 1, 0, n - 1); }
    void update(int idx, int value, int node, int start, int end) {
        if (start == end) {
            tree[node] = {value, start};
        } else {
            int mid = (start + end) / 2;
            if (idx <= mid) {
                update(idx, value, 2 * node, start, mid);
            } else {
                update(idx, value, 2 * node + 1, mid + 1, end);
            }
            tree[node] = min(tree[2 * node], tree[2 * node + 1]);
        }
    }

    int query(int L, int R) { return query(L - 1, R - 1, 1, 0, n - 1).second + 1; }
    pair<int, int> query(int L, int R, int node, int start, int end) {
        if (R < start || L > end) {
            return {INF, -1};
        }
        if (L <= start && end <= R) {
            return tree[node];
        }
        int mid = (start + end) / 2;
        return min(query(L, R, 2 * node, start, mid), query(L, R, 2 * node + 1, mid + 1, end));
    }
};

int main() {
    init();
    int N;
    cin >> N;

    vector<int> arr(N);
    for (int i = 0; i < N; ++i) {
        cin >> arr[i];
    }

    SegmentTree segTree(arr);

    int M;
    cin >> M;

    for (int i = 0; i < M; ++i) {
        int type;
        cin >> type;

        if (type == 1) {
            int idx, value;
            cin >> idx >> value;
            segTree.update(idx, value);
        } else if (type == 2) {
            int L, R;
            cin >> L >> R;
            cout << segTree.query(L, R) << "\n";
        }
    }
    return 0;
}