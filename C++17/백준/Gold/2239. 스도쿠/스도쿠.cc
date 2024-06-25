#include <iostream>

using namespace std;

typedef long long ll;

int sdocu[81][81];

void init() {
    cin.tie(NULL);
    cout.tie(NULL);
    ios::sync_with_stdio(false);
}

void dfs(int x, int y, int cnt) {
    if (cnt == 81) {
        for (int i = 0; i < 9; i++) {
            for (int j = 0; j < 9; j++) {
                cout << sdocu[i][j];
            }
            cout << '\n';
        }
        exit(0);
    }
    if (sdocu[x][y] == 0) {
        for (int i = 1; i <= 9; i++) {
            bool flag = true;
            for (int j = 0; j < 9; j++) {
                // 가로, 세로, 3x3 사각형 검사
                if (sdocu[x][j] == i || sdocu[j][y] == i || sdocu[(x / 3) * 3 + j / 3][(y / 3) * 3 + j % 3] == i) {
                    flag = false;
                    break;
                }
            }
            if (flag) {
                sdocu[x][y] = i;
                if (y == 8) {
                    dfs(x + 1, 0, cnt + 1);
                } else {
                    dfs(x, y + 1, cnt + 1);
                }
                sdocu[x][y] = 0;
            }
        }
    } else {
        if (y == 8) {
            dfs(x + 1, 0, cnt + 1);
        } else {
            dfs(x, y + 1, cnt + 1);
        }
    }
}
int main() {
    init();
    for (int i = 0; i < 9; i++) {
        string str;
        cin >> str;
        for(int j = 0; j < 9; j++) sdocu[i][j] = str[j] - '0';
    }
    dfs(0, 0, 0);
    return 0;
}