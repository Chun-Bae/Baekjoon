#include <iostream>
#include <map>

using namespace std;

void init() {
    ios::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);
}

int main() {
    init();
    int n;
    string name, state;
    map<string, string, greater<>> firm;
    cin >> n;
    while (n--) {
        cin >> name >> state;
        firm[name] = state;
    }
    map<string, string>::iterator it;
    for (it = firm.begin(); it != firm.end(); it++) {
        if (it->second == "enter") {
            cout << it->first << "\n";
        }
    }
    return 0;
}