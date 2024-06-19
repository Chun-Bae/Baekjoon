#include <iostream>

using namespace std;

int main() {
    int max = 0;
    int n, sum;
    for (int i = 0; i < 2; i++) {
        sum = 0;
        for (int j = 0; j < 4; j++) {
            cin >> n;
            sum += n;
        }
        if (sum > max) max = sum;
    }
    cout << max;
    return 0;
}