#include <algorithm>
#include <cstring>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

typedef long long ll;
typedef vector<int> vec1;
typedef vector<vec1> vec2;
typedef vector<vec2> vec3;

void init() {
    cin.tie(NULL);
    cout.tie(NULL);
    ios::sync_with_stdio(false);
}

int N, K;
vector<string> numbers;
ll dp[1 << 15][100];
ll fact[16];
int mod[51];
int powMod[51];

ll gcd(ll a, ll b) {
    if (b == 0) return a;
    return gcd(b, a % b);
}

ll bitmasking(int mask, int rem) {
    // 1<<3 - 1 = 111
    // 나머지가 0이면 1, 아니면 0
    if (mask == (1 << N) - 1) return rem == 0 ? 1 : 0;

    // 재귀 때문에 중복 값은 리턴
    if (dp[mask][rem] != -1) return dp[mask][rem];

    dp[mask][rem] = 0;

    for (int i = 0; i < N; ++i) {
        // i번째 숫자를 사용하지 않은 경우
        if (!(mask & (1 << i))) {
            // mod[12345] = ((mod[123] * powMod[2]) + mod[45]) % K
            int newRem = (rem * powMod[numbers[i].size()] + mod[i]) % K;
            // 12345라는 정보는 mask로 표현되어 알 수 있음
            dp[mask][rem] += bitmasking(mask | (1 << i), newRem);
        }
    }
    // 000

    // 001
    // .. 011
    // .. .. 111
    // .. 101
    // 010
    // .. 110
    // 100

    return dp[mask][rem];
    // 참고로 rem도 dp로 표현하는 이유는 순서에 따라 나머지가 달라지기 때문
    // 12345, 45123은 같은 마스킹이지만 나머지가 다름
}

int main() {
    init();
    cin >> N;
    numbers.resize(N);
    for (int i = 0; i < N; i++) cin >> numbers[i];

    cin >> K;
    memset(dp, -1, sizeof(dp));

    for (int i = 0; i < N; i++) {
        mod[i] = 0;
        for (char c : numbers[i]) {
            mod[i] = (mod[i] * 10 + c - '0') % K;
        }
    }

    // mod[12345] = ((mod[123] * powMod[2]) + mod[45]) % K
    // powMod[2] = 10^2 % k
    powMod[0] = 1;
    for (int i = 1; i <= 50; i++) {
        powMod[i] = (powMod[i - 1] * 10) % K;
    }

    // 모든 순열의 개수
    fact[0] = 1;
    for (int i = 1; i <= N; ++i) {
        fact[i] = fact[i - 1] * i;
    }

    ll total = fact[N];
    ll valid = bitmasking(0, 0);

    if (valid == 0) {
        cout << "0/1\n";
    } else if (valid == total) {
        cout << "1/1\n";
    } else {
        ll g = gcd(valid, total);
        cout << valid / g << "/" << total / g << "\n";
    }

    return 0;
}