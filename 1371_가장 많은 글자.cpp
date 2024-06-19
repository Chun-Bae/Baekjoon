#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

int main() {
    vector<int> alphabet(26, 0);
    char a;
    while (1) {
        cin >> a;

        if (cin.eof()) break;
        if (a >= 'a' && a <= 'z') alphabet[a - 'a']++;
    }
    int max = 0;
    for (auto& i : alphabet)
        if (max < i) max = i;

    for (int i = 0; i < 26; i++)
        if (max == alphabet[i]) cout << char(i + 'a');
    return 0;
}