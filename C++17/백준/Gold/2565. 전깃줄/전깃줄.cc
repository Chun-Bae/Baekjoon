#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

typedef long long ll;
typedef vector<int> vec1;
typedef vector<vec1> vec2;
typedef vector<vec2> vec3;
typedef vector<pair<int, int>> pii;

void init() {
    cin.tie(NULL);
    cout.tie(NULL);
    ios::sync_with_stdio(false);
}

int main() {
    init();
    int n;
    cin >> n;

    pii lines(n);
    for (int i = 0; i < n; i++) {
        cin >> lines[i].first >> lines[i].second;
    }

    sort(lines.begin(), lines.end());

    vec1 lis;
    for (int i = 0; i < n; i++) {
        int b_pos = lines[i].second;
        auto it = lower_bound(lis.begin(), lis.end(), b_pos);

        if (it == lis.end()) {
            lis.push_back(b_pos);
        } else {
            *it = b_pos;
        }
    }

    int min_remove = n - lis.size();
    cout << min_remove << endl;
    return 0;
}