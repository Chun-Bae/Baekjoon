#include <iostream>

using namespace std;

int main() {
    int N;
    cin >> N;
    for (int i = 0; i < 2 * N - 1; i++) {
        if (i < N) {
            for (int j = i; j > 0; j--) {
                cout << " ";
            }
            for (int j = 2 * (N - i) - 1; j > 0; j--) {
                cout << "*";
            }
        } else {
            for (int j = i - N; j < N - 2; j++) {
                cout << " ";
            }
            for (int j = 2 * (i - N + 1); j >= 0; j--) {
                cout << "*";
            }
        }
        cout << endl;
    }
    return 0;
}