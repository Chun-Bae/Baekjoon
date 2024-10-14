#include <algorithm>
#include <cstring>
#include <iostream>
#include <queue>
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
int n, m;
int board[100][100];
bool visited[100][100];
int dx[] = {-1, 1, 0, 0};
int dy[] = {0, 0, -1, 1};

void bfs() {
    queue<pair<int, int>> q;
    q.push({0, 0});
    visited[0][0] = true;

    while (!q.empty()) {
        auto cur = q.front();
        q.pop();
        int x = cur.first;
        int y = cur.second;

        for (int i = 0; i < 4; i++) {
            int nx = x + dx[i];
            int ny = y + dy[i];

            if (nx < 0 || ny < 0 || nx >= n || ny >= m) continue;
            if (visited[nx][ny]) continue;

            if (board[nx][ny] == 0) {
                q.push({nx, ny});
                visited[nx][ny] = true;
            } else if (board[nx][ny] == 1) {
                board[nx][ny] = 2;
                visited[nx][ny] = true;
            }
        }
    }
}

int countCheese() {
    int count = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (board[i][j] == 1) count++;
        }
    }
    return count;
}

int main() {
    init();
    cin >> n >> m;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> board[i][j];
        }
    }

    int time = 0;
    int lastCheese = 0;

    while (true) {
        memset(visited, false, sizeof(visited));
        int currentCheese = countCheese();

        if (currentCheese == 0) {
            cout << time << '\n' << lastCheese << '\n';
            break;
        }

        lastCheese = currentCheese;
        bfs();
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (board[i][j] == 2) board[i][j] = 0;
            }
        }

        time++;
    }

    return 0;
}