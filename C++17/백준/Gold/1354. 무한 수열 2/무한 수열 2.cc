#include <algorithm>
#include <iostream>
#include <unordered_map>
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

ll N, P, Q, X, Y;
unordered_map<ll, ll> memo;

ll infinite_sequence(ll i) {
    if (i <= 0) return 1;
    if (memo.find(i) != memo.end()) return memo[i];
    return memo[i] = infinite_sequence(i / P - X) + infinite_sequence(i / Q - Y);
}
int main() {
    init();
    cin >> N >> P >> Q >> X >> Y;
    cout << infinite_sequence(N) << endl;

    return 0;
}