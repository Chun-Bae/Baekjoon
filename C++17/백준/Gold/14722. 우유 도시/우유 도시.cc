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
    vec2 city(N, vec1(N));
    vec2 dp(N, vec1(N, 0));

    for (int i = 0; i < N; ++i)
        for (int j = 0; j < N; ++j) cin >> city[i][j];

    if (city[0][0] == 0)
        dp[0][0] = 1;
    else
        dp[0][0] = 0;

    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < N; ++j) {
            if (i == 0 && j == 0) continue;

            int up = 0, left = 0;
            if (i > 0) up = dp[i - 1][j];
            if (j > 0) left = dp[i][j - 1];

            dp[i][j] = max(up, left);

            if (city[i][j] == dp[i][j] % 3) dp[i][j]++;
        }
    }

    cout << dp[N - 1][N - 1] << "\n";
    return 0;
}