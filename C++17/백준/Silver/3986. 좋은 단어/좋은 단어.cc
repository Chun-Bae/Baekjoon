#include <iostream>
#include <stack>
#include <string>

using namespace std;


void init(){
    cin.tie(NULL);
    cout.tie(NULL);
    ios::sync_with_stdio(false);
}

bool isGoodWord(const string &word) {
    stack<char> s;
    for (char ch : word) {
        if (!s.empty() && s.top() == ch) {
            s.pop();
        } else {
            s.push(ch);
        }
    }
    return s.empty();
}

int main() {
    init();
    int n;
    cin >> n;
    int goodWordCount = 0;

    for (int i = 0; i < n; ++i) {
        string word;
        cin >> word;
        if (isGoodWord(word)) {
            ++goodWordCount;
        }
    }

    cout << goodWordCount << "\n";
    return 0;
}
