#include <algorithm>
#include <iostream>
#include <limits>
#include <vector>

#define INF std::numeric_limits<int>::max()

using namespace std;

int main() {
    int T;
    cin >> T;

    while (T--) {
        int K;
        cin >> K;
        vector<int> novel(K + 1);
        vector<vector<int>> dp(K + 1, vector<int>(K + 1));
        vector<int> presum(K + 1, 0);

        for (int i = 1; i <= K; i++) {
            cin >> novel[i];
            for (int j = K; j >= i; j--) {
                presum[j] += novel[i];
            }
        }
        // for (int i = 1; i <= K; i++)
        //     cout << presum[i] << " ";
        // cout << endl;

        for (int len = 2; len <= K; len++) {
            for (int i = 1; i + len - 1 <= K; i++) {
                int j = i + len - 1;
                dp[i][j] = INF;
                for (int k = i; k < j; k++) {
                    // printf("%d %d %d\n", i, k, j);
                    // printf("presum: %d\n", presum[j] - presum[i - 1]);

                    dp[i][j] = min(
                        dp[i][j],
                        dp[i][k] + dp[k + 1][j] + (presum[j] - presum[i - 1]));
                    // printf("dp[%d][%d]: %d\n", i, j, dp[i][j]);
                }
            }
        }
        cout << dp[1][K] << endl;
        // printf("=======\n");
    }

    return 0;
}
