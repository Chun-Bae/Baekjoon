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
    int N;
    cin >> N;

    vector<ll> A(N);
    for (int i = 0; i < N; ++i) cin >> A[i];

    sort(A.begin(), A.end());
    int goodCount = 0;

    for (int i = 0; i < N; ++i) {
        int left = 0, right = N - 1;

        while (left < right) {
            if (left == i) {
                ++left;
                continue;
            }
            if (right == i) {
                --right;
                continue;
            }

            ll sum = A[left] + A[right];

            if (sum == A[i]) {
                ++goodCount;
                break;
            } else if (sum < A[i]) {
                ++left;
            } else {
                --right;
            }
        }
    }

    cout << goodCount << endl;
    return 0;
}