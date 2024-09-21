#include <algorithm>
#include <iostream>
#include <vector>
#define MOD 10007
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

int comb(int n, int k) {
    if (k > n || k < 0) return 0;
    if (k == 0 || k == n) return 1;

    vec1 C(k + 1, 0);
    C[0] = 1;

    for (int i = 1; i <= n; i++) {
        for (int j = min(i, k); j > 0; j--) {
            C[j] = (C[j] + C[j - 1]) % MOD;
        }
    }

    return C[k];
}

int main() {
    init();
    int N;
    cin >> N;
    if (N < 4) {
        cout << 0 << '\n';
        return 0;
    }

    int result = 0;
    // i: 포카드의 종류의 개수
    for (int i = 1; i <= 13; i++) {
        if (N - 4 * i < 0) break;
        // 52-4*i: 52장의 카드 중 4*i장을 제외한 나머지 카드
        // comb(52-4*i, N-4*i): 포카드를 뽑고 남은 카드 중에서
        // 포카드를 제외한 나머지 카드를 뽑는 경우의 수
        int includ = comb(13, i) * comb(52 - 4 * i, N - 4 * i) % MOD;
        if (i % 2 == 1)
            result = (result + includ) % MOD;
        else
            result = (result - includ + MOD) % MOD;
    }
    cout << result << '\n';

    return 0;
}