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
    int n0, n1, n2, n3, n4;
    for (int i = 1;; i++) {
        cin >> n0;
        if (n0 == 0) break;

        n1 = 3 * n0;
        if (n1 % 2 == 0) {
            n2 = (n1 + 1) / 2;
            cout<<i<<". even ";
        } else {
            n2 = n1 / 2;
            cout<<i<<". odd ";
        }
        n3 = 3 * n2;
        n4 = n3 / 9;

        n1 % 2 == 0 ? n0 = 2 * n4 : n0 = 2 * n4 + 1;
        cout<<n4<<endl;
    }
    return 0;
}