#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

int main() {
    int N;
    cin >> N;
    vector<int> stairs(N + 1);
    vector<int> dp(N + 1, 0);
    for (int i = 1; i <= N; i++)
        cin >> stairs[i];

    dp[1] = stairs[1];
    dp[2] = stairs[1] + stairs[2];
    dp[3] = max(stairs[1] + stairs[3], stairs[2] + stairs[3]);

    for (int i = 4; i <= N; i++) {
        int a = stairs[i] + dp[i - 2];
        int b = stairs[i] + stairs[i - 1] + dp[i - 3];
        dp[i] = max(a, b);
    }
    cout << dp[N];

    return 0;
}