#include <iostream>
#include <vector>

using namespace std;

void init() {
    cin.tie(NULL);
    cout.tie(NULL);
    ios::sync_with_stdio(false);
}

int main() {
    init();
    vector<long long> dp(68);
    dp[0] = 1;
    dp[1] = 1;
    dp[2] = 2;
    dp[3] = 4;
    for (int i = 4; i <= 67; i++) {
        dp[i] = dp[i - 1] + dp[i - 2] + dp[i - 3] + dp[i - 4];
    }

    int t;
    int n;
    cin >> t;
    while (t--) {
        cin >> n;
        cout << dp[n] << '\n';
    }
    return 0;
}