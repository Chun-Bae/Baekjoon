#include <iostream>

using namespace std;

int main() {
    string str;
    cin >> str;
    for (auto& s : str) {
        if (s < 97)
            s += 32;
        else
            s -= 32;
    }
    cout << str;
}