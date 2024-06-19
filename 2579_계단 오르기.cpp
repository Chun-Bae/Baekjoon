#include <iostream>

using namespace std;

typedef long long ll;

int dp[301];
int scores[301];

void init() {
    cin.tie(NULL);
    cout.tie(NULL);
    ios::sync_with_stdio(false);
}

int main() {
    init();
    int T;
    cin >> T;
    for (int i = 1; i <= T; i++) cin >> scores[i];
    dp[1] = scores[1];
    dp[2] = max(scores[2] + scores[1], scores[2]);
    dp[3] = max(scores[3] + scores[2], scores[3] + scores[1]);

    for (int i = 4; i <= T; i++) {
        dp[i] = max(scores[i] + dp[i - 2], scores[i] + scores[i - 1] + dp[i - 3]);
    }
    cout << dp[T];
    return 0;
}