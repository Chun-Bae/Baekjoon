#include <iostream>

using namespace std;

int main() {
    int joi = 0, ioi = 0;
    string str;
    string s;
    cin >> str;
    for (int i = 0; i < str.size() - 2; i++) {
        s = "";
        s += str[i];
        s += str[i + 1];
        s += str[i + 2];

        if (!s.compare("JOI")) joi++;
        if (!s.compare("IOI")) ioi++;
    }
    cout << joi << '\n' << ioi << '\n';
    return 0;
}