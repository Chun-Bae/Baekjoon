#include <iostream>
#define MOD 1000000007
using namespace std;

typedef long long ll;

void init() {
    cin.tie(NULL);
    cout.tie(NULL);
    ios::sync_with_stdio(false);
}

struct Matrix {
    ll mat[2][2];
};

Matrix multiply(Matrix a, Matrix b) {
    Matrix result;
    result.mat[0][0] = (a.mat[0][0] * b.mat[0][0] + a.mat[0][1] * b.mat[1][0]) % MOD;
    result.mat[0][1] = (a.mat[0][0] * b.mat[0][1] + a.mat[0][1] * b.mat[1][1]) % MOD;
    result.mat[1][0] = (a.mat[1][0] * b.mat[0][0] + a.mat[1][1] * b.mat[1][0]) % MOD;
    result.mat[1][1] = (a.mat[1][0] * b.mat[0][1] + a.mat[1][1] * b.mat[1][1]) % MOD;
    return result;
}

Matrix power(Matrix base, ll exp) {
    Matrix result = {{{1, 0}, {0, 1}}};
    while (exp > 0) {
        if (exp % 2 == 1) {
            result = multiply(result, base);
        }
        base = multiply(base, base);
        exp /= 2;
    }
    return result;
}

ll getFibonacci(ll n) {
    if (n == 0) return 0;
    if (n == 1) return 1;
    Matrix F = {{{1, 1}, {1, 0}}};
    Matrix result = power(F, n - 1);
    return result.mat[0][0];
}

int main() {
    init();
    ll n;
    cin >> n;

    ll result = getFibonacci(n);
    cout << result << endl;

    return 0;
}
