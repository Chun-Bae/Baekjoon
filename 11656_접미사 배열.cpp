#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

int main() {
    vector<string> sarr;
    string str;

    cin >> str;
    for (int i = 0; i < str.size(); i++) sarr.push_back(str.substr(i, str.size() - i));
    sort(sarr.begin(), sarr.end(), less<string>());
    for (auto& s : sarr) cout << s << endl;

    return 0;
}