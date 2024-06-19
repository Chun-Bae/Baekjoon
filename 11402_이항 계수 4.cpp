#include <cstring>
#include <iostream>
#include <vector>

using namespace std;
using Long = long long;

const int MAX = 2001;
Long arrC[MAX][MAX];
int m;

vector<int> convertToDigits(Long value, int mod) {
    vector<int> digits;
    while (value > 0) {
        digits.push_back(value % mod);
        value /= mod;
    }
    return digits;
}

Long calculateCombination(int n, int k) {
    if (n < k) return 0;
    if (n / 2 < k) k = n - k;
    Long &result = arrC[n][k];
    if (result != -1) return result;
    if (k == 0) return result = 1;
    if (k == 1) return result = n;
    return result = (calculateCombination(n - 1, k - 1) + calculateCombination(n - 1, k)) % m;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    memset(arrC, -1, sizeof(arrC));

    Long n, k;
    cin >> n >> k >> m;

    auto nDigits = convertToDigits(n, m);
    auto kDigits = convertToDigits(k, m);

    Long result = 1;
    for (size_t i = 0; i < min(nDigits.size(), kDigits.size()); i++) {
        result = (result * calculateCombination(nDigits[i], kDigits[i])) % m;
    }

    cout << result << "\n";
    return 0;
}
