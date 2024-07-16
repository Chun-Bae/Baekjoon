#include <algorithm>
#include <climits>
#include <iostream>
using namespace std;

// Min Cumulative matrix Multiplication (DP)
int mcmm[501][501];  // dp[501][501]
// matrix Element
int mat_e[501][2];

void init() {
    cin.tie(NULL);
    cout.tie(NULL);
    ios::sync_with_stdio(false);
}

int main() {
    init();
    int N;
    cin >> N;
    for (int i = 1; i <= N; i++) {
        cin >> mat_e[i][0] >> mat_e[i][1];
    }

    for (int len = 2; len <= N; len++) {
        for (int i = 1; i <= N - len + 1; i++) {
            // i는 최종으로 갈수록 적어지고 len은 최종으로 갈수록 커진다.
            int j = i + len - 1;
            mcmm[i][j] = INT_MAX;
            // mcmm[1][4]라하면 A~D까지의 최소 곱셈 연산 횟수 (1=A, 2=B, 3=C, 4=D 이런 식)
            for (int k = i; k < j; k++) {
                // (A)(BCD)
                // mcmm[1][1] + mcmm[2][4] + (A의 행 수 * A의 열 수 * D의 열 수)
                // (AB)(CD)
                // mcmm[1][2] + mcmm[3][4] + (A의 행 수 * B의 열 수 * D의 열 수)
                // (ABC)(D)
                // mcmm[1][3] + mcmm[4][4] + (A의 행 수 * C의 열 수 * D의 열 수)

                // 여기서 mcmm[1][3]를 예로 들면 A~C까지의 최소 곱셈 연산 횟수
                mcmm[i][j] = min(mcmm[i][j], mcmm[i][k] + mcmm[k + 1][j] + mat_e[i][0] * mat_e[k][1] * mat_e[j][1]);
            }
        }
    }

    cout << mcmm[1][N] << "\n";
    return 0;
}