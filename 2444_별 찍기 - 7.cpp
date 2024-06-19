#include <iostream>

using namespace std;

int main() {
    int N;
    cin >> N;
    for (int i = 1; i <= 2 * N - 1; i++) {
        if (i <= N) {
            for (int j = i; j < N; j++) {
                cout << " ";
            }
            for (int j = 0; j < i * 2 - 1; j++) {
                cout << "*";
            }
        } else {
            for (int j = i - N; j > 0; j--) {
                cout << " ";
            }
            for (int j = ((N * 2 - 1) - i) * 2 + 1; j > 0; j--) {
                cout << "*";
            }
        }
        cout << endl;
    }
}