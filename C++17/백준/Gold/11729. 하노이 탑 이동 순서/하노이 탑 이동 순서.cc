#include <iostream>
using namespace std;

typedef long long ll;

void init() {
    cin.tie(NULL);
    cout.tie(NULL);
    ios::sync_with_stdio(false);
}

void hanoi(int n, int from, int to, int via) {
    if (n == 1) {
        cout << from << " " << to << "\n";
    } else {
        hanoi(n - 1, from, via, to);
        cout << from << " " << to << "\n";
        hanoi(n - 1, via, to, from);
    }
}

int main() {
    init();
    int n;
    cin >> n;
    cout << (1LL << n) - 1 << "\n";
    hanoi(n, 1, 3, 2);

    return 0;
}
