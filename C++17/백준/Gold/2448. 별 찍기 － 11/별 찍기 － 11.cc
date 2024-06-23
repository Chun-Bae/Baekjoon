#include <cmath>
#include <iostream>
#include <vector>

using namespace std;

void init() {
    cin.tie(NULL);
    cout.tie(NULL);
    ios::sync_with_stdio(false);
}

void drawStars(vector<vector<char>>& canvas, int y, int x, int size) {
    if (size == 3) {
        canvas[y][x] = '*';
        canvas[y + 1][x - 1] = '*';
        canvas[y + 1][x + 1] = '*';
        for (int i = -2; i <= 2; ++i) canvas[y + 2][x + i] = '*';
    } else {
        int newSize = size / 2;
        drawStars(canvas, y, x, newSize);
        drawStars(canvas, y + newSize, x - newSize, newSize);
        drawStars(canvas, y + newSize, x + newSize, newSize);
    }
}

int main() {
    init();
    int N;
    cin >> N;
    vector<vector<char>> canvas(N, vector<char>(2 * N - 1, ' '));

    drawStars(canvas, 0, N - 1, N);

    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < 2 * N - 1; ++j) {
            cout << canvas[i][j];
        }
        cout << '\n';
    }
    return 0;
}