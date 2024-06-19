#include <iostream>

using namespace std;

bool isUppercase(char s) { return s < 0x41 + 26 && s >= 0x41; }
bool isLowercase(char s) { return s < 0x61 + 26 && s >= 0x61; }

void Caesar(char* s, int rel) {
    int interval = 'O' - 'B';
    *s -= rel;
    *s += interval;
    *s %= 26;
    *s += rel;
}

int main() {
    string str;
    getline(cin, str);
    for (auto& s : str) {
        if (isUppercase(s))
            Caesar(&s, 0x41);
        else if (isLowercase(s))
            Caesar(&s, 0x61);
    }
    cout << str;
    return 0;
}