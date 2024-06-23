#include <iomanip>
#include <iostream>

using namespace std;

typedef long long ll;

double dp[2][10001];

void init() {
    cin.tie(NULL);
    cout.tie(NULL);
    ios::sync_with_stdio(false);
}

int main() {
    init();
    int N;
    double max_prime = 0;
    cin >> N;
    for (int i = 0; i < N; i++) {
        cin >> dp[0][i];
        dp[1][i] = dp[0][i];
        if (dp[1][i] > max_prime) max_prime = dp[1][i];
    }
    int n = N;
    while (N--) {
        for (int i = 0; i < N; i++) {
            dp[1][i] = dp[1][i] * dp[0][(n - N) + i];
            if (max_prime < dp[1][i]) max_prime = dp[1][i];
        }
    }
    cout << fixed << setprecision(3) << max_prime << endl;

    return 0;
}