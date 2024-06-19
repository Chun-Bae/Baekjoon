#include <iostream>

using namespace std;
typedef long long ll;

ll dp[100001];

void init() {
    cin.tie(NULL);
    cout.tie(NULL);
    ios::sync_with_stdio(false);
}

int main() {
    init();
    int N, M;
    cin >> N >> M;
    for (int i = 1; i <= N; i++) {
        cin >> dp[i];
        dp[i] += dp[i - 1];
    }

    while(M--) {
        int a, b;
        cin >> a >> b;
        cout<< dp[b]-dp[a-1]<<'\n';
    }

    return 0;
}