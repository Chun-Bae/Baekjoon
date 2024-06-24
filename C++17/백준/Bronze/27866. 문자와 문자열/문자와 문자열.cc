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
    string S;
    int i;
    cin >> S >> i;
    cout << S[i-1];

    return 0;
}