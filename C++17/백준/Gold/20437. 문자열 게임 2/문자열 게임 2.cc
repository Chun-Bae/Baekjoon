#include <algorithm>
#include <iostream>
#include <map>
#include <string>
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

void solve() {
    string W;
    int K;
    cin >> W >> K;

    map<char, vector<int>> posMap;
    int minLen = 10001;
    int maxLen = -1;

    for (int i = 0; i < W.size(); i++) {
        posMap[W[i]].push_back(i);
    }

    for (auto& entry : posMap) {
        vector<int>& positions = entry.second;

        if (positions.size() < K) continue;

        for (int i = 0; i <= positions.size() - K; i++) {
            int length = positions[i + K - 1] - positions[i] + 1;
            minLen = min(minLen, length);
            maxLen = max(maxLen, length);
        }
    }

    if (minLen == 10001 || maxLen == -1) {
        cout << "-1" << endl;
    } else {
        cout << minLen << " " << maxLen << endl;
    }
}

int main() {
    init();
    int T;
    cin >> T;

    while (T--) {
        solve();
    }

    return 0;
}