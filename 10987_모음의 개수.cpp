#include <iostream>

using namespace std;

int main() {
    string str;
    int count = 0;
    cin >> str;
    for (auto& s : str)
        if (s == 'a' || s == 'e' || s == 'i' || s == 'o' || s == 'u') ++count;
    cout << count;
    return 0;
}