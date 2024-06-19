#include <iostream>

using namespace std;

int main() {
    string str;
    int cnt = 0;
    while (1) {
        getline(cin, str);
        if (cin.eof()) break;
        cnt++;
    }
    cout << cnt;
    return 0;
}