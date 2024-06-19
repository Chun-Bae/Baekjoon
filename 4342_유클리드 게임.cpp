#include <iostream>

using namespace std;

void init() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
}

bool gcd(long long p, long long q) {
    long long a = max(p, q);
    long long b = min(p, q);
    
    if (a % b == 0) return true;
    if (a - b < b) { //  수를 최대한 많이 안 주는 사람
        return !gcd(a % b, b);
    }
    return true;
}

int main() {
    init();
    long long a, b;

    while (1) {
        cin >> a >> b;

        if (a == 0 && b == 0) break;

        if (gcd(a, b))
            cout << "A wins" << '\n';
        else
            cout << "B wins" << '\n';
    }
    return 0;
}
