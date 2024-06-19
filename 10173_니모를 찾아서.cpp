#include <algorithm>
#include <iostream>
#include <string>
using namespace std;

int main() {
    string str, s;
    bool isF;
    while (1) {
        getline(cin, str);
        if (str == "EOI") break;
        isF = false;
        if (str.size() >= 4) {
            for (int i = 0; i <= str.size() - 4; i++) {
                s = str.substr(i, 4);
                transform(s.begin(), s.end(), s.begin(), ::tolower);
                if (s == "nemo") {
                    isF = true;
                    break;
                }
            }
        }
        if (isF)
            cout << "Found" << endl;
        else
            cout << "Missing" << endl;
    }

    return 0;
}