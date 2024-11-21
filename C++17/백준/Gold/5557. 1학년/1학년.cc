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

int main() {
    init();
    int N;
    cin >> N;
    vec1 numbers(N);
    for (int i = 0; i < N; i++) cin >> numbers[i];

    vector<vector<ll>> dp(N, vector<ll>(21, 0));
    dp[0][numbers[0]] = 1;

    for (int i = 1; i < N - 1; ++i) {
        for (int j = 0; j <= 20; ++j) {
            if (dp[i - 1][j] > 0) {
                if (j + numbers[i] <= 20) dp[i][j + numbers[i]] += dp[i - 1][j];
                if (j - numbers[i] >= 0) dp[i][j - numbers[i]] += dp[i - 1][j];
            }
        }
    }
    cout << dp[N - 2][numbers[N - 1]] << '\n';
    return 0;
}