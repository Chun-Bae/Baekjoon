#include <iostream>

using namespace std;

typedef long long ll;

ll dp[1026][1026];

void init() {
    cin.tie(NULL);
    cout.tie(NULL);
    ios::sync_with_stdio(false);
}

int main() {
    init();
    int N, M;
    cin >> N >> M;
    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= N; j++) {
            cin >> dp[i][j];
            dp[i][j] = dp[i][j] + dp[i][j - 1] + dp[i - 1][j] - dp[i - 1][j - 1];
        }
    }

    while (M--) {
        int x1, y1, x2, y2;
        cin >> x1 >> y1 >> x2 >> y2;
        cout << dp[x2][y2] - dp[x2][y1 - 1] - dp[x1 - 1][y2] + dp[x1 - 1][y1 - 1] << '\n';
    }
    return 0;
}