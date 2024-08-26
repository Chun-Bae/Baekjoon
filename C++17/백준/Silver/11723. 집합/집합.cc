#include <algorithm>
#include <iostream>
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

int main() {
    init();
    int M;
    cin >> M;

    int S = 0;  

    while (M--) {
        string cmd;
        int x;

        cin >> cmd;
        if (cmd == "add") {
            cin >> x;
            S |= (1 << (x - 1));
        } else if (cmd == "remove") {
            cin >> x;
            S &= ~(1 << (x - 1));
        } else if (cmd == "check") {
            cin >> x;
            if (S & (1 << (x - 1))) {
                cout << 1 << '\n';
            } else {
                cout << 0 << '\n';
            }
        } else if (cmd == "toggle") {
            cin >> x;
            S ^= (1 << (x - 1));
        } else if (cmd == "all") {
            S = (1 << 20) - 1;
        } else if (cmd == "empty") {
            S = 0;
        }
    }

    return 0;
}