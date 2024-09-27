#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

typedef long long ll;
typedef vector<int> vec1;
typedef vector<vec1> vec2;
typedef vector<vec2> vec3;

struct Point {
    int x, y;
    bool operator<(const Point& p) const { return x == p.x ? y < p.y : x < p.x; }
};

ll ccw(const Point& p1, const Point& p2, const Point& p3) { return (ll)(p2.x - p1.x) * (p3.y - p1.y) - (ll)(p2.y - p1.y) * (p3.x - p1.x); }

void init() {
    cin.tie(NULL);
    cout.tie(NULL);
    ios::sync_with_stdio(false);
}
vector<Point> convexHull(vector<Point>& points) {
    int n = points.size();
    if (n < 3) return points;

    sort(points.begin(), points.end());

    vector<Point> hull;

    for (int i = 0; i < n; i++) {
        while (hull.size() >= 2 && ccw(hull[hull.size() - 2], hull[hull.size() - 1], points[i]) <= 0) {
            hull.pop_back();
        }
        hull.push_back(points[i]);
    }

    int lowerSize = hull.size();
    for (int i = n - 2; i >= 0; i--) {
        while (hull.size() > lowerSize && ccw(hull[hull.size() - 2], hull[hull.size() - 1], points[i]) <= 0) {
            hull.pop_back();
        }
        hull.push_back(points[i]);
    }

    hull.pop_back(); 

    return hull;
}
int main() {
    init();
    int N;
    cin >> N;
    vector<Point> points(N);

    for (int i = 0; i < N; i++) {
        cin >> points[i].x >> points[i].y;
    }

    vector<Point> result = convexHull(points);

    cout << result.size() << '\n';

    return 0;
}