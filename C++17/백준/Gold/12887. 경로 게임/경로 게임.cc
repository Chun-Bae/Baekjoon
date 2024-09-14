#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#define INF 1e9

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
    int M;
    cin >> M;
    vector<string> grid(2);
    cin >> grid[0];
    cin >> grid[1];

    vec2 dp(2, vec1(M, INF));

    for (int row = 0; row < 2; ++row) {
        if (grid[row][0] == '.') {
            dp[row][0] = 0;
        }
    }

    for (int col = 1; col < M; ++col) {
        for (int row = 0; row < 2; ++row) {
            if (grid[row][col] == '.') {
                if (grid[row][col - 1] == '.') {
                    dp[row][col] = min(dp[row][col], dp[row][col - 1]);
                }
                if (grid[1 - row][col - 1] == '.') {
                    dp[row][col] = min(dp[row][col], dp[1 - row][col - 1] + 1);
                }
            }
        }
    }

    int min_row_changes = INF;
    for (int row = 0; row < 2; ++row) {
        if (grid[row][M - 1] == '.') {
            min_row_changes = min(min_row_changes, dp[row][M - 1]);
        }
    }

    int total_white_cells = 0;
    for (int row = 0; row < 2; ++row) {
        for (int col = 0; col < M; ++col) {
            if (grid[row][col] == '.') {
                total_white_cells++;
            }
        }
    }

    if (min_row_changes == INF) {
        cout << 0 << endl;
    } else {
        int minimal_white_cells_needed = M + min_row_changes;
        int result = total_white_cells - minimal_white_cells_needed;
        cout << result << endl;
    }
    return 0;
}