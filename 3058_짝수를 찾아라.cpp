#include <iostream>

using namespace std;

int main() {
    int T, n, min, sum;
    cin >> T;
    for (int i = 0; i < T; i++) {
        sum = 0;
        min = 100;
        for (int j = 0; j < 7; j++) {
            cin >> n;
            if (!(n % 2)) {
                if (min > n) min = n;
                sum += n;
            }
        }
        cout << sum << " " << min << endl;
    }
    return 0;
}