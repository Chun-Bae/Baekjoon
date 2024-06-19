#include <algorithm>
#include <iostream>
#include <string>

using namespace std;

int main() {
    string ban = "CAMBRIDGE";
    string str;
    cin >> str;
    for (auto& b : ban) str.erase(remove(str.begin(), str.end(), b), str.end());

    cout << str << endl;
    return 0;
}