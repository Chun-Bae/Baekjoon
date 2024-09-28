#include <algorithm>
#include <iostream>
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
struct Point {
    int x, y;
    bool operator<(const Point& p) const { return x == p.x ? y < p.y : x < p.x; }
};
ll ccw(const Point& p1, const Point& p2, const Point& p3) { return (ll)(p2.x - p1.x) * (p3.y - p1.y) - (ll)(p2.y - p1.y) * (p3.x - p1.x); }

int main() {
    init();
    vector<Point> points;
    for (int i = 0; i < 3; i++) {
        Point p;
        cin >> p.x >> p.y;
        points.push_back(p);
    }
    ll res = ccw(points[0], points[1], points[2]);
    if (res > 0) cout << 1;
    else if (res < 0) cout << -1;
    else cout << 0;
    

    return 0;
}