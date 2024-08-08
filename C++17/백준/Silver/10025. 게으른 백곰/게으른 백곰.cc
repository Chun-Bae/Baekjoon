#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;
typedef long long ll;

void init() {
    cin.tie(NULL);
    cout.tie(NULL);
    ios::sync_with_stdio(false);
}

int main() {
    init();
    int N, K;
    cin >> N >> K;

    vector<ll> ice(1000001, 0);

    for (int i = 0; i < N; i++) {
        int g, x;
        cin >> g >> x;
        ice[x] += g;
    }

    K = min(K, 1000000);

    ll current_sum = 0;
    ll max_sum = 0;

    for (int i = 0; i <= 2 * K && i <= 1000000; i++) {
        current_sum += ice[i];
    }

    max_sum = current_sum;

    for (int i = 1; i <= 1000000; i++) {
        if (i + 2 * K <= 1000000) {
            current_sum = current_sum - ice[i - 1] + ice[i + 2 * K];
            max_sum = max(max_sum, current_sum);
        } else {
            break;
        }
    }

    cout << max_sum << "\n";

    return 0;
}
