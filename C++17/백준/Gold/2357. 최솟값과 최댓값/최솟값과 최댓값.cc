#include <algorithm>
#include <climits>
#include <iostream>
#include <vector>

using namespace std;

typedef long long ll;
typedef vector<int> vec1;
typedef vector<vec1> vec2;
typedef vector<vec2> vec3;
typedef pair<int, int> pii;
typedef vector<pii> vec1pii;
vec1 arr;
vec1pii segTree;

pii segtree_init(int node, int start, int end) {
    if (start == end) {
        segTree[node] = {arr[start], arr[start]};
        return segTree[node];
    }
    int mid = (start + end) / 2;
    pii left = segtree_init(node * 2, start, mid);
    pii right = segtree_init(node * 2 + 1, mid + 1, end);
    segTree[node] = {min(left.first, right.first), max(left.second, right.second)};
    return segTree[node];
}

pii segtree_query(int node, int start, int end, int left, int right){
    if (left > end || right < start){
        return {INT_MAX, INT_MIN};
    }
    if (left <= start && end <= right){
        return segTree[node];
    }
    int mid = (start + end) / 2;
    pii leftResult = segtree_query(node * 2, start, mid, left, right);
    pii rightResult = segtree_query(node * 2 + 1, mid + 1, end, left, right);
    return {min(leftResult.first, rightResult.first), max(leftResult.second, rightResult.second)};
}

void init() {
    cin.tie(NULL);
    cout.tie(NULL);
    ios::sync_with_stdio(false);
}

int main() {
    init();
    int N, M;
    cin >> N >> M;
    arr.resize(N);
    segTree.resize(4 * N);
    for (int i = 0; i < N; i++) {
        cin >> arr[i];
    }
    segtree_init(1, 0, N - 1);
    for (int i = 0; i < M; i++) {
        int a, b;
        cin >> a >> b;
        pii result = segtree_query(1, 0, N - 1, a - 1, b - 1);
        cout << result.first << ' ' << result.second << '\n';
    }

    return 0;
}