#include <cmath>
#include <iostream>

using namespace std;

double is_c(double x, double y, double m) {
    double hx = sqrt(x * x - m * m);
    double hy = sqrt(y * y - m * m);
    return (hx * hy) / (hx + hy);
}

int main() {
    double x, y, c;
    cin >> x >> y >> c;
    double l = 0;
    double h = min(x, y);
    double r = 0;

    // 이분탐색
    while (h - l > 0.000001) {
        double m = (l + h) / 2.0;
        if (is_c(x, y, m) >= c) {
            r = m;
            l = m;
        } else
            h = m;
    }
    cout << fixed;
    cout.precision(3);
    cout << r;
    return 0;
}