#include <algorithm>
#include <iostream>
#include <vector>
#define MOD 1000000000
using namespace std;

typedef long long ll;
typedef vector<ll> vec1;
typedef vector<vec1> vec2;
typedef vector<vec2> vec3;

void init() {
    cin.tie(NULL);
    cout.tie(NULL);
    ios::sync_with_stdio(false);
}

int main() {
    init();
    int N;
    cin >> N;

    vec3 dp(N + 1, vec2(10, vec1(1 << 10, 0)));

    for (int i = 1; i <= 9; i++) {
        dp[1][i][1 << i] = 1;
    }

    for (int n = 2; n <= N; n++) {
        for (int digit = 0; digit <= 9; digit++) {
            for (int bitmask = 0; bitmask < (1 << 10); bitmask++) {
                if (digit > 0) {
                    dp[n][digit][bitmask | (1 << digit)] = (dp[n][digit][bitmask | (1 << digit)] + dp[n - 1][digit - 1][bitmask]) % MOD;
                }
                if (digit < 9) {
                    dp[n][digit][bitmask | (1 << digit)] = (dp[n][digit][bitmask | (1 << digit)] + dp[n - 1][digit + 1][bitmask]) % MOD;
                }
            }
        }
    }

    ll result = 0;
    for (int digit = 0; digit <= 9; digit++) {
        result = (result + dp[N][digit][(1 << 10) - 1]) % MOD;
    }

    cout << result << endl;

    return 0;
}
