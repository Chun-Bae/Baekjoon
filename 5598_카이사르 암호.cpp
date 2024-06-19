#include <iostream>

using namespace std;

int main() {
    string str;
    cin >> str;
    for (auto& s : str) {
        s -= 65;
        s += 23;
        s %= 26;
        s += 65;
    }
    cout << str;
    return 0;
}