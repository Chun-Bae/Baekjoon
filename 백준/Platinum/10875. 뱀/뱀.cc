/// https://www.acmicpc.net/problem/10875

#include <algorithm>
#include <iostream>
#include <queue>
#include <vector>

using namespace std;
typedef long long ll;

const ll INF = 2e18;
const ll dx[4] = {1, 0, -1, 0};
const ll dy[4] = {0, -1, 0, 1};

enum class Directions {
    EAST,
    SOUTH,
    WEST,
    NORTH
};

Directions ChangeL(Directions d) {
    return static_cast<Directions>((static_cast<int>(d) + 3) % 4);
}

Directions ChangeR(Directions d) {
    return static_cast<Directions>((static_cast<int>(d) + 1) % 4);
}

struct Point {
    ll x, y;
};

struct Line {
    Point p1, p2;
};

ll get_collision_dist(Line l1, Line l2) {
    ll minX1 = min(l1.p1.x, l1.p2.x);
    ll minX2 = min(l2.p1.x, l2.p2.x);
    ll maxX1 = max(l1.p1.x, l1.p2.x);
    ll maxX2 = max(l2.p1.x, l2.p2.x);

    ll minY1 = min(l1.p1.y, l1.p2.y);
    ll minY2 = min(l2.p1.y, l2.p2.y);
    ll maxY1 = max(l1.p1.y, l1.p2.y);
    ll maxY2 = max(l2.p1.y, l2.p2.y);

    // INF 는 안 부딪침
    if (maxX1 < minX2 ||
        maxX2 < minX1 ||
        maxY1 < minY2 ||
        maxY2 < minY1) return INF;

    // Line 1을 움직이는 주체
    // Line 2는 장애물 취급

    // Line1이 수평
    if (l1.p1.y == l1.p2.y) {
        // Line2가 수평
        if (l2.p1.y == l2.p2.y) {
            // Line1이 오른쪽 이동
            if (l1.p1.x < l1.p2.x) {
                // Line2의 X 최소값이 Line1의 시작점보다 크면,
                // l1 -→ l2 --
                return (minX2 > l1.p1.x) ? minX2 - l1.p1.x : INF;
            }
            // Line1이 왼쪽 이동
            else {
                // Line2의 X 최댓값이 Line1의 시작점보다 작으면,
                // l2-- l1 ←-
                return (maxX2 < l1.p1.x) ? l1.p1.x - maxX2 : INF;
            }
        }
        // Line2가 수직 (교차)
        else {
            // 왼쪽 오른쪽 방향 상관없이,
            //  l1 --→ ←-- l1
            //  l2    |
            // 수평 길이가 거리
            return abs(l2.p1.x - l1.p1.x);
        }

    }
    // Line1이 수직
    else {
        // Line2가 수직
        if (l2.p1.x == l2.p2.x) {
            // Line1이 위로 이동
            if (l1.p1.y < l1.p2.y) {
                // Line2의 Y 최소값이 Line1의 시작점보다 크면,
                // | l2
                // ↑ l1
                return (minY2 > l1.p1.y) ? minY2 - l1.p1.y : INF;
            }
            // Line1이 아래로 이동
            else {
                // Line2의 Y 최댓값이 Line1의 시작점보다 작으면,
                // ↓ l1
                // | l2
                return (maxY2 < l1.p1.y) ? l1.p1.y - maxY2 : INF;
            }
        }
        // Line2가 수평 (교차)
        else {
            //  l1 |
            //     ↓
            //  l2 --
            //     ↑
            //  l1 |
            // 수직 길이가 거리
            return abs(l2.p1.y - l1.p1.y);
        }
    }
}

ll L;
int N;
ll min_dist;
ll total_time;
vector<Line> body;
queue<pair<int, char>> q;
Directions dir;

int main() {
    cin >> L;
    cin >> N;
    dir = Directions::EAST;
    min_dist = INF;
    for (int i = 0; i < N; i++) {
        int t;
        char d;
        cin >> t >> d;
        q.push({t, d});
    }
    q.push({(int)2e9 + 7, 'X'});

    ll cx = 0;
    ll cy = 0;
    total_time = 0;
    while (!q.empty()) {
        auto [time, cmd] = q.front();
        q.pop();

        ll dist_to_wall;
        int d_idx = static_cast<int>(dir);

        // 벽까지의 거리
        if (dir == Directions::EAST)
            dist_to_wall = L - cx + 1;
        if (dir == Directions::SOUTH)
            dist_to_wall = cy - (-L) + 1;
        if (dir == Directions::WEST)
            dist_to_wall = cx - (-L) + 1;
        if (dir == Directions::NORTH)
            dist_to_wall = L - cy + 1;

        // 직진하면 얼마나 갈 수 있는 지
        ll move_limit = min((ll)time, dist_to_wall);

        ll nx = cx + dx[d_idx] * move_limit;
        ll ny = cy + dy[d_idx] * move_limit;
        Line new_line = {{cx, cy}, {nx, ny}};

        // 아무것도 안부딪치면 벽까지의 거리가 최단 거리
        // 이후 다른 line 들과 비교하면서 점점 줄어듬.
        ll crash_dist = dist_to_wall;
        
        // 꺾을 때 한 점은 공유하기 때문에,
        // 바로 이전 거와는 검사를 안함
        for (int i = 0; i < (int)body.size() - 1; i++) {
            ll dist = get_collision_dist(new_line, body[i]);
            if (dist != INF) {
                crash_dist = min(crash_dist, dist);
            }
        }

        // 더 갈 수 있는 거리보다 부딪친 거리가 짧으므로 사망
        if (crash_dist <= time) {
            cout << total_time + crash_dist;
            return 0;
        }
        // 생존했으니 전체 거리 갱신
        total_time += time;

        body.push_back(new_line);

        cx += dx[d_idx] * time;
        cy += dy[d_idx] * time;

        if (cmd == 'L')
            dir = ChangeL(dir);
        if (cmd == 'R')
            dir = ChangeR(dir);
    }

    return 0;
}