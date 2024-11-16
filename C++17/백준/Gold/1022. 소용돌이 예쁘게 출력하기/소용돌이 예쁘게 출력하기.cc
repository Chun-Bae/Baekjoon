#include <iomanip>
#include <iostream>
#include <string>
#include <vector>

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

    int r1, c1, r2, c2;
    cin >> r1 >> c1 >> r2 >> c2;

    int rows = r2 - r1 + 1;
    int cols = c2 - c1 + 1;
    vec2 grid(rows, vec1(cols));

    int total_cells = rows * cols;
    int filled_cells = 0;

    int x = 0, y = 0;
    int num = 1;
    int dir = 0;
    int steps = 1;
    int dir_changes = 0;
    int dx[4] = {0, -1, 0, 1};
    int dy[4] = {1, 0, -1, 0};

    int maxValue = 1;

    while (filled_cells < total_cells) {
        for (int i = 0; i < steps; ++i) {
            if (x >= r1 && x <= r2 && y >= c1 && y <= c2) {
                grid[x - r1][y - c1] = num;
                if (num > maxValue) maxValue = num;
                filled_cells++;
            }
            if (filled_cells == total_cells) break;
            x += dx[dir % 4];
            y += dy[dir % 4];
            num++;
        }
        dir = (dir + 1) % 4;
        dir_changes++;
        if (dir_changes == 2) {
            dir_changes = 0;
            steps++;
        }
    }

    int width = to_string(maxValue).length();

    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            cout << setw(width) << grid[i][j];
            if (j < cols - 1) cout << " ";
        }
        cout << "\n";
    }

    return 0;
}
