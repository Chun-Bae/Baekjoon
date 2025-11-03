#include <deque>
#include <iostream>

using namespace std;

typedef long long ll;

void init() {
    cin.tie(NULL);
    cout.tie(NULL);
    ios::sync_with_stdio(false);
}

int main() {
    init();
    int n;
    cin >> n;
    deque<int> dq(n);
    for (int i = 0; i < n; i++) dq[i] = i + 1;

    while (!dq.empty()) {
        if (dq.size() == 1) cout << dq.front();
        dq.pop_front();
        dq.push_back(dq.front());
        dq.pop_front();
    }

    return 0;
}