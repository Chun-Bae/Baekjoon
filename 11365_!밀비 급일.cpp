#include <algorithm>
#include <iostream>

using namespace std;

int main() {
    string str;
    while (1) {
        getline(cin, str);
        if (!str.compare("END")) return 0;
        reverse(str.begin(), str.end());
        cout << str << endl;
    }
    return 0;
}