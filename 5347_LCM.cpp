#include <iostream>

using namespace std;

long long gcd(int a, int b) {
    if (a % b == 0)
        return b;
    else
        return gcd(b, a % b);
}

long long lcm(long long a, long long b) { return a * b / gcd(a, b); } 

int main() {
    int T;
    int a, b;
    cin >> T;
    while (T--) {
        cin >> a >> b;
        cout << lcm(a, b) << endl;
    }
    return 0;
}