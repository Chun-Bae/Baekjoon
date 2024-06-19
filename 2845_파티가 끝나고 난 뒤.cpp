#include <iostream>

using namespace std;

int main() {
    int L, P, n;
    cin >> L >> P;
    for (int i = 0; i < 5; i++) {
        cin >> n;
        cout << n - L * P << " ";
    }
    return 0;
}