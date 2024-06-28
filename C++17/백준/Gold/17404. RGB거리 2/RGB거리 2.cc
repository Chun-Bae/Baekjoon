#include <algorithm>
#include <iostream>
#define MAX 1e9
using namespace std;

int dp[1001][3];
int R[1001], G[1001], B[1001];
int minCost = MAX;

void init() {
    cin.tie(NULL);
    cout.tie(NULL);
    ios::sync_with_stdio(false);
}

int main() {
    init();
    int N;
    cin >> N;
    for (int i = 1; i <= N; i++) cin >> R[i] >> G[i] >> B[i];
    for (int first_color = 0; first_color < 3; ++first_color) {
        for (int i = 0; i <= N; ++i) dp[i][0] = dp[i][1] = dp[i][2] = MAX;

        switch (first_color) {
            case 0:
                dp[1][0] = R[1];
                break;
            case 1:
                dp[1][1] = G[1];
                break;
            case 2:
                dp[1][2] = B[1];
                break;
        }

        for (int i = 2; i <= N; ++i) {
            dp[i][0] = min(dp[i - 1][1], dp[i - 1][2]) + R[i];
            dp[i][1] = min(dp[i - 1][0], dp[i - 1][2]) + G[i];
            dp[i][2] = min(dp[i - 1][0], dp[i - 1][1]) + B[i];
        }

        // N번 집의 색상이 1번 집의 색상과 다른 경우만 고려
        for (int last_color = 0; last_color < 3; ++last_color) {
            if (first_color != last_color) {
                minCost = min(minCost, dp[N][last_color]);
            }
        }
    }

    cout << minCost << '\n';

    return 0;
}
