#include <iostream>

using namespace std;

int main() {
    int N;
    cin >> N;
    for (int i = 1; i <= 2 * N - 1; i++) {
        if (i <= N) {
            for (int j = 1; j < i + 1; j++) {
                cout << "*";
            }
            for (int j = 0; j < (N - i); j++) {
                cout << " ";
            }
            for (int j = 0; j < (N - i); j++) {
                cout << " ";
            }

            for (int j = 1; j < i + 1; j++) {
                cout << "*";
            }
        } else {
            int m = (2 * N - 1) - i;
            for (int j = 0; j < m + 1; j++) {
                cout << "*";
            }
            for (int j = 1; j < (N - m); j++) {
                cout << " ";
            }
            for (int j = 1; j < (N - m); j++) {
                cout << " ";
            }

            for (int j = 0; j < m + 1; j++) {
                cout << "*";
            }
        }

        cout << endl;
    }
    return 0;
}