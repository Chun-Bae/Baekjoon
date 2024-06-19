#include <iostream>

using namespace std;

int main() {
    int T;
    cin >> T;
    while (T--) {
        int N, K;
        int n, cnt = 0;
        cin >> N >> K;
        while (N--) {
            cin >> n;
            cnt += n / K;
        }
        cout << cnt << '\n';
    }
    return 0;
}