#include <iostream>
#include <queue>
#include <vector>

using namespace std;

void init() {
    cin.tie(NULL);
    cout.tie(NULL);
    ios::sync_with_stdio(false);
}

int main() {
    init();
    int N, K;
    cin >> N >> K;
    queue<int> q;
    for (int i = 0; i < N; i++) {
        q.push(i + 1);
    }
    cout << "<";
    while (!q.empty()) {
        for (int i = 0; i < K - 1; i++) {
            q.push(q.front());
            q.pop();
        }
        cout << q.front();
        q.pop();
        if (!q.empty()) {
            cout << ", ";
        }
    }
    cout << ">";

    return 0;
}