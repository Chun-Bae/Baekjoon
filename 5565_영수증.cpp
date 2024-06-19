#include <iostream>
#include <vector>

using namespace std;

int main() {
    int sum, price;
    cin >> sum;

    for (int i = 0; i < 9; i++) {
        cin >> price;
        sum -= price;
    }
    cout << sum << endl;

    return 0;
}