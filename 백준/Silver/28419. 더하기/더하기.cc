#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;
typedef long long ll;
int main() {
    int N;
    cin >> N;
    ll odds = 0;
    ll even = 0;
    for (int i = 0; i < N; i++) {
        int a;
        cin >> a;
        if (i % 2 == 0) {
            odds += a;
        } else {
            even += a;
        }
    }

    if (N == 3) {
        int diff = odds - even;
        if (diff > 0)
            cout << -1;
        else
            cout << -diff;
    } else {
        cout << abs(odds - even);
    }

    return 0;
}
