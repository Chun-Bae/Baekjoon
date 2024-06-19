#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

int main() {
    // C++ IO 속도 향상
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N, x, y;
    cin >> N;
    vector<pair<int, int>> XY(N);

    for (int i = 0; i < N; i++) {
        cin >> x >> y;
        XY[i] = make_pair(x, y);
    }

    sort(XY.begin(), XY.end(), [](const pair<int, int>& a, const pair<int, int>& b) { return a.first == b.first ? a.second < b.second : a.first < b.first; });

    for (const auto& p : XY) {
        cout << p.first << ' ' << p.second << '\n'; 
    }

    return 0;
}