#include <iostream>
#include <queue>

using namespace std;

void init() {
    cin.tie(NULL);
    cout.tie(NULL);
    ios::sync_with_stdio(false);
}

short D_(short n) { return (n * 2) % 10000; }
short S_(short n) { return n == 0 ? 9999 : n - 1; }
short L_(short n) {
    unsigned short d1, d2, d3, d4;
    d1 = n / 1000;
    d2 = (n / 100) % 10;
    d3 = (n / 10) % 10;
    d4 = n % 10;
    return d2 * 1000 + d3 * 100 + d4 * 10 + d1;
}
short R_(short n) {
    unsigned short d1, d2, d3, d4;
    d1 = n / 1000;
    d2 = (n / 100) % 10;
    d3 = (n / 10) % 10;
    d4 = n % 10;
    return d4 * 1000 + d1 * 100 + d2 * 10 + d3;
}
short (*f[4])(short) = {D_, S_, L_, R_};
const string pu5h[] = {"D", "S", "L", "R"};

void bfs(short A, short B) {
    bool visited[10000] = {false};
    queue<pair<int, string>> q;
    q.push({A, ""});
    visited[A] = true;

    while (!q.empty()) {
        short A = q.front().first;
        string pou = q.front().second;
        q.pop();
        if (A == B) {
            cout << pou << endl;
            return;
        }
        for (short i = 0; i < 4; i++) {
            short next_A = f[i](A);
            if (!visited[next_A]) {
                visited[next_A] = true;
                q.push({next_A, pou + pu5h[i]});
            }
        }
    }
}

int main() {
    init();
    short T;
    cin >> T;
    while (T--) {
        short A, B;
        cin >> A >> B;
        bfs(A, B);
    }
    return 0;
}