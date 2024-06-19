#include <iostream>

using namespace std;

int main() {
    int T;
    double n, sum;
    cin >> T;
    for (int i = 0; i < T; i++) {
        sum = 0;
        for (int j = 0; j < 5; j++) {
            cin >> n;
            switch (j) {
                case 0:
                    sum += 350.34 * n;
                    break;
                case 1:
                    sum += 230.90 * n;
                    break;
                case 2:
                    sum += 190.55 * n;
                    break;
                case 3:
                    sum += 125.30 * n;
                    break;
                case 4:
                    sum += 180.90 * n;
                    break;
                default:
                    break;
            }
        }
        cout << fixed;
        cout.precision(2);
        cout << "$" << sum << '\n';
    }

    return 0;
}