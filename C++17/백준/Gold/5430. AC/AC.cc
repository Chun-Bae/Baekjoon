#include <algorithm>
#include <iostream>
#include <queue>
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

deque<int> getElementsParser(const string& str) {
    deque<int> numbers;
    string trimmed = str.substr(1, str.size() - 2);
    stringstream ss(trimmed);
    string item;

    while (getline(ss, item, ',')) numbers.push_back(stoi(item));

    return numbers;
}

void printList(deque<int> numbers) {
    cout << "reverse: [";
    for (int i = 0; i < numbers.size(); i++) {
        cout << numbers[i];
        if (i != numbers.size() - 1) cout << ',';
    }
    cout << "]\n";
}

void conductCommand(deque<int> numbers, string command) {
    bool isReversed = false;
    for (auto c : command) {
        if (c == 'R') {
            isReversed = !isReversed;

        } else if (c == 'D') {
            if (numbers.empty()) {
                cout << "error\n";
                return;
            } else {
                if (isReversed) {
                    numbers.pop_back();
                } else {
                    numbers.pop_front();
                }
            }
        }
    }
    if (isReversed) reverse(numbers.begin(), numbers.end());
    cout << "[";
    for (int i = 0; i < numbers.size(); i++) {
        cout << numbers[i];
        if (i != numbers.size() - 1) cout << ',';
    }
    cout << "]\n";
}

int main() {
    init();
    int T;
    cin >> T;
    while (T--) {
        string command, str;
        int noUse;
        cin >> command;
        cin >> noUse;
        cin >> str;
        deque<int> numbers = getElementsParser(str);
        conductCommand(numbers, command);
    }

    return 0;
}
