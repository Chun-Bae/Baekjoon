#include <iostream>
using namespace std;

char arr[501][501];
char win_arr[4][4];

void init() {
    cin.tie(NULL);
    cout.tie(NULL);
    ios::sync_with_stdio(false);
}

void set_window(int i, int j, const char arr[501][501]) {
    for (int y = 0; y < 4; y++) {
        for (int x = 0; x < 4; x++) {
            win_arr[y][x] = arr[i * 5 + 1 + y][j * 5 + 1 + x];
        }
    }
}
int match_blind_type() {
    int type = 0;
    for (int i = 0; i < 4; i++)
        if (win_arr[i][0] == '*') type++;
    return type;
}

int main() {
    init();
    int M, N;
    int cnt[5] = {0, 0, 0, 0, 0};
    cin >> M >> N;
    int Y = 5 * M + 1;
    int X = 5 * N + 1;

    for (int i = 0; i < Y; i++) {
        for (int j = 0; j < X; j++) {
            cin >> arr[i][j];
        }
    }

    for (int i = 0; i < M; i++) {
        for (int j = 0; j < N; j++) {
            set_window(i, j, arr);
            cnt[match_blind_type()]++;
        }
    }
    for (auto i : cnt) cout << i << ' ';

    return 0;
}
