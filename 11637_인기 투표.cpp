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
    int T;
    cin >> T;
    while (T--) {
        int n;
        cin >> n;

        vector<int> vot(n);
        int total = 0, max = 0, maxIdx = -1;
        bool no = false;
        for (int i = 0; i < n; i++) {
            cin >> vot[i];
            total += vot[i];
            if (vot[i] > max) {
                max = vot[i];
                maxIdx = i;
                no = false;
            } else if (vot[i] == max) {
                no = true;
            }
        }
        if (no)
            cout << "no ";
        else if (max > total / 2)
            cout << "majority ";
        else
            cout << "minority ";
        cout << "winner ";
        if (!no) cout << maxIdx + 1;
        cout << '\n';
    }
    return 0;
}