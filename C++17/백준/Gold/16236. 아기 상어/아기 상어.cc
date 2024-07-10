#include <cstring>  // for memset
#include <iostream>
#include <queue>
#include <vector>

using namespace std;

const int MAX = 22;
int n;
int sea[MAX][MAX];
int visited[MAX][MAX];
int dx[] = {0, -1, 1, 0};  // 상좌우하
int dy[] = {-1, 0, 0, 1};
int shark_x, shark_y, shark_size = 2, fish_eaten = 0, total_time = 0;
bool stop_simulation = false;  // 먹을 물고기가 없는 경우
bool ate_fish = false;         // 한 마리를 먹은 경우

void bfs() {
    memset(visited, 0, sizeof(visited));  // 방문 초기화
    int dist = 0;
    queue<pair<int, int>> shark;                                                                                          // 상어 위치
    priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, greater<pair<int, pair<int, int>>>> fishes;  // 물고기 위치 및 거리
    shark.push({shark_x, shark_y});
    visited[shark_y][shark_x] = 1;

    while (!shark.empty()) {
        int q_size = shark.size();
        for (int i = 0; i < q_size; i++) {
            int cur_x = shark.front().first;
            int cur_y = shark.front().second;
            shark.pop();

            for (int j = 0; j < 4; j++) {
                int nx = cur_x + dx[j];
                int ny = cur_y + dy[j];

                if (nx < 0 || nx >= n || ny < 0 || ny >= n) continue;
                if (visited[ny][nx] || sea[ny][nx] > shark_size) continue;

                // visited에 거리 저장
                visited[ny][nx] = visited[cur_y][cur_x] + 1;
                shark.push({nx, ny});
                if (sea[ny][nx] != 0 && sea[ny][nx] < shark_size) {
                    // 물고기 거리 및 위치 저장
                    fishes.push({visited[ny][nx], {ny, nx}});
                }
            }
        }
        // bfs로 발견한 최소 위치의 물고기들,
        // 먹을 수 있는 물고기가 있는데 그 여러 물고기 중 가장 가까운 물고기를 먹는다
        if (!fishes.empty()) {
            pair<int, int> fish = fishes.top().second;
            total_time += fishes.top().first - 1;
            fishes.pop();
            shark_x = fish.second;
            shark_y = fish.first;
            sea[shark_y][shark_x] = 0;
            ate_fish = true;
            return;
        }
    }
}

void init() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
}

int main() {
    init();
    cin >> n;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> sea[i][j];
            if (sea[i][j] == 9) {
                shark_y = i;
                shark_x = j;
                sea[i][j] = 0;
            }
        }
    }

    while (!stop_simulation) {
        bfs();           // 한 마리 먹을때까지 이동
        if (ate_fish) {  // 먹었을 경우
            ate_fish = false;
            fish_eaten += 1;                 // 현재 크기에서 물고기 먹은 횟수 증가
            if (fish_eaten == shark_size) {  // 상어 크기가 증가하는 경우
                shark_size += 1;             // 상어 사이즈 +1
                fish_eaten = 0;              // 현재 크기에서 물고기 먹은 횟수 초기화
            }
        } else {  // 한 마리도 못먹는 경우
            stop_simulation = true;
        }
    }

    cout << total_time << '\n';
    return 0;
}
