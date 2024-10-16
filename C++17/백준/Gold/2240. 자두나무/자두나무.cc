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
int dp[1001][31][2];
int fall[1001];

int main() {
    init();
    int T, W;
    cin >> T >> W;

    for (int i = 1; i <= T; i++) {
        cin >> fall[i];
    }

    if (fall[1] == 1)
        dp[1][0][0] = 1;
    else
        dp[1][0][0] = 0;

    if (fall[1] == 2)
        dp[1][1][1] = 1;
    else
        dp[1][1][1] = 0;

    for (int t = 2; t <= T; t++) {
        for (int w = 0; w <= W; w++) {
            dp[t][w][0] = dp[t - 1][w][0];
            if (w > 0) {
                dp[t][w][0] = max(dp[t][w][0], dp[t - 1][w - 1][1]);
            }
            if (fall[t] == 1) dp[t][w][0]++;

            dp[t][w][1] = dp[t - 1][w][1];
            if (w > 0) {
                dp[t][w][1] = max(dp[t][w][1], dp[t - 1][w - 1][0]);
            }
            if (fall[t] == 2) dp[t][w][1]++;
        }
    }

    int result = 0;
    for (int w = 0; w <= W; w++) {
        result = max(result, dp[T][w][0]);
        result = max(result, dp[T][w][1]);
    }

    cout << result << endl;

    return 0;
}