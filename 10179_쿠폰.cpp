#include <iostream>
#include <cmath>

using namespace std;

int main() {
    int T;
    double n;
    cin >> T;
    for (int i = 0; i < T; i++) {
        cin >> n;
        n = round(n * 100) / 100.0;
        cout << fixed;
        cout.precision(2);
        cout << "$" << n * 0.8 << endl;
    }
    return 0;
}