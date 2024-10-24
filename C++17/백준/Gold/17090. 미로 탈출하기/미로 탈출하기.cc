#include <algorithm>
#include <iostream>
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
int N, M;
vector<vector<char>> maze;
vector<vector<int>> visited;
vector<vector<bool>> canEscape;

int dx[] = {-1, 0, 1, 0};
int dy[] = {0, 1, 0, -1};

int getDirection(char c) {
    if (c == 'U') return 0;
    if (c == 'R') return 1;
    if (c == 'D') return 2;
    if (c == 'L') return 3;
    return -1;
}
bool dfs(int x, int y) {
    if (x < 0 || x >= N || y < 0 || y >= M) {
        return true;
    }

    if (visited[x][y] != -1) {
        return canEscape[x][y];
    }

    visited[x][y] = 1;

    int dir = getDirection(maze[x][y]);
    int nx = x + dx[dir];
    int ny = y + dy[dir];

    canEscape[x][y] = dfs(nx, ny);

    return canEscape[x][y];
}
int main() {
    init();
    cin >> N >> M;
    maze.resize(N, vector<char>(M));
    visited.resize(N, vector<int>(M, -1));
    canEscape.resize(N, vector<bool>(M, false));

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            cin >> maze[i][j];
        }
    }

    int result = 0;

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            if (dfs(i, j)) {
                result++;
            }
        }
    }

    cout << result << endl;
    return 0;
}