#include <iostream>
#include <queue>
#include <algorithm>

using namespace std;

// 상하좌우로 이동하기 위한 방향 배열
int dx[] = {-1, 1, 0, 0};
int dy[] = {0, 0, -1, 1};

int n, m; // 연구소의 크기 (세로, 가로)
int maxSafeArea = 0; // 최대 안전 영역의 크기
int lab[8][8]; // 연구소의 초기 상태
int originalLab[8][8]; // 벽을 세운 후의 임시 연구소 상태

void init(){
    cin.tie(NULL);
    cout.tie(NULL);
    ios::sync_with_stdio(false);
}

// 연구소 상태를 복사하는 함수
void copyLab(int (*dest)[8], int (*src)[8]) {
    for (int i = 0; i < n; i++) 
        for (int j = 0; j < m; j++) 
            dest[i][j] = src[i][j];
} 

// BFS를 사용하여 바이러스를 퍼뜨리는 함수
void bfs() {
    int spreadLab[8][8]; // 바이러스가 퍼진 후의 연구소 상태
    copyLab(spreadLab, originalLab);

    queue<pair<int, int>> q;
    // 초기 바이러스 위치를 큐에 추가
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            if (spreadLab[i][j] == 2) 
                q.push(make_pair(i, j));    

    // BFS를 사용하여 바이러스를 퍼뜨림
    while (!q.empty()) {
        int x = q.front().first;
        int y = q.front().second;
        q.pop();
        for (int i = 0; i < 4; i++) {
            int nx = x + dx[i];
            int ny = y + dy[i];
            
            // 범위 내에 있고 빈 칸인 경우 바이러스를 퍼뜨림
            if (0 <= nx && nx < n && 0 <= ny && ny < m) {
                if (spreadLab[nx][ny] == 0) {
                    spreadLab[nx][ny] = 2;
                    q.push(make_pair(nx, ny));
                }
            }
        }
    }

    // 오염되지 않은 안전 영역의 크기 계산
    int safeArea = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (spreadLab[i][j] == 0)
                safeArea++;
        }
    }
    maxSafeArea = max(maxSafeArea, safeArea);
}

// 벽을 세우는 함수: 모든 벽을 세우는 경우를 구함.
void buildWall(int count) {
    // 벽이 3개 세워졌을 때 바이러스를 퍼뜨림
    if (count == 3) {
        bfs();
        return;
    }
    // 빈 칸에 벽을 세움
    for (int i = 0; i < n; i++) 
        for (int j = 0; j < m; j++) 
            if (originalLab[i][j] == 0) {
                originalLab[i][j] = 1;
                buildWall(count + 1);
                // 기존의 벽을 다시 빈 칸으로 돌려놓음
                originalLab[i][j] = 0;
            }
}

int main() {
    init();
    
    scanf("%d %d", &n, &m);

    // 연구소의 초기 상태 입력
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            scanf("%d", &lab[i][j]);

    // 모든 빈 칸에 대해 벽을 세우고 바이러스 퍼뜨림
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (lab[i][j] == 0) {
                copyLab(originalLab, lab);
                originalLab[i][j] = 1;
                buildWall(1);
                originalLab[i][j] = 0;
            }
        }
    }
    // 최대 안전 영역의 크기 출력
    printf("%d\n", maxSafeArea);
}
