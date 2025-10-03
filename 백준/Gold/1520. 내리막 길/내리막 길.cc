#include <algorithm>
#include <iostream>
#include <queue>
#include <vector>

using namespace std;

int N;
int M;
vector<vector<int>> atlas;
vector<vector<int>> dp;

void print_vec2(vector<vector<int>> arr) {
    cout << "\n=================\n";
    for (int r = 1; r < arr.size(); r++) {
        for (int c = 1; c < arr[0].size(); c++) {
            printf("%2d ", arr[r][c]);
        }
        cout << "\n";
    }
}

int dfs(pair<int, int> cur) {
    int dr = cur.first;
    int dc = cur.second;
    if (dp[dr][dc] != -1) {
        return dp[dr][dc];
    }

    int sum = 0;
    if (dr + 1 <= N)
        if (atlas[dr][dc] > atlas[dr + 1][dc]) {
            sum += dfs({dr + 1, dc});
        }
    if (dc + 1 <= M)
        if (atlas[dr][dc] > atlas[dr][dc + 1]) {
            sum += dfs({dr, dc + 1});
        }
    if (dr - 1 >= 1)
        if (atlas[dr][dc] > atlas[dr - 1][dc]) {
            sum += dfs({dr - 1, dc});
        }
    if (dc - 1 >= 1)
        if (atlas[dr][dc] > atlas[dr][dc - 1]) {
            sum += dfs({dr, dc - 1});
        }
    dp[dr][dc] = sum;
    return sum;
}

int main() {
    cin >> N >> M;
    atlas.resize(N + 1, vector<int>(M + 1, 0));
    dp.resize(N + 1, vector<int>(M + 1, -1));

    for (int r = 1; r <= N; r++)
        for (int c = 1; c <= M; c++)
            cin >> atlas[r][c];

    dp[N][M] = 1;
    cout << dfs({1, 1});

    return 0;
}