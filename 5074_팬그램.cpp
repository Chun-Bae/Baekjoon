#include <iostream>
#include <vector>
using namespace std;

int main() {
    string str;
    while (1) {
        getline(cin, str);
        if (str == "*") break;

        vector<bool> alphabet(26, false);
        bool flag = true;
        for (auto s : str)
            if (s >= 'a' && s <= 'z') alphabet[s - 97] = true;
        for (auto alpha : alphabet)
            if (!alpha) flag = false;

        flag ? cout << "Y" << endl : cout << "N" << endl;
    }
}