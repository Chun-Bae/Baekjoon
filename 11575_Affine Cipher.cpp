#include <iostream>

using namespace std;

int main() {
    int T, a, b;
    string str;
    cin >> T;
    for (int i = 0; i < T; i++) {
        cin >> a >> b;
        cin >> str;
        for (auto& s : str) {
            cout << char((((s - 65) * a + b) % 26) + 65);
        }
        cout << '\n';
    }
    return 0;
}