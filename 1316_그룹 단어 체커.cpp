#include <iostream>
#include <vector>

using namespace std;

int main() {
    int T, count = 0;
    string str;
    cin >> T;
    for (int i = 0; i < T; i++) {
        vector<int> checker(26, 0);
        bool flag = true;
        cin >> str;
        for (int j = 0; j < str.size(); j++) {
            if (j > 0 && str[j] == str[j - 1])
                continue;
            else
                checker[str[j] - 'a']++;
        }

        for (int j = 0; j < 26; j++) {
            if (checker[j] >= 2) {
                flag = false;
                break;
            }
        }
        if (flag) count++;
    }
    cout << count;
    return 0;
}