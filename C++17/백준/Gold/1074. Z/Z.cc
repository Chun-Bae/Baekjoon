#include <iostream>

using namespace std;

void init() {
    cin.tie(NULL);
    cout.tie(NULL);
    ios::sync_with_stdio(false);
}

int Z(int n, int r, int c) {
    if (n == 0) {
        return 0;
    }

    int half = 1 << (n - 1);
    int quadrant_size = half * half;

    if (r < half && c < half) {
        // top-left
        return Z(n - 1, r, c);
    } else if (r < half && c >= half) {
        // top-right
        return quadrant_size + Z(n - 1, r, c - half);
    } else if (r >= half && c < half) {
        // bottom-left
        return 2 * quadrant_size + Z(n - 1, r - half, c);
    } else {
        // bottom-right
        return 3 * quadrant_size + Z(n - 1, r - half, c - half);
    }
}

int main() {
    init();
    int N, r, c;
    cin >> N >> r >> c;
    cout << Z(N, r, c) << endl;
    return 0;
}
