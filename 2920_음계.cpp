#include <iostream>

using namespace std;

int main() {
    int n;
    bool a = true, b = true;
    for (int i = 1; i <= 8; i++) {
        cin >> n;
        if (n != i) a = false;
        if (n != 9 - i) b = false;
    }
    if (a)
        cout << "ascending";
    else if (b)
        cout << "descending";
    else
        cout << "mixed";

    return 0;
}