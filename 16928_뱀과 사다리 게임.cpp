#include <iostream>
#include <queue>

using namespace std;

typedef long long ll;

int table[101];
int visit[101];

void init() {
    cin.tie(NULL);
    cout.tie(NULL);
    ios::sync_with_stdio(false);
}

void table_init(int N, int M) {
    int x, y;
    while (N--) {
        cin >> x >> y;
        table[x] = y;
    }
    while (M--) {
        cin >> x >> y;
        table[x] = y;
    }
}

void bfs(int x, int c) {
    queue<pair<int, int>> q;
    q.push(make_pair(x, c));
    while (!q.empty()) {
        int current = q.front().first;  // 현재 좌표
        int cnt = q.front().second;     // 카운트
        q.pop();

        for (int i = 1; i <= 6; i++) {
            int next = current + i;
            if (next == 100) {
                cout << cnt + 1;  // 도착했으면 출력
                return;
            } else if (next < 100) {
                // 사다리 혹은 뱀인지 확인 
                while (table[next] != 0) next = table[next]; // 점프한 자리로 이동
                if (!visit[next]) {
                    q.push(make_pair(next, cnt + 1));
                    visit[next] = true;
                }
            }
        }
    }
}

int main() {
    init();
    int N, M;
    cin >> N >> M;
    table_init(N, M);
    bfs(1, 0);
    return 0;
}