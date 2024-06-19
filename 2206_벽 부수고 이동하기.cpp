#include <iostream>
#include <queue>
#include <vector>

using namespace std;

const int MAX = 1000;      // 그리드 최대 크기

// (-1, 0) (0, 1) (1, 0) (0, -1) 네 방향 이동
int dx[] = {-1, 0, 1, 0};  // 방향 배열: x 좌표
int dy[] = {0, 1, 0, -1};  // 방향 배열: y 좌표


int visit[MAX][MAX][2];    // 방문 및 이동 횟수 기록 배열
vector<vector<int>> grid;  // 그리드 정보
int N, M;                  // 그리드의 세로(N)와 가로(M) 크기

void init() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
}

void BFS() {
    queue<pair<pair<int, int>, int>> q;
    q.push({{0, 0}, 0});
    visit[0][0][0] = 1;

    while (!q.empty()) {
        auto front = q.front();
        q.pop();
        int x = front.first.first;
        int y = front.first.second;
        int broken = front.second;

        if (x == M - 1 && y == N - 1) {
            cout << visit[y][x][broken] << endl;
            return;
        }

        for (int i = 0; i < 4; i++) {
            // 상하좌우 증가
            int nx = x + dx[i];
            int ny = y + dy[i];
            // 인접 좌표가 범위 밖이거나 방문한 좌표일 경우
            if (ny < 0 || ny >= N || nx < 0 || nx >= M) continue;
            if (visit[ny][nx][broken]) continue;

            // 벽이 없는 경우
            if (grid[ny][nx] == 0) {
                visit[ny][nx][broken] = visit[y][x][broken] + 1;
                q.push({{nx, ny}, broken});
            }
            // 벽이 있고 아직 벽을 부수지 않은 경우
            else if (!broken) {
                visit[ny][nx][1] = visit[y][x][broken] + 1;
                q.push({{nx, ny}, 1});
            }
        }
    }

    // 목적지에 도달하지 못했을 경우
    cout << -1 << endl;
}

int main() {
    init();
    cin >> N >> M;
    grid.resize(N, vector<int>(M));

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            char c;
            cin >> c;            
            grid[i][j] = c - '0';
        }
    }
    BFS();
    return 0;
}