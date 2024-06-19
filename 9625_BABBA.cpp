#include <iostream>

using namespace std;

void dp(int *a, int *b) {
    int at = *a, bt = *b;
    at = *b;
    bt = *a + *b;
    *a = at;
    *b = bt;
}

int main() {
    int n;
    int a = 0;
    int b = 1;
    cin >> n;
    while ((n--) > 1) {
        dp(&a, &b);
    }
    cout << a << " " << b;
    return 0;
}