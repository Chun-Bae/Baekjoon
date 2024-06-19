#include <iostream>
#include <vector>

using namespace std;

int main() {
    int T;
    string str;
    cin >> T;
    cin.ignore();
    for (int i = 0; i < T; i++) {
        getline(cin, str);
        vector<bool> alphabet(26, false);
        bool flag = true;
        for (auto s : str) {
            if (s >= 'A' && s <= 'Z')
                alphabet[s - 'A'] = true;
            else if (s >= 'a' && s <= 'z')
                alphabet[s - 'a'] = true;
        }
        for (auto alpha : alphabet)
            if (!alpha) flag = false;

        flag ? cout << "pangram " : cout << "missing ";
        for (int i = 0; i < 26; i++)
            if (!alphabet[i]) cout << char(i + 'a');
        cout << endl;
    }
}