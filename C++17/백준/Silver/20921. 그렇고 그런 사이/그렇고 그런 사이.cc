#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

void init() {
    cin.tie(NULL);
    cout.tie(NULL);
    ios::sync_with_stdio(false);
}

int main() {
    init();
    int N, K;
    cin >> N >> K;

    vector<bool> is_used(N + 1, false);
    vector<int> result;

    for (int i = N; i >= 1; i--) {
        if (K == 0) break;

        int matched = min(K, i - 1);
        K -= matched;
        is_used[matched + 1] = true;

        result.push_back(matched + 1);
    }

    for (int i = 1; i <= N; i++) {
        if (!is_used[i]) result.push_back(i);
    }

    for (int i = 0; i < N; i++) {
        cout << result[i] << ' ';
    }
    cout << endl;

    return 0;
}