#include <iostream>

using namespace std;

int main() {
    int T;
    string str;
    bool gksek = false;
    cin >> T;
    for (int i = 0; i < T; i++) {
        cin >> str;
        str[str.size() / 2] == str[str.size() / 2 - 1] ? cout << "Do-it" : cout << "Do-it-Not";
        cout << endl;
    }
    return 0;
}