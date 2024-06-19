#include <iostream>

using namespace std;

int main() {
    int N, num, cnt;
    cin >> N;
    for (int i = 0; i < N; i++) {
        cin >> num;
        cnt = 0;
        while (num) {
            if (num % 2) cout << cnt << " ";
            num /= 2;
            cnt++;
        }
    }
    return 0;
}