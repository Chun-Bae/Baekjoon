#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;
typedef long long ll;

int main() {
    ll N, k;
    cin >> N >> k;

    ll left = 1;
    ll right = N * N;
    ll result = 0;
    while (left <= right) {
        ll mid = (left + right) / 2;

        ll count = 0;
        for (int c = 1; c <= N; c++)
            count += min(N, mid / c);

      if (count < k) {
            left = mid + 1;
        } else {
            right = mid - 1;
        }
        result=left;
    }
    cout << result;
    return 0;
}