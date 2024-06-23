#include <iostream>
#include <queue>
#include <vector>

using namespace std;

void init() {
    cin.tie(NULL);
    cout.tie(NULL);
    ios::sync_with_stdio(false);
}

const int MAX = 100000;
int visit[MAX + 1];

void bfs(int N, int K) {
    queue<pair<int, int>> q;
    fill(visit, visit + MAX + 1, -1);
    q.push({N, 0});
    visit[N] = N;

    while (!q.empty()) {
        int current = q.front().first;
        int time = q.front().second;
        q.pop();

        if (current == K) {
            cout << time << '\n';
            // 역추적
            vector<int> path;
            for (int i = K; i != N; i = visit[i]) path.push_back(i);
            path.push_back(N);

            for (int i = path.size() - 1; i >= 0; i--) cout << path[i] << " ";
            cout << '\n';
            return;
        }

        vector<int> next_positions = {current - 1, current + 1, current * 2};
        for (int next : next_positions) {
            if (next >= 0 && next <= MAX && visit[next] == -1) {
                q.push({next, time + 1});
                visit[next] = current;
            }
        }
    }
}

int main() {
    init();
    int N, K;
    cin >> N >> K;
    bfs(N, K);
    return 0;
}
