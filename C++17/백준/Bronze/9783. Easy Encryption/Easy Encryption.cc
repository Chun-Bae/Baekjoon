#include <iomanip>
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
    char c;

    while (cin.get(c)) {
        int n;
        if (c >= 'A' && c <= 'Z') {
            n = c - 'A' + 1 + 26;
        } else if (c >= 'a' && c <= 'z') {
            n = c - 'a' + 1;
        } else if (c >= '0' && c <= '9') {
            cout << '#' << c;
            continue;
        }

        else if (c == ' ') {
            cout << ' ';
            continue;
        } else {
            cout << c;
            continue;
        }

        cout << setw(2) << setfill('0') << n;
    }
    return 0;
}