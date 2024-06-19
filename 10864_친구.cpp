#include <iostream>
#include <vector>

using namespace std;

typedef long long ll;

void init() {
    cin.tie(NULL);
    cout.tie(NULL);
    ios::sync_with_stdio(false);
}

int main() {
    init();
    int N, M;
    cin >> N >> M;

    vector<int> cnt(N, 0);
    while (M--) {
        int a, b;
        cin >> a >> b;
        cnt[a - 1]++;
        cnt[b - 1]++;
    }
    for (auto c : cnt) cout << c << '\n';
    return 0;
}