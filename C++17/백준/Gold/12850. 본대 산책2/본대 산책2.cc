#include <iostream>
#include <vector>
using namespace std;

typedef long long ll;
const int MOD = 1000000007;
const int SIZE = 8;

// 행렬 곱
vector<vector<ll>> mat_mult(const vector<vector<ll>>& A, const vector<vector<ll>>& B) {
    vector<vector<ll>> result(SIZE, vector<ll>(SIZE, 0));
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            for (int k = 0; k < SIZE; k++) {
                result[i][j] = (result[i][j] + A[i][k] * B[k][j]) % MOD;
            }
        }
    }
    return result;
}

vector<vector<ll>> mat_pow(vector<vector<ll>> base, ll exp) {
    vector<vector<ll>> result(SIZE, vector<ll>(SIZE, 0));
    // I
    for (int i = 0; i < SIZE; i++) {
        result[i][i] = 1;
    }
    while (exp > 0) {
        if (exp % 2 == 1) {
            result = mat_mult(result, base);
        }
        base = mat_mult(base, base);
        exp /= 2;
    }
    return result;
}

void init() {
    cin.tie(NULL);
    cout.tie(NULL);
    ios::sync_with_stdio(false);
}

int main() {
    init();
    ll D;
    cin >> D;

    vector<vector<ll>> A = {
    {0, 1, 1, 0, 0, 0, 0, 0},
    {1, 0, 0, 1, 0, 0, 0, 0},
    {1, 0, 0, 1, 1, 0, 0, 0},
    {0, 1, 1, 0, 1, 1, 0, 0},
    {0, 0, 1, 1, 0, 1, 1, 0},
    {0, 0, 0, 1, 1, 0, 1, 1},
    {0, 0, 0, 0, 1, 1, 0, 1}, 
    {0, 0, 0, 0, 0, 1, 1, 0}};

    vector<vector<ll>> result = mat_pow(A, D);
    cout << result[7][7] << '\n';

    return 0;
}
