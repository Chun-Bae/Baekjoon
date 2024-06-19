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
    while (1) {
        int a, b, c, d;
        cin >> a >> b >> c >> d;
        if (!(a || b || c || d)) break;
        cout << c - b << " " << d - a << '\n';
    }
    return 0;
}