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

    int N, M;
    ll K;
    cin >> N >> M >> K;

    ll totalRain = 0;

    for (int i = 1; i <= M; i++) {
        int t;
        ll r;
        cin >> t >> r;

        totalRain += r; 

        if (totalRain > K) {
            cout << i << " 1" << endl;
            return 0;
        }
    }

    cout << -1 << endl;  
    return 0;
}
