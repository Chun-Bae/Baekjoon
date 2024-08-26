
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
    ll x, y;
    bool operator<=(const Point &p) const {
        if (x == p.x) return y <= p.y;
        return x <= p.x;
    }
    bool operator>(const Point &p) const { return !(*this <= p); }
};

int CCW(Point A, Point B, Point C) {
    ll result = (B.x - A.x) * (C.y - A.y) - (B.y - A.y) * (C.x - A.x);
    if (result > 0) return 1;
    if (result < 0) return -1;
    return 0;
}

bool isIntersect(Point A, Point B, Point C, Point D) {
    int ab = CCW(A, B, C) * CCW(A, B, D);
    int cd = CCW(C, D, A) * CCW(C, D, B);

    if (ab == 0 && cd == 0) {
        if (A > B) swap(A, B);
        if (C > D) swap(C, D);
        
        return A <= D && C <= B;
    }
    return ab <= 0 && cd <= 0;
}

int main() {
    init();
    Point A, B, C, D;
    cin >> A.x >> A.y >> B.x >> B.y >> C.x >> C.y >> D.x >> D.y;

    if (isIntersect(A, B, C, D)) {
        cout << 1 << '\n';
    } else {
        cout << 0 << '\n';
    }

    return 0;
}
