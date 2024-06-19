#include <algorithm>
#include <iostream>
#define MAX 20

using namespace std;

int R, C;                    // 행과 열의 크기
char board[MAX][MAX];        // 보드에 쓰여진 알파벳을 저장하는 배열
bool visited[26] = {false};  // 방문한 알파벳을 추적하는 배열

// 네 방향 이동을 위한 변화량: 상, 하, 좌, 우
int dx[4] = {-1, 1, 0, 0};
int dy[4] = {0, 0, -1, 1};

int maxPathLength = 0;  // 최대 경로 길이


void dfs(int row, int col, int pathLength) {
    // max
    maxPathLength = max(pathLength, maxPathLength);

    // 네 방향 탐색
    for (int dir = 0; dir < 4; ++dir) {
        int newRow = row + dx[dir];
        int newCol = col + dy[dir];

        // 보드 범위 내에 있고, 방문하지 않은 알파벳이면 탐색
        if (newRow >= 0 && newRow < R && newCol >= 0 && newCol < C) {
            int idx = board[newRow][newCol] - 'A';

            if (!visited[idx]) {
                visited[idx] = true;
                dfs(newRow, newCol, pathLength + 1);
                visited[idx] = false;  // 방문 상태 원상 복귀
            }
        }
    }
}

void init() {
    cin.tie(NULL);
    cout.tie(NULL);
    ios::sync_with_stdio(false);
}

int main() {
    init();
    cin >> R >> C;

    for (int i = 0; i < R; ++i) {
        for (int j = 0; j < C; ++j) {
            cin >> board[i][j];
        }
    }
    
    visited[board[0][0] - 'A'] = true;
    //  dfs(int row, int col, int pathLength)
    dfs(0, 0, 1);

    cout << maxPathLength << endl;
    return 0;
}