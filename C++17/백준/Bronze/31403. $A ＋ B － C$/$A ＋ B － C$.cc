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
    string A, B, C;
    cin >> A >> B >> C;
    cout << stoi(A) + stoi(B) - stoi(C) << '\n';
    A.append(B);
    cout << stoi(A) - stoi(C) << '\n';
    return 0;
}