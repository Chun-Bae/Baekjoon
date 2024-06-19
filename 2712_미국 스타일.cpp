#include <iostream>

using namespace std;

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
        double n;
        string str;
        cin >> n >> str;
        if (str == "kg") {
            str = "lb";
            n *= 2.2046;
        } else if (str == "lb") {
            str = "kg";
            n *= 0.4536;
        } else if (str == "l") {
            str = "g";
            n *= 0.2642;
        } else if (str == "g") {
            str = "l";
            n *= 3.7854;
        }
        cout << fixed;
        cout.precision(4);
        cout << n << " " << str << '\n';
    }
    return 0;
}