#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

void print_vec2(vector<vector<int>> arr) {
    printf("=============\n");
    for (int r = 0; r < arr.size(); r++) {
        for (int c = 0; c < arr[0].size(); c++)
            printf("%2d ", arr[r][c]);
        cout << "\n";
    }
}

int main() {
    int N, M;
    vector<vector<int>> maze;
    vector<vector<int>> dp;

    cin >> N >> M;
    maze.resize(N + 1, vector<int>(M + 1, 0));
    dp.resize(N + 1, vector<int>(M + 1, 0));

    for (int r = 1; r <= N; r++) {
        for (int c = 1; c <= M; c++) {
            cin >> maze[r][c];
            dp[r][c] = maze[r][c];
        }
    }

    for (int r = 1; r <= N; r++) {
        for (int c = 1; c <= M; c++) {
            int c1 = dp[r - 1][c];
            int c2 = dp[r][c - 1];
            int c3 = dp[r - 1][c - 1];

            dp[r][c] += max({c1, c2, c3});
            // print_vec2(dp);
        }
    }

    cout << dp[N][M];
    return 0;
}