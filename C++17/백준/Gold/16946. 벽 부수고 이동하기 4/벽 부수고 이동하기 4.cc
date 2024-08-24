#include <iostream>
#include <vector>
#include <queue>
#include <unordered_map>

using namespace std;

typedef long long ll;
typedef vector<int> vec1;
typedef vector<vec1> vec2;
typedef vector<vec2> vec3;



using namespace std;

const int dx[4] = {0, 1, 0, -1};
const int dy[4] = {1, 0, -1, 0};

int n, m;
vec2 map;
vec2 group;
vec1 groupSize;

void init(){
    cin.tie(NULL);
    cout.tie(NULL);
    ios::sync_with_stdio(false);
}



int bfs(int x, int y, int groupId) {
    queue<pair<int, int>> q;
    q.push({x, y});
    group[x][y] = groupId;
    int cnt = 1;

    while (!q.empty()) {
        int cx = q.front().first;
        int cy = q.front().second;
        q.pop();

        for (int i = 0; i < 4; i++) {
            int nx = cx + dx[i];
            int ny = cy + dy[i];

            if (nx >= 0 && nx < n && ny >= 0 && ny < m) {
                if (map[nx][ny] == 0 && group[nx][ny] == -1) {
                    group[nx][ny] = groupId;
                    q.push({nx, ny});
                    cnt++;
                }
            }
        }
    }

    return cnt;
}

int main() {
    init();
    cin >> n >> m;
    map.resize(n, vector<int>(m));
    group.resize(n, vector<int>(m, -1));

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            char ch;
            cin >> ch;
            map[i][j] = ch - '0';
        }
    }

    int groupId = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (map[i][j] == 0 && group[i][j] == -1) {
                int size = bfs(i, j, groupId);
                groupSize.push_back(size);
                groupId++;
            }
        }
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (map[i][j] == 1) {
                unordered_map<int, int> adjacentGroups;
                int moveCount = 1;

                for (int k = 0; k < 4; k++) {
                    int nx = i + dx[k];
                    int ny = j + dy[k];

                    if (nx >= 0 && nx < n && ny >= 0 && ny < m) {
                        int adjGroup = group[nx][ny];
                        if (adjGroup != -1 && adjacentGroups.find(adjGroup) == adjacentGroups.end()) {
                            moveCount += groupSize[adjGroup];
                            adjacentGroups[adjGroup] = 1;
                        }
                    }
                }

                cout << moveCount % 10;
            } else {
                cout << 0;
            }
        }
        cout << '\n';
    }

    return 0;
}
