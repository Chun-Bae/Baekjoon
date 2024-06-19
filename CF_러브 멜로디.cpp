#include <iostream>
#include <sstream>
#include <string>
#include <vector>

using namespace std;

typedef long long ll;

void init() {
    cin.tie(NULL);
    cout.tie(NULL);
    ios::sync_with_stdio(false);
}

int main() {
    init();
    int N;
    int yes = 0;
    cin >> N;
    string str;
    cin >> ws;
    getline(cin, str);
    for (auto s : str) {
        if (s == 'A' || s == 'G' || s == 'F' || s == 'E' || s == 'D') yes++;
    }

    vector<string> ttok;
    stringstream stream(str);
    string token;
    while (getline(stream, token, '.')) {
        if (token != "") ttok.push_back(token);
    }
    int size = 0;
    bool is = false;
    // cout << "size: " << ttok.size() << endl;
    if (ttok.size() >= 3) {
        for (int i = 0; i < ttok.size() - 2; i++) {
            // cout << ttok[i] << ", " << ttok[i + 1] << ", " << ttok[i + 2] << endl;
            if (ttok[i].size() >= 2 && ttok[i + 1].size() == 2 && ttok[i + 2].size() >= 1) is = true;
        }
    }

    if (is && yes >= 5)
        cout << "Yes" << endl;
    else
        cout << "No" << endl;

    return 0;
}
