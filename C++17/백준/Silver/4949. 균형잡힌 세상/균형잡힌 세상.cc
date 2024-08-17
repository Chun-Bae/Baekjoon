#include <iostream>
#include <stack>
#include <string>

using namespace std;

void init() {
    cin.tie(NULL);
    cout.tie(NULL);
    ios::sync_with_stdio(false);
}

bool isBalanced(const string& str) {
    stack<char> s;

    for (char ch : str) {
        if (ch == '(' || ch == '[') {
            s.push(ch);
        } else if (ch == ')') {
            if (s.empty() || s.top() != '(') {
                return false;
            }
            s.pop();
        } else if (ch == ']') {
            if (s.empty() || s.top() != '[') {
                return false;
            }
            s.pop();
        }
    }

    return s.empty();
}

int main() {
    init();
    string line;
    while (true) {
        getline(cin, line);
        if (line == ".") break;

        if (isBalanced(line)) {
            cout << "yes" << endl;
        } else {
            cout << "no" << endl;
        }
    }

    return 0;
}
