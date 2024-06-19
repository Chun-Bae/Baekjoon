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
    string A, B;
    cin >> A >> B;

    for (auto& s1 : A)
        if (s1 == '6') s1 = '5';
    for (auto& s2 : B)
        if (s2 == '6') s2 = '5';
    cout << stoi(A) + stoi(B);
    cout << " ";
    for (auto& s1 : A)
        if (s1 == '5') s1 = '6';
    for (auto& s2 : B)
        if (s2 == '5') s2 = '6';
    cout << stoi(A) + stoi(B);
    return 0;
}