#include <iostream>

using namespace std;

int main() {
    int T;
    int a, b;
    cin >> T;
    for (int i = 0; i < T; i++) {
        cin >> a >> b;
        cout << b * 2 - a << " " << b - (b * 2 - a) << endl;
    }
    return 0;
}