#include <algorithm>
#include <iostream>

using namespace std;

int main() {
    string str;
    int n, m;
    cin >> n >> m;
    while (n--) {
        cin >> str;
        reverse(str.begin(), str.end());
        cout << str << '\n';
    }
    return 0;
}