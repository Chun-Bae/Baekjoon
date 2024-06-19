#include <iostream>

using namespace std;

int main() {
    int n, l;
    cin >> n;
    while (1) {
        cin >> l;
        if (!l) return 0;
        if (l % n)
            cout << l << " is NOT a multiple of " << n << "." << endl;
        else
            cout << l << " is a multiple of " << n << "." << endl;
    }
    return 0;
}