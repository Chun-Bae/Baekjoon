#include <iostream>

using namespace std;

int dp[100001][2];

void init() {
    cin.tie(NULL);
    cout.tie(NULL);
    ios::sync_with_stdio(false);
}

int main() {
    init();
    int T;
    cin >> T;
    while (T--) {
        int N;
        cin >> N;
        for (int i = 0; i < 2; ++i) {
            for (int j = 1; j <= N; ++j) {
                cin >> dp[j][i];
            }
        }
        dp[2][0] += dp[1][1];
        dp[2][1] += dp[1][0];
        for (int i = 3; i <= N; ++i) {
            dp[i][0] += max(dp[i - 1][1], dp[i - 2][1]);
            dp[i][1] += max(dp[i - 1][0], dp[i - 2][0]);
        }
        // 50 40 200 140 250
        // 30 100 120 210 260
        cout << max(dp[N][0], dp[N][1]) << '\n';
    }

    return 0;
}