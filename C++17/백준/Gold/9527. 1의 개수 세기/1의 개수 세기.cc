#include <iostream>

using namespace std;

typedef long long ll;

void init(){
    cin.tie(NULL);
    cout.tie(NULL);
    ios::sync_with_stdio(false);
}

ll count_ones(ll n) {
    ll count = 0;
    for (ll i = 1; i <= n; i <<= 1) {
        // i = 1, 2, 4, 8, 16, ...

        // pair: n번째 비트에서 주기만큼 1이 등장하는 횟수
        ll pairs = (n + 1) / (i << 1);
        // remainder: 주기 이후에 남은 n번째 비트 수
        ll remainder = (n + 1) % (i << 1);
        // i만큼 빼는 이유: 절반 이상이어야 i인 n번째 비트에서 1이 첫 등장하기 때문
        count += pairs * i + max(0LL, remainder - i);
    }
    return count;
}

int main(){
    init();
    ll A, B;
    cin >> A >> B;
    
    ll result = count_ones(B) - count_ones(A - 1);
    cout << result << "\n";
    
    return 0;
}
