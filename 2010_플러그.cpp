#include <iostream>

using namespace std;

int main() {
    int N, n;
    int sum = 0;
    cin >> N;
    for (int i = 0; i < N; i++) {
        cin >> n;
        sum += n;
    }
    sum -= (N - 1);
    cout << sum << endl;
    return 0;
}