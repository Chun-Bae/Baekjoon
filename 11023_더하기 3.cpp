#include <iostream>

using namespace std;

int main() {
    int n, sum = 0;
    for (int i = 0; i < 100; i++) {
        cin >> n;
        if (cin.eof()) break;
        sum += n;
    }
    cout << sum;
    return 0;
}