#include <iostream>

using namespace std;

int main() {
    int T;
    string str;
    cin >> T;
    cin.ignore();
    for (int i = 0; i < T; i++) {
        getline(cin, str);
        if (str[0] >= 97) str[0] -= 32;
        cout << str << endl;
    }
    return 0;
}