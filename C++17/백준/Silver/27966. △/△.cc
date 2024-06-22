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
    ll N;
    cin >> N;
    cout << N - 1 + (N - 1) * (N - 2) << '\n';
    for (ll i = 2; i <= N; i++) {
        cout << "1 " << i << '\n';
    }
    return 0;
}