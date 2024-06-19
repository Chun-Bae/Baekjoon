#include <algorithm>
#include <iostream>

using namespace std;

typedef long long ll;

int dp[1001][1001];

void init() {
    cin.tie(NULL);
    cout.tie(NULL);
    ios::sync_with_stdio(false);
}

int main() {
    init();
    string a, b;
    cin >> a >> b;
    for (int i = 0; i <= b.size(); i++) {
        for (int j = 0; j <= a.size(); j++) {
            if (i && j) {
                if (a[j - 1] == b[i - 1]) {
                    dp[i][j] = dp[i - 1][j - 1] + 1;
                } else
                    dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
            }
        }
    }
    int maax = dp[b.size()][a.size()];
    string ans = "";
    for (int i = b.size(); i >= 1; i--) {
        if (maax == 0) break;
        for (int j = a.size(); j >= 1; ) {
            if (maax == 0) break;
            if (a[j-1] == b[i-1] && dp[i][j] == maax) {
                ans += b[i - 1];
                i--;
                j--;
                maax--;
            } else if (dp[i][j] == dp[i - 1][j]) {
                i--;
            } else if (dp[i][j] == dp[i][j - 1]) {
                j--;
            }
        }
    }
    reverse(ans.begin(), ans.end());
    cout << dp[b.size()][a.size()] << endl;
    cout << ans << endl;

    return 0;
}