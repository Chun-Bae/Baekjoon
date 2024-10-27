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
    int n, m;
    vec1 T(n);
    cin >> n >> m;

    if (m == 0) {  
        cout << 0;
        return 0;
    }
    for (int i = 0; i < n; i++) cin >> T[i];

    int left = 0;
    ll sum = 0;
    ll max_sum = 0;

    for (int right = 0; right < n; right++) {
        sum += T[right];
        if (right >= m - 1) {
            max_sum = max(max_sum, sum);
            sum -= T[left];
            left++;
        }
    }
    cout << max_sum;
    return 0;
}