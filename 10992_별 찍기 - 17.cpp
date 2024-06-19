#include <iostream>

using namespace std;

int main() {
    int N;
    cin >> N;
    for (int i = 1; i <= N; i++) {
        if (i == N)
            for (int j = 0; j < i * 2 - 1; j++) cout << "*";
        else {
            for (int j = N - i; j >= 1; j--) cout << " ";
            cout << "*";
            for (int j = 1; j <= (i - 1) * 2 - 1; j++) cout << " ";
            if (i != 1) cout << "*";
        }
        cout << endl;
    }
    return 0;
}