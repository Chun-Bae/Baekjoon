#include <algorithm>
#include <cmath>
#include <iostream>
#include <vector>
#define MAXN 50000
using namespace std;

typedef long long ll;
typedef vector<int> vec1;
typedef vector<vec1> vec2;
typedef vector<vec2> vec3;
vec1 mu(MAXN + 1);
vec1 prime(MAXN + 1, 1);

ll count_square_free(ll N) {
    ll res = 0;
    ll max_k = sqrt(N);
    for (ll k = 1; k <= max_k; ++k) {
        if (mu[k] == 0) continue;
        res += mu[k] * (N / (k * k));
    }
    return res;
}

void init() {
    cin.tie(NULL);
    cout.tie(NULL);
    ios::sync_with_stdio(false);
}

int main() {
    init();
    ll K;
    cin >> K;

    for (int i = 0; i <= MAXN; ++i) mu[i] = 1;
    for (ll i = 2; i <= MAXN; ++i) {
        if (prime[i]) {
            for (int j = i; j <= MAXN; j += i) {
                prime[j] = 0;
                mu[j] *= -1;
            }
            for (ll j = i * i; j <= MAXN; j += i * i) {
                mu[j] = 0;
            }
        }
    }

    ll left = 1, right = 2e9, ans = 0;
    while (left <= right) {
        ll mid = (left + right) / 2;
        ll cnt = count_square_free(mid);
        if (cnt >= K) {
            ans = mid;
            right = mid - 1;
        } else {
            left = mid + 1;
        }
    }

    cout << ans << endl;

    return 0;
}