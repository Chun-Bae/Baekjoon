#include <iostream>

using namespace std;

int main() {
    int T, a, b;
    cin >> T;
    for (int i = 0; i < T; i++) {
        cin >> a >> b;
        cout << ((a % b) ? (a / b + 1) : (a / b));
        cout << endl;
    }
    return 0;
}