#include <algorithm>
#include <iostream>

using namespace std;

int main() {
    string n1, n2;
    string n;
    int T;
    cin >> T;
    while (T--) {
        cin >> n1;
        n2 = n1;
        reverse(n1.begin(), n1.end());
        n = to_string(stoi(n1) + stoi(n2));
        int size = n.size();

        string l = n.substr(0, size / 2);
        string m;
        if (size % 2 == 1)
            m = n[size / 2];
        else
            m = "";
        string r = l;
        reverse(r.begin(), r.end());
        string cmp = l + m + r;

        if (n == cmp)
            cout << "YES" << '\n';
        else
            cout << "NO" << '\n';
    }

    return 0;
}