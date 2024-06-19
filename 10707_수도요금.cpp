#include <iostream>

using namespace std;

typedef long long ll;

void init() {
    cin.tie(NULL);
    cout.tie(NULL);
    ios::sync_with_stdio(false);
}

int main() {
    init();
    int A, B, C, D, P;
    int sum_x = 0, sum_y = 0;
    cin >> A >> B >> C >> D >> P;
    sum_x += A * P;
    sum_y += B;
    if (P > C) sum_y += (P - C) * D;
    cout << min(sum_x, sum_y);
    return 0;
}