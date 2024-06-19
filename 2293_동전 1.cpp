#include <iostream>
#include <vector>

using namespace std;

typedef long long ll;

ll dp[10001];

void init() {
    cin.tie(NULL);
    cout.tie(NULL);
    ios::sync_with_stdio(false);
}

int main() {
    init();
    int n, k;
    cin >> n >> k;

    vector<int> coins(n + 1);

    for (int i = 1; i <= n; i++) cin >> coins[i];
    dp[0] = 1;
    for (int i = 1; i <= n; i++) {
        for (int j = coins[i]; j <= k; j++) {
            dp[j] = dp[j] + dp[j - coins[i]];
        }
    }
    cout << dp[k] << endl;

    return 0;
}