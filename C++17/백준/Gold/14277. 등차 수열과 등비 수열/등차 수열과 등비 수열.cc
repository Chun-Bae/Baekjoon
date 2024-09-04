#include <algorithm>
#include <cmath>
#include <iostream>
#include <set>
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

int main() {
    init();
    ll a, b, c, d, u;
    cin >> a >> b >> c >> d >> u;
    ll count = 0;

    if (a <= u) {
        count = (u - a) / b + 1;
    }

    if (d == 1 && c <= u) {
        if (a == c || (a < c && (c - a) % b == 0)) {
        } else {
            count++;
        }
    } else {
        while (c <= u) {
            if (c < a || (c - a) % b != 0) {
                count++;
            }
            if (c > u / d) break; 
            c *= d;
        }
    }

    cout << count << "\n";
    return 0;
}