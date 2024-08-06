#include <iostream>

using namespace std;

typedef long long ll;

ll dp[91][2];

void init() {
    cin.tie(NULL);
    cout.tie(NULL);
    ios::sync_with_stdio(false);
}

int main() {
    init();
    int N;
    cin >> N;

    dp[1][0] = 0;
    dp[1][1] = 1;
    // 이친수의 가장 오른쪽을 보고 판단
    for (int i = 2; i <= N; ++i) {
        dp[i][0] = dp[i - 1][0] + dp[i - 1][1];  // 마지막이 0인 경우
        dp[i][1] = dp[i - 1][0];                 // 마지막이 1인 경우
    }

    cout << dp[N][0] + dp[N][1] << endl;
    return 0;
}
