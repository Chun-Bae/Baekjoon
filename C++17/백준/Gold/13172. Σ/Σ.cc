#include <iostream>
#define MOD 1000000007
using namespace std;

typedef long long ll;

void init() {
    cin.tie(NULL);
    cout.tie(NULL);
    ios::sync_with_stdio(false);
}

ll modInverse(ll b, ll m) {
    // 페르마 소
    ll result = 1;
    ll power = m - 2;
    // 분할정복
    while (power > 0) {
        if (power % 2 == 1) {
            result = (result * b) % m;
        }
        b = (b * b) % m;
        power /= 2;
    }
    return result;
}

int main() {
    init();
    int M;
    cin >> M;
    ll total = 0;

    for (int i = 0; i < M; i++) {
        ll N, S;
        cin >> N >> S;

        ll b_inverse = modInverse(N, MOD);
        ll E = (S * b_inverse) % MOD;
        total = (total + E) % MOD;
    }

    cout << total << endl;
    return 0;
}
