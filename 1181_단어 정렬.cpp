#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

bool comp(string a, string b) {
    if (a.length() != b.length()) {
        return a.length() < b.length();
    } else {
        return a < b;
    }
}

int main() {
    vector<string> strs;
    string str;
    int T;
    cin >> T;
    for (int i = 0; i < T; i++) {
        cin >> str;
        strs.push_back(str);
    }
    sort(strs.begin(), strs.end(), comp);
    strs.erase(unique(strs.begin(), strs.end()), strs.end());
    for (int i = 0; i < strs.size(); i++) cout << strs[i] << endl;

    return 0;
}