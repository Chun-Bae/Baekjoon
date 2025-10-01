#include <algorithm>
#include <iostream>
#include <queue>
#include <vector>

using namespace std;

void print_grid(vector<vector<int>> grid,int M,int N) {
    cout<<"================="<<endl;
    for (int i = 0; i < M; i++) {
        for (int j = 0; j < N; j++) {
            cout << grid[i][j];
        }
        cout << endl;
    }
}

int main() {
    vector<vector<int>> grid;
    vector<vector<int>> visited;
    queue<pair<int, int>> q;
    vector<pair<int, int>> dxdy = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
    vector<int> cnt;
    int M, N, K;
    cin >> M >> N >> K;
    grid.resize(M, vector<int>(N, 0));
    visited.resize(M, vector<int>(N, 0));

    while (K--) {
        int x1, y1, x2, y2;
        cin >> y1 >> x1 >> y2 >> x2;
        for (int i = x1; i < x2; i++) {
            for (int j = y1; j < y2; j++) {
                grid[i][j] = 1;
                visited[i][j] = 1;
            }
        }
    }

    for (int i = 0; i < M; i++) {
        for (int j = 0; j < N; j++) {
            if (visited[i][j] == 1) continue;
            int ccnt = 0;
            q.push({i, j});
            visited[i][j] = 1;

            while (!q.empty()) {
                pair<int, int> t = q.front();
                q.pop();
                ccnt++;

                for (int f = 0; f < 4; f++) {
                    int t_x = t.first + dxdy[f].first;
                    int t_y = t.second + dxdy[f].second;
                    if (t_x < 0 || t_y < 0 || t_x >= M || t_y >= N) continue;
                    if (visited[t_x][t_y] == 0) {
                        visited[t_x][t_y] = 1;
                        q.push({t_x, t_y});
                    }
                }
            }
            cnt.push_back(ccnt);
        }
    }
    sort(cnt.begin(), cnt.end());
    cout << cnt.size() << endl;
    for (auto c : cnt) printf("%d ", c);

    return 0;
}