#include <algorithm>
#include <cstring>
#include <iostream>

#define MOD 1000

using namespace std;

typedef long long ll;

int dp[5][5][38];
int result[5][5];

void init() {
    cin.tie(NULL);
    cout.tie(NULL);
    ios::sync_with_stdio(false);
}

int main() {
    init();
    int N;
    ll B;
    cin >> N >> B;
    // 단위 행렬 I
    for (int i = 0; i < N; i++) result[i][i] = 1;

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cin >> dp[i][j][0];
        }
    }
    // 분할 정복
    for (int log = 1; log <= 37; log++) {
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < N; j++) {
                for (int k = 0; k < N; k++) {
                    // 행렬 곱
                    dp[i][j][log] = (dp[i][j][log] + ((dp[i][k][log - 1] % MOD) * (dp[k][j][log - 1] % MOD)) % MOD) % MOD;
                }
            }
        }
    }
    // 이진
    string bin = "";
    while (B) {
        bin += to_string(B % 2);
        B /= 2;
    }

    int log = 0;
    for (char b : bin) {
        int digit = (b - '0');
        int temp[5][5] = {0}; // 행렬곱할 때 숫자 바뀌므로 temp 생성
        if (digit) {
            for (int i = 0; i < N; i++) {
                for (int j = 0; j < N; j++) {
                    for (int k = 0; k < N; k++) {
                        temp[i][j] = (temp[i][j] + (result[i][k] * dp[k][j][log] % MOD)) % MOD;
                    }
                }
            }
            memcpy(result, temp, sizeof(result));
        }

        log++;
    }
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cout << result[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}