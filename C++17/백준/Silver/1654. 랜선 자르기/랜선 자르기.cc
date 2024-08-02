#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

typedef long long ll;

void init() {
    cin.tie(NULL);
    cout.tie(NULL);
    ios::sync_with_stdio(false);
}

bool isPossible(vector<ll>& lengths, ll length, ll N) {
    ll count = 0;
    for (ll len : lengths) {
        count += len / length;
    }
    return count >= N;
}

int main() {
    init();
    
    int K;
    ll N;
    cin >> K >> N;
    
    vector<ll> lengths(K);
    ll max_length = 0;
    for (int i = 0; i < K; ++i) {
        cin >> lengths[i];
        if (lengths[i] > max_length) {
            max_length = lengths[i];
        }
    }
    
    ll left = 1, right = max_length;
    ll result = 0;
    
    while (left <= right) {
        ll mid = (left + right) / 2;
        
        if (isPossible(lengths, mid, N)) {
            result = mid;
            left = mid + 1;
        } else {
            right = mid - 1;
        }
    }
    
    cout << result << '\n';
    
    return 0;
}
