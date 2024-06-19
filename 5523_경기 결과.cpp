#include <iostream>

using namespace std;

int main() {
    int T, a, b, ac = 0, bc = 0;
    cin >> T;
    for (int i = 0; i < T; i++) {
        cin >> a >> b;
        if (a > b) ac++;
        if (a < b) bc++;
    }
    cout << ac << " " << bc << endl;
    return 0;
}