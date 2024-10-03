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
const int MOD = 1000000;
int main() {
    init();
    string s;
    cin >> s;

    if (s[0] == '0') {
        cout << 0 << endl;
        return 0;
    }

    int n = s.length();
    vec1 dp(5001, 0);
    dp[0] = 1;

    for (int i = 1; i <= n; i++) {
        int oneDigit = s[i - 1] - '0';
        if (oneDigit >= 1 && oneDigit <= 9) {
            dp[i] = (dp[i] + dp[i - 1]) % MOD;
        }

        if (i > 1) {
            int twoDigits = (s[i - 2] - '0') * 10 + (s[i - 1] - '0');
            if (twoDigits >= 10 && twoDigits <= 26) {
                dp[i] = (dp[i] + dp[i - 2]) % MOD;
            }
        }
    }

    cout << dp[n] << endl;
    return 0;
}