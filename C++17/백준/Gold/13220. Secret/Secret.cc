#include <algorithm>
#include <cstdio>
#include <iostream>
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

typedef long long ll;
const ll mod1 = 1000000007LL;
const ll mod2 = 1000000009LL;
const ll base1 = 911LL;
const ll base2 = 1597LL;
const ll offset = 2000000000LL;

int main() {
    init();
    int N;
    scanf("%d", &N);
    vector<ll> A(N), B(N);
    ll sumA = 0, sumB = 0;
    for (int i = 0; i < N; ++i) {
        scanf("%lld", &A[i]);
        sumA += A[i];
    }
    for (int i = 0; i < N; ++i) {
        scanf("%lld", &B[i]);
        sumB += B[i];
    }

    if (N == 1) {
        if (A[0] == B[0])
            printf("YES\n");
        else
            printf("NO\n");
        return 0;
    }

    vector<ll> DA(N), DB(N);
    for (int i = 0; i < N; ++i) {
        DA[i] = A[(i + 1) % N] - A[i];
        DB[i] = B[(i + 1) % N] - B[i];
    }

    vector<ll> DA_DA(2 * N);
    for (int i = 0; i < N; ++i) {
        DA_DA[i] = DA[i];
        DA_DA[i + N] = DA[i];
    }

    vector<ll> pow_base1(N + 1);
    vector<ll> pow_base2(N + 1);
    pow_base1[0] = 1;
    pow_base2[0] = 1;
    for (int i = 1; i <= N; ++i) {
        pow_base1[i] = (pow_base1[i - 1] * base1) % mod1;
        pow_base2[i] = (pow_base2[i - 1] * base2) % mod2;
    }

    ll hash_DB1 = 0, hash_DB2 = 0;
    for (int i = 0; i < N; ++i) {
        ll val1 = (DB[i] + offset) % mod1;
        ll val2 = (DB[i] + offset) % mod2;
        hash_DB1 = (hash_DB1 * base1 + val1) % mod1;
        hash_DB2 = (hash_DB2 * base2 + val2) % mod2;
    }

    ll hash_window1 = 0, hash_window2 = 0;
    for (int i = 0; i < N; ++i) {
        ll val1 = (DA_DA[i] + offset) % mod1;
        ll val2 = (DA_DA[i] + offset) % mod2;
        hash_window1 = (hash_window1 * base1 + val1) % mod1;
        hash_window2 = (hash_window2 * base2 + val2) % mod2;
    }

    bool found = false;
    if (hash_window1 == hash_DB1 && hash_window2 == hash_DB2) {
        found = true;
    }

    for (int i = N; i < 2 * N && !found; ++i) {
        ll val_remove1 = (DA_DA[i - N] + offset) % mod1;
        ll val_remove2 = (DA_DA[i - N] + offset) % mod2;

        ll val_add1 = (DA_DA[i] + offset) % mod1;
        ll val_add2 = (DA_DA[i] + offset) % mod2;

        hash_window1 = (hash_window1 - (val_remove1 * pow_base1[N - 1]) % mod1 + mod1) % mod1;
        hash_window2 = (hash_window2 - (val_remove2 * pow_base2[N - 1]) % mod2 + mod2) % mod2;

        hash_window1 = (hash_window1 * base1 + val_add1) % mod1;
        hash_window2 = (hash_window2 * base2 + val_add2) % mod2;

        if (hash_window1 == hash_DB1 && hash_window2 == hash_DB2) {
            found = true;
            break;
        }
    }

    if (found && sumA == sumB) {
        printf("YES\n");
    } else {
        printf("NO\n");
    }
    return 0;
}
