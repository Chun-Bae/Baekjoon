#include <algorithm>
#include <iostream>
#include <queue>
#include <string>
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
const int dx[4] = {1, -1, 0, 0};
const int dy[4] = {0, 0, 1, -1};

int w, h;
vector<string> building;
int fireTime[1000][1000];
int personTime[1000][1000];

void solve() {
    queue<pair<int, int>> fireQueue;
    queue<pair<int, int>> personQueue;

    for (int i = 0; i < h; ++i) {
        for (int j = 0; j < w; ++j) {
            fireTime[i][j] = -1;
            personTime[i][j] = -1;
            if (building[i][j] == '*') {
                fireQueue.push({i, j});
                fireTime[i][j] = 0;
            }
            if (building[i][j] == '@') {
                personQueue.push({i, j});
                personTime[i][j] = 0;
            }
        }
    }

    while (!fireQueue.empty()) {
        int x = fireQueue.front().second;
        int y = fireQueue.front().first;
        fireQueue.pop();

        for (int d = 0; d < 4; ++d) {
            int nx = x + dx[d];
            int ny = y + dy[d];

            if (nx >= 0 && nx < w && ny >= 0 && ny < h) {
                if (building[ny][nx] != '#' && fireTime[ny][nx] == -1) {
                    fireTime[ny][nx] = fireTime[y][x] + 1;
                    fireQueue.push({ny, nx});
                }
            }
        }
    }

    while (!personQueue.empty()) {
        int x = personQueue.front().second;
        int y = personQueue.front().first;
        personQueue.pop();

        for (int d = 0; d < 4; ++d) {
            int nx = x + dx[d];
            int ny = y + dy[d];

            if (nx < 0 || nx >= w || ny < 0 || ny >= h) {
                cout << personTime[y][x] + 1 << '\n';
                return;
            }

            if (building[ny][nx] == '.' && personTime[ny][nx] == -1) {
                if (fireTime[ny][nx] == -1 || fireTime[ny][nx] > personTime[y][x] + 1) {
                    personTime[ny][nx] = personTime[y][x] + 1;
                    personQueue.push({ny, nx});
                }
            }
        }
    }

    cout << "IMPOSSIBLE\n";
}
int main() {
    init();
    int t;
    cin >> t;
    while (t--) {
        cin >> w >> h;
        building.resize(h);

        for (int i = 0; i < h; ++i) {
            cin >> building[i];
        }

        solve();
    }
    return 0;
}