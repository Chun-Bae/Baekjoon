#include <iostream>

using namespace std;

int main() {
    int N;
    int d1, d2;
    cin >> N;
    for (int i = 1; i <= N; i++) {
        cin >> d1 >> d2;
        cout << "Case " << i << ": " << d1 + d2 << endl;
    }
    return 0;
}