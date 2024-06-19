#include <deque>
#include <iostream>

using namespace std;

int main() {
    deque<int> d;
    int N, input;
    string opt;
    cin >> N;
    for (int i = 0; i < N; i++) {
        cin >> opt;
        if (opt == "push_back") {
            cin >> input;
            d.push_back(input);
        }
        if (opt == "push_front") {
            cin >> input;
            d.push_front(input);
        }

        if (opt == "size") cout << d.size() << endl;
        if (opt == "empty") d.size() ? cout << 0 << endl : cout << 1 << endl;
        if (opt == "front") d.size() ? cout << d.front() << endl : cout << -1 << endl;
        if (opt == "back") d.size() ? cout << d.back() << endl : cout << -1 << endl;

        if (opt == "pop_back") {
            if (d.size()) {
                cout << d.back() << endl;
                d.pop_back();
            } else
                cout << -1 << endl;
        }

        if (opt == "pop_front") {
            if (d.size()) {
                cout << d.front() << endl;
                d.pop_front();
            } else
                cout << -1 << endl;
        }
    }
    return 0;
}