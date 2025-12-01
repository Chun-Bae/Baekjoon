#include <algorithm>
#include <iostream>
#include <vector>
#define MOD 9901

using namespace std;

int main() {
    int N;
    cin >> N;
    // 0 : 사자 없음
    // 1 : 위칸에 사자
    // 2 : 아래칸에 사자
    vector<vector<int>> dp(N + 1, vector<int>(3, 0));

    dp[1][0] = dp[1][1] = dp[1][2] = 1;
    for (int i = 2; i <= N; i++) {
        dp[i][0] = ((dp[i - 1][0] + dp[i - 1][1]) % MOD + dp[i - 1][2]) % MOD;
        dp[i][1] = (dp[i - 1][0] + dp[i - 1][2]) % MOD;
        dp[i][2] = (dp[i - 1][0] + dp[i - 1][1]) % MOD;
    }

    int ans = (dp[N][0] + dp[N][1] % MOD + dp[N][2]) % MOD;
    cout << ans << endl;

    return 0;
}