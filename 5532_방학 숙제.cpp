#include <iostream>

using namespace std;

int main() {
    int L, A, B, C, D;
    cin >> L >> A >> B >> C >> D;
    cout << L - ((A / C > B / D) ? ((A % C) ? (A / C + 1) : (A / C)) : ((B % D) ? (B / D + 1) : (B / D)));
    return 0;
}