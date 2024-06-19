#include <iostream>

using namespace std;

long Combination(int n, int k) {
    if (n / 2 < k) k = n - k;
    if (k == 0) return 1;
    if (k == 1) return n;
    return Combination(n - 1, k - 1) + Combination(n - 1, k);
}
int main() {
    int n, k, result;
    cin >> n >> k;
    cout << Combination(n, k);
    return 0;
}