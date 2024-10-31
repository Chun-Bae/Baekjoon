#include <algorithm>
#include <iostream>
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
const int MOD = 1000000000;

int main() {
    init();
    int N, K;
    cin >> N >> K;

    vec2 dp(K + 1, vec1(N + 1, 0));

    for (int i = 0; i <= N; i++) {
        dp[1][i] = 1;
    }

    for (int k = 2; k <= K; k++) {
        for (int n = 0; n <= N; n++) {
            dp[k][n] = dp[k - 1][n];
            if (n > 0) {
                dp[k][n] = (dp[k][n] + dp[k][n - 1]) % MOD;
            }
        }
    }

    cout << dp[K][N] << endl;

    return 0;
}