#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

void init() {
    cin.tie(NULL);
    cout.tie(NULL);
    ios::sync_with_stdio(false);
}

int main() {
    init();
    int N;
    cin >> N;
    vector<string> words;
    while (N--) {
        string str;
        bool flag = false;
        cin >> str;
        sort(str.begin(), str.end());
        if (words.empty()) {
            words.push_back(str);
            continue;
        }

        for (auto &word : words) {
            if (word.compare(str) == 0) {
                flag = true;
                break;
            }
        }
        if (!flag) {
            words.push_back(str);
        }
    }

    cout << words.size() << '\n';
    return 0;
}