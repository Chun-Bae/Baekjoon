#include <iostream>

using namespace std;

int main() {
    string str;
    string kmp = "";
    cin >> str;
    kmp += str[0];
    for (int i = 1; i < str.size(); i++)
        if (str[i] == '-') kmp += str[i + 1];
    cout << kmp;
    return 0;
}