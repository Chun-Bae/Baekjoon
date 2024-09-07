#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

typedef long long ll;
typedef vector<ll> vec1;
typedef vector<vec1> vec2;
typedef vector<vec2> vec3;
ll N, M;
vec1 times;

void init() {
    cin.tie(NULL);
    cout.tie(NULL);
    ios::sync_with_stdio(false);
}

bool canProcessAllInTime(ll mid) {
    ll total_people = 0;
    for (int i = 0; i < N; i++) {
        total_people += (mid / times[i]);
        // 넘으면 더 괜찮은 수가 존재
        if (total_people >= M) return true;
    }
    return total_people >= M;
}
int main() {
    init();
    cin >> N >> M;
    times.resize(N);

    ll max_time = 0;
    for (int i = 0; i < N; i++) {
        cin >> times[i];
        max_time = max(max_time, times[i]);
    }

    ll left = 1, right = max_time * M;
    ll result = right;

    while (left <= right) {
        ll mid = (left + right) / 2;
        if (canProcessAllInTime(mid)) {
            result = mid;
            right = mid - 1;
        } else {
            left = mid + 1;
        }
    }

    cout << result << '\n';
    return 0;
}