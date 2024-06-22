#include <iostream>

using namespace std;

typedef long long ll;

void init() {
    cin.tie(NULL);
    cout.tie(NULL);
    ios::sync_with_stdio(false);
}

int main() {
    init();
    ll N, M, a, K;
    cin >> N >> M >> a >> K;
    ll rank_min = (a - K + M - 1) / M + 1;
    ll rank_max = min(N, a - K + 1);
    cout << rank_max << " " << rank_min << "\n";
    return 0;
}