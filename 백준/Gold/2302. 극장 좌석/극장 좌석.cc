#include <iostream>
#include <vector>

using namespace std;

int main() {
    int N, M;
    cin >> N >> M;
    vector<int> dp(N + 1, 0);

    dp[0] = 1;  // 좌석이 0개
    dp[1] = 1;  // 좌석이 1개
    for (int i = 2; i <= N; i++) {
        dp[i] = dp[i - 1] + dp[i - 2];
    }

    int prev = 0;
    int sum = 1;
    for (int i = 0; i < M; i++) {
        int vip;
        cin >> vip;
        sum *= dp[vip - prev - 1];
        prev = vip;
    }
    sum *= dp[N - prev];

    cout << sum;

    return 0;
}