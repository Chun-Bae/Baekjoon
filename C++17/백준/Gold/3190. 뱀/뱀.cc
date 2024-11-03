#include <algorithm>
#include <deque>
#include <iostream>
#include <map>
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

int dx[] = {0, 1, 0, -1};
int dy[] = {1, 0, -1, 0};

int main() {
    init();
    int N, K;
    cin >> N >> K;

    vec2 board(N + 1, vec1(N + 1, 0));
    for (int i = 0; i < K; ++i) {
        int x, y;
        cin >> x >> y;
        board[x][y] = 1;
    }

    int L;
    cin >> L;
    map<int, char> turns;
    for (int i = 0; i < L; ++i) {
        int X;
        char C;
        cin >> X >> C;
        turns[X] = C;
    }

    deque<pair<int, int>> snake;
    snake.push_back({1, 1});
    board[1][1] = 2;

    int time = 0, dir = 0;

    while (true) {
        time++;
        int nx = snake.front().first + dx[dir];
        int ny = snake.front().second + dy[dir];

        if (nx < 1 || nx > N || ny < 1 || ny > N || board[nx][ny] == 2) break;

        snake.push_front({nx, ny});

        if (board[nx][ny] == 1) {
            board[nx][ny] = 2;
        } else {
            board[nx][ny] = 2;
            int tx = snake.back().first;
            int ty = snake.back().second;
            board[tx][ty] = 0;
            snake.pop_back();
        }

        if (turns.count(time)) {
            if (turns[time] == 'L') {
                dir = (dir + 3) % 4;
            } else if (turns[time] == 'D') {
                dir = (dir + 1) % 4;
            }
        }
    }

    cout << time << endl;
    return 0;
}