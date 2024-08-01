#include <iostream>
#include <vector>

using namespace std;

vector<vector<char>> directions;
vector<vector<int>> visited;
int N, M;

int dx[] = {-1, 1, 0, 0};
int dy[] = {0, 0, -1, 1};

int dfs(int x, int y, int id) {
    visited[x][y] = id;
    int nx, ny;

    if (directions[x][y] == 'U') {
        nx = x + dx[0];
        ny = y + dy[0];
    } else if (directions[x][y] == 'D') {
        nx = x + dx[1];
        ny = y + dy[1];
    } else if (directions[x][y] == 'L') {
        nx = x + dx[2];
        ny = y + dy[2];
    } else if (directions[x][y] == 'R') {
        nx = x + dx[3];
        ny = y + dy[3];
    }

    if (visited[nx][ny] == 0) {
        return dfs(nx, ny, id);
    } else if (visited[nx][ny] == id) {
        return 1;
    } else {
        return 0;
    }
}

void init() {
    cin.tie(NULL);
    cout.tie(NULL);
    ios::sync_with_stdio(false);
}

int main() {
    init();
    cin >> N >> M;
    directions.resize(N, vector<char>(M));
    visited.resize(N, vector<int>(M, 0));

    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < M; ++j) {
            cin >> directions[i][j];
        }
    }

    int safeZones = 0;
    int id = 1;
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < M; ++j) {
            if (visited[i][j] == 0) {
                safeZones += dfs(i, j, id);
                id++;
            }
        }
    }

    cout << safeZones << "\n";

    return 0;
}
