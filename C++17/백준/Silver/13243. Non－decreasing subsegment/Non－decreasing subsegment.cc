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
    vec1 arr(n);
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    
    int max_cnt = 1;
    int max_sum = arr[0];
    int cnt = 1;
    int sum = arr[0];

    for (int i = 1; i < n; i++) {
        if (arr[i] >= arr[i - 1]) {
            cnt++;
            sum += arr[i];
        } else {
            if (cnt > max_cnt) {
                max_cnt = cnt;
                max_sum = sum;
            }
            cnt = 1;
            sum = arr[i];
        }
    }

    if (cnt > max_cnt) {
        max_cnt = cnt;
        max_sum = sum;
    }

    cout << max_cnt << " " << max_sum << "\n";

    return 0;
}
