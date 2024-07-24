#include <cstring>
#include <iostream>
#include <queue>
#include <vector>

using namespace std;

int N, M;
vector<vector<int>> cheese;
int visited[101][101];
int directions[4][2] = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};

// 외부 부분은 1로 표시
void markOutsideAir() {
    memset(visited, 0, sizeof(visited));
    queue<pair<int, int>> q;
    q.push({0, 0});
    visited[0][0] = 1;

    while (!q.empty()) {
        int x = q.front().first;
        int y = q.front().second;
        q.pop();

        for (int i = 0; i < 4; i++) {
            int nx = x + directions[i][0];
            int ny = y + directions[i][1];

            if (nx >= 0 && nx < N && ny >= 0 && ny < M && !visited[nx][ny] && cheese[nx][ny] == 0) {
                visited[nx][ny] = 1;
                q.push({nx, ny});
            }
        }
    }
}

int meltCheese() {
    int time = 0;
    while (true) {
        markOutsideAir();

        bool melted = false;
        vector<pair<int, int>> toMelt;

        for (int i = 0; i < N; i++) {
            for (int j = 0; j < M; j++) {
                if (cheese[i][j] == 1) {
                    int airCount = 0;
                    for (int k = 0; k < 4; k++) {
                        int nx = i + directions[k][0];
                        int ny = j + directions[k][1];
                        if (visited[nx][ny] == 1) {
                            airCount++;
                        }
                    }
                    if (airCount >= 2) {
                        toMelt.push_back({i, j});
                        melted = true;
                    }
                }
            }
        }

        for (auto& pos : toMelt) {
            cheese[pos.first][pos.second] = 0;
        }

        if (!melted) break;
        time++;
    }
    return time;
}

void init() {
    cin.tie(NULL);
    cout.tie(NULL);
    ios::sync_with_stdio(false);
}

int main() {
    cin >> N >> M;
    cheese.resize(N, vector<int>(M));

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            cin >> cheese[i][j];
        }
    }

    cout << meltCheese() << '\n';
    return 0;
}
