#include <iostream>

using namespace std;

typedef long long ll;

void init() {
    cin.tie(NULL);
    cout.tie(NULL);
    ios::sync_with_stdio(false);
}

int grid[18][18];
int n;

void dfs(int x, int y, int direction) {
    // 좌표 숫자 증가로 확인
    grid[x][y]++;

    // 가로로 움직이기 (가로, 대각상태일 때)
    if (direction == 0 || direction == 2) {
        if (y < n && grid[x][y + 1] != -1) dfs(x, y + 1, 0);
    }
    // 세로로 움직이기 (세로, 대각상태일 때)
    if (direction == 1 || direction == 2) {
        if (x < n && grid[x + 1][y] != -1) dfs(x + 1, y, 1);
    }
    // 대각선으로 움직이기 (세 군데 빈칸이어야 함)
    if (x < n && y < n && grid[x][y + 1] != -1 && grid[x + 1][y] != -1 && grid[x + 1][y + 1] != -1) dfs(x + 1, y + 1, 2);
}

int main() {
    init();

    cin >> n;

    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= n; j++) {
            // 좌표 누적합을 위해 벽을 -1로 변경.
            cin >> grid[i][j];
            grid[i][j] ? grid[i][j] = -1 : grid[i][j] = 0;
        } 
    dfs(1, 2, 0);
    // 알고보니 도착지도 벽으로 뒀다면 dfs해도 -1로 저장되어 있을 것.
    if(grid[n][n]==-1) grid[n][n] = 0;

    cout<<grid[n][n];

    return 0;
}