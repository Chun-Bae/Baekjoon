
#include <algorithm>
#include <cmath>
#include <iomanip>
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

double f(double x, int K, vec1 coef) {
    double result = 0;
    for (int i = 0; i <= K; i++) {
        result += coef[i] * pow(x, K - i);
    }
    return result;
}

int main() {
    int K;
    cin >> K;
    vec1 coef(K + 1);
    for (int i = 0; i <= K; i++) cin >> coef[i];

    double a, b;
    int N;
    cin >> a >> b >> N;

    double real_integral = 0;
    for (int i = 0; i <= K; i++) {
        real_integral += coef[i] * (pow(b, K - i + 1) - pow(a, K - i + 1)) / (K - i + 1);
    }

    double low = 0, high = (b - a) / N, epsilon = -1;
    for (int iter = 0; iter < 100; iter++) {  
        double mid = (low + high) / 2;

        double quadrature = 0;
        double deltaX = (b - a) / N;
        for (int k = 0; k < N; k++) {
            double x = a + k * deltaX + mid;
            quadrature += f(x, K, coef) * deltaX;
        }

        if (fabs(quadrature - real_integral) <= 1e-4) {
            epsilon = mid;
            break;
        } else if (quadrature > real_integral) {
            high = mid;
        } else {
            low = mid;
        }
    }

    if (epsilon != -1) {
        cout << fixed << setprecision(4) << epsilon << endl;
    } else {
        cout << -1 << endl;
    }

    return 0;
}
