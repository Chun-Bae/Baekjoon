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

    vec1 T(N + 1);
    vec1 P(N + 1);
    vec1 dp(N + 2, 0);

    for (int i = 1; i <= N; ++i) cin >> T[i] >> P[i];

    for (int i = N; i >= 1; --i) {
        if (i + T[i] <= N + 1) {
            dp[i] = max(dp[i + 1], P[i] + dp[i + T[i]]);
        } else {
            dp[i] = dp[i + 1];
        }
    }

    cout << dp[1] << endl;
    return 0;
}