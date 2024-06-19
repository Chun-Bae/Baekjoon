#include <iostream>
#define MOD 1000000007
typedef long long ll;
using namespace std;

ll dp[5];

void init() {
    cin.tie(NULL);
    cout.tie(NULL);
    ios::sync_with_stdio(false);
}

int main() {
    init();
    int n;
    cin >> n;
    for (auto& d : dp) d = 1;
    // dp[2] = 1*4 + 1*3 + 1*2 + 1*2 + 1*3; // 0-(1 2 3 4), 1-(0 3 4), 2-(0 4), 3-(0 1), 4-(0 1 2)
    //  마지막부분: 0(1,2,3,4), 1(0,3,4), 2(0,4) 3(0,1), 4(0,1,2)
    while ((n--) - 1) {
        ll tmp[5];
        tmp[0] = (dp[1] + dp[2] + dp[3] + dp[4]) % MOD;
        tmp[1] = (dp[0] + dp[3] + dp[4]) % MOD;
        tmp[2] = (dp[0] + dp[4]) % MOD;
        tmp[3] = (dp[0] + dp[1]) % MOD;
        tmp[4] = (dp[0] + dp[1] + dp[2]) % MOD;
        for (int i = 0; i < 5; i++) dp[i] = tmp[i];
    }
    int result = 0;
    for (auto r : dp) result = (result + r) % MOD;
    cout << result % MOD;

    return 0;
}