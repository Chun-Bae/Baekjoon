#include <iostream>

using namespace std;

int main() {
    double before = 0, n = 0;

    cin >> before;
    for (;;) {
        cin >> n;
        if (n == 999) break;
        cout << fixed;
        cout.precision(2);
        cout << n - before << endl;
        before = n;
    }

    return 0;
}