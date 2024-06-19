#include <iostream>

using namespace std;

int main() {
    int T, n;
    cin >> T;
    for (int i = 0; i < T; i++) {
        cin >> n;
        cout << "Pairs for " << n << ": ";
        for (int j = 1; j < n; j++) {
            for (int k = j; k < n; k++) {
                if (j + k == n && j < k) {
                    if (j != 1) cout << ", ";
                    cout << j << " " << k;
                }
            }
        }
        cout << endl;
    }
    return 0;
}