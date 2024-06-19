#include <iostream>

using namespace std;

int main() {
    int N, _case, n, sum;

    cin >> N;
    for (int i = 0; i < N; i++) {
        cin >> _case;
        sum = 0;
        for (int j = 0; j < _case; j++) {
            cin >> n;
            sum += n;
        }
        cout << sum << endl;
    }
    return 0;
}