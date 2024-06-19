#include <iostream>

using namespace std;

typedef long long ll;

void init() {
    cin.tie(NULL);
    cout.tie(NULL);
    ios::sync_with_stdio(false);
}

int main() {
    init();
    int N;
    cin >> N;

    for (int i = 1; i <= N; i++) {
        int cnt = 0;
        for (int i = 1; i <= 10; i++) {
            int ans;
            cin >> ans;
            if (((i - 1) % 5 + 1) == ans) cnt++;
        }
        if (cnt == 10) cout << i << '\n';
    }
    return 0;
}