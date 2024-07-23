#include <iostream>
#include <vector>

using namespace std;

void init() {
    cin.tie(NULL);
    cout.tie(NULL);
    ios::sync_with_stdio(false);
}

int main() {
    init();
    int N;
    cin >> N;
    vector<int> arr(N + 1);
    for (int i = 1; i <= N; i++) {
        cin >> arr[i];
    }

    int M;
    cin >> M;

    vector<vector<int>> dp(N + 1, vector<int>(N + 1, 0));

    // 길이 1인 경우는 항상 팰린드롬
    for (int i = 1; i <= N; i++) {
        dp[i][i] = 1;
    }

    // 길이 2인 경우
    for (int i = 1; i < N; i++) {
        if (arr[i] == arr[i + 1]) {
            dp[i][i + 1] = 1;
        }
    }

    // 길이 3 이상인 경우
    // [1, 3], [2, 4], [3, 5], ... [N - 2, N]
    // [1, 4], [2, 5], [3, 6], ... [N - 3, N]
    // [1, 5], [2, 6], [3, 7], ... [N - 4, N]
    for (int length = 3; length <= N; length++) {
        for (int i = 1; i <= N - length + 1; i++) {
            int j = i + length - 1;
            if (arr[i] == arr[j] && dp[i + 1][j - 1]) {
                dp[i][j] = 1;
            }
        }
    }

    while (M--) {
        int S, E;
        cin >> S >> E;
        cout << dp[S][E] << '\n';
    }

    return 0;
}
