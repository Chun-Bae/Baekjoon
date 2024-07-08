#include <iostream>
#include <vector>

using namespace std;

int R, C, T;
int dust[51][51];
int temp[51][51];
pair<int, int> cleaner1, cleaner2;

void init() {
    cin.tie(NULL);
    cout.tie(NULL);
    ios::sync_with_stdio(false);
}

void spread_dust() {
    for (int i = 0; i < R; ++i) {
        for (int j = 0; j < C; ++j) {
            if (dust[i][j] > 0) {
                int amount = dust[i][j] / 5;
                if (i > 0 && dust[i - 1][j] != -1) { // 위
                    temp[i - 1][j] += amount;
                    temp[i][j] -= amount;
                }
                if (i < R - 1 && dust[i + 1][j] != -1) { // 아래
                    temp[i + 1][j] += amount;
                    temp[i][j] -= amount;
                }
                if (j > 0 && dust[i][j - 1] != -1) { // 왼쪽
                    temp[i][j - 1] += amount;
                    temp[i][j] -= amount;
                }
                if (j < C - 1 && dust[i][j + 1] != -1) { // 오른쪽
                    temp[i][j + 1] += amount;
                    temp[i][j] -= amount;
                }
            }
        }
    }
    for (int i = 0; i < R; ++i) {
        for (int j = 0; j < C; ++j) {
            dust[i][j] += temp[i][j];
        }
    }
}

void operate_cleaner() {
    // opper
    for (int i = cleaner1.first - 1; i > 0; --i) dust[i][0] = dust[i - 1][0];
    for (int i = 0; i < C - 1; ++i) dust[0][i] = dust[0][i + 1];
    for (int i = 0; i < cleaner1.first; ++i) dust[i][C - 1] = dust[i + 1][C - 1];
    for (int i = C - 1; i > 1; --i) dust[cleaner1.first][i] = dust[cleaner1.first][i - 1];
    dust[cleaner1.first][1] = 0;

    // lower
    for (int i = cleaner2.first + 1; i < R - 1; ++i) dust[i][0] = dust[i + 1][0];
    for (int i = 0; i < C - 1; ++i) dust[R - 1][i] = dust[R - 1][i + 1];
    for (int i = R - 1; i > cleaner2.first; --i) dust[i][C - 1] = dust[i - 1][C - 1];
    for (int i = C - 1; i > 1; --i) dust[cleaner2.first][i] = dust[cleaner2.first][i - 1];
    dust[cleaner2.first][1] = 0;
}

int main() {
    init();
    cin >> R >> C >> T;

    for (int i = 0; i < R; ++i) {
        for (int j = 0; j < C; ++j) {
            cin >> dust[i][j];
            if (dust[i][j] == -1) {
                if (cleaner1.first == 0) cleaner1 = {i, j};
                else cleaner2 = {i, j};
            }
        }
    }

    while (T--) {
        fill(&temp[0][0], &temp[0][0] + sizeof(temp) / sizeof(temp[0][0]), 0);
        spread_dust();
        operate_cleaner();
    }

    int total_dust = 0;
    for (int i = 0; i < R; ++i) {
        for (int j = 0; j < C; ++j) {
            if (dust[i][j] > 0) {
                total_dust += dust[i][j];
            }
        }
    }

    cout << total_dust << '\n';
    return 0;
}
