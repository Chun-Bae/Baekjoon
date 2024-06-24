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
    int T;
    cin >> T;
    while (T--) {
        int R;
        string S;
        cin >> R >> S;
        for (auto& c : S) {
            for (int j = 0; j < R; ++j) {
                cout << c;
            }
        }
        cout << '\n';
    }
    return 0;
}