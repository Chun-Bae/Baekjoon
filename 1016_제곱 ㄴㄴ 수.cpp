#include <iostream>

typedef long long ll;
using namespace std;

ll eratosthenes[1000001];  // 상대거리 배열

ll pow2(ll x) { return x * x; }

void init() {
    cin.tie(NULL);
    cout.tie(NULL);
    ios::sync_with_stdio(false);
}

int main() {
    init();
    ll min, max;
    cin >> min >> max;
    for (ll x = 2; pow2(x) <= max; x++) {
        ll multiple = min / pow2(x);
        if (min % pow2(x)) multiple++;  // min보다 바로 큰 x*x값
        while (multiple * pow2(x) <= max) {
            eratosthenes[multiple * pow2(x) - min] = 1;
            multiple++;
        }
    }

    int cnt = 0;
    for (int i = 0; i <= max - min; i++) {
        if (eratosthenes[i] == 0) cnt++;
    }
    cout << cnt;
    return 0;
}