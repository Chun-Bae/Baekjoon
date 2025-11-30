#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

int main() {
    int N;
    cin >> N;
    vector<int> T(N, 0), P(N, 0), dp(N + 1, 0);

    for (int i = 0; i < N; i++) {
        cin >> T[i] >> P[i];
    }
    for (int i = N - 1; i >= 0; i--) {
        if (i + T[i] <= N)
            //  현재할 상담과 그 상담이 끝날 날의 합 / 앞에 날
            dp[i] = max(P[i] + dp[i + T[i]], dp[i + 1]);
        else
            // T일만큼 더 하는 게 초과면 안하고 넘어감
            dp[i] = dp[i + 1];
    }
    cout << dp[0];

    return 0;
}