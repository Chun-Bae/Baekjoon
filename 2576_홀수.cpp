#include <iostream>

using namespace std;

int main() {
    int min = 100;
    int sum = 0;
    int isOdd;
    for (int i = 0; i < 7; i++) {
        cin >> isOdd;
        if (isOdd % 2 == 1) {
            sum += isOdd;
            if (isOdd < min) min = isOdd;
        }
    }
    if (sum)
        cout << sum << endl << min;
    else
        cout << -1;
    return 0;
}