#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;
typedef long long ll;
ll N, M, K;
vector<ll> arr;
vector<ll> tree;

void init() {
    cin.tie(NULL);
    cout.tie(NULL);
    ios::sync_with_stdio(false);
}

ll segtree(ll node, ll start, ll end) {
    if (start == end) {
        return tree[node] = arr[start];
    } else {
        ll mid = (start + end) / 2;
        return tree[node] = segtree(node * 2, start, mid) + segtree(node * 2 + 1, mid + 1, end);
    }
}

void update(ll node, ll start, ll end, ll idx, ll val) {
    if (idx < start || idx > end) return;
    if (start == end) {
        arr[idx] = val;
        tree[node] = val;
        return;
    }
    ll mid = (start + end) / 2;
    update(node * 2, start, mid, idx, val);
    update(node * 2 + 1, mid + 1, end, idx, val);
    tree[node] = (tree[node * 2] + tree[node * 2 + 1]);
}

ll query(ll node, ll start, ll end, ll l, ll r) {
    if (r < start || end < l) return 0;
    if (l <= start && end <= r) return tree[node];
    ll mid = (start + end) / 2;
    ll p1 = query(node * 2, start, mid, l, r);
    ll p2 = query(node * 2 + 1, mid + 1, end, l, r);
    return (p1 + p2);
}

int main() {
    init();
    cin >> N >> M >> K;
    arr.resize(N);
    tree.resize(N * 4);
    for (ll i = 0; i < N; i++) {
        cin >> arr[i];
    }

    segtree(1, 0, N - 1);

    for (ll i = 0; i < M + K; i++) {
        ll a, b, c;
        cin >> a >> b >> c;
        if (a == 1) {
            update(1, 0, N - 1, b - 1, c);
        } else if (a == 2) {
            ll result = query(1, 0, N - 1, b - 1, c - 1);
            cout << result << '\n';
        }
    }

    return 0;
}