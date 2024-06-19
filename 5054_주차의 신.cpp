#include <iostream>

using namespace std;

int main() {
    int t, n, xi, max, min, location;
    cin >> t;
    for (int i = 0; i < t; i++) {
        cin >> n;
        max = 0, min = 99;
        for (int j = 0; j < n; j++) {
            cin >> location;
            if (location > max) max = location;
            if (location < min) min = location;
        }
        cout << (max - min) * 2 << endl;
    }
    return 0;
}