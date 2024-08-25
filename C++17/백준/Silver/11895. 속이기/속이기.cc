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
    int n;
    cin >> n;
    int sum = 0;
    int XOR = 0;
    vec1 arr(n);
    // (X1 ^ X2 ^ X3) ^ (Y1 ^ Y2 ^ Y3 ^ Y4) = 0
    // then sort and (X1 ^ X2 ^ X3 ^ X4 ^ X5 ^ X6) - Y1 = max
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
        sum += arr[i];
        XOR ^= arr[i];
    }
    if (XOR == 0) {
        sort(arr.begin(), arr.end());
        cout << sum - arr[0];
    } else
        cout << 0;
    return 0;
}