#include <algorithm>
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

int main() {
    init();
    int N, M;
    cin >> N >> M;
    vec1 A(N);
    for (int i = 0; i < N; i++) cin >> A[i];

    vector<ll> prefixCount(M, 0);
    ll sum = 0;
    ll result = 0;

    prefixCount[0] = 1;

    for (int i = 0; i < N; i++) {
        sum += A[i];
        int remainder = sum % M;

        if (remainder < 0) remainder += M;

        result += prefixCount[remainder];
        prefixCount[remainder]++;
    }

    cout << result << endl;
    return 0;
}