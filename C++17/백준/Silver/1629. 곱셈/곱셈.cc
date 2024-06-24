#include <iostream>

using namespace std;

typedef long long ll;

void init() {
    cin.tie(NULL);
    cout.tie(NULL);
    ios::sync_with_stdio(false);
}

int main() {
    init();
    ll A, B, C;
    cin >> A >> B >> C;
    // 분할 정복을 이용한 거듭제곱
    // A^13 = A^1 * A^4 * A^8
    // 13 = 1101 
    // 0인 부분의 연산을 아낄 수 있음
    ll result = 1;
    while (B > 0) {
        if (B % 2 == 1) {
            result *= A;
            result %= C;
        }
        A *= A;
        A %= C;
        B /= 2;
    }
    cout << result;
    return 0;
}