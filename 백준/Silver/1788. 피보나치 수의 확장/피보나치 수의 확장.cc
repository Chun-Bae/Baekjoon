#include <algorithm>
#include <iostream>
#include <vector>

#define MOD 1'000'000'000

using namespace std;

int main() {
    int n, absn;
    cin >> n;
    if (n == 0) {
        cout << 0 << '\n';
        cout << 0 << '\n';
        return 0;
    }
    absn = abs(n);
    vector<int> dp(absn+1, 0);

    if (n > 0) {
        dp[0] = 0;
        dp[1] = 1;
        for (int i = 2; i <= n; i++) {
            dp[i] = (dp[i - 1] + dp[i - 2]) % MOD;
        }
    } else {
        dp[0] = 0;
        dp[1] = 1;
        for (int i = 2; i <= absn; i++) {
            dp[i] = (dp[i - 2] - dp[i - 1]) % MOD;
        }
    }
    if (dp[absn] == 0) cout << 0;
    if (dp[absn] > 0) cout << 1;
    if (dp[absn] < 0) cout << -1;
    cout << endl;
    cout << abs(dp[absn]) << endl;

    return 0;
}