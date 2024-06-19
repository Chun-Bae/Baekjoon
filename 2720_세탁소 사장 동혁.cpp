#include <iostream>
#define QUARTER 25
#define DIME 10
#define NICKEL 5
#define PENNY 1
using namespace std;

void balance(int *price, int *unit, int unit_frame) {
    if (*price / unit_frame) {
        *unit = *price / unit_frame;
        *price %= unit_frame;
    } else
        *unit = 0;
}

int main() {
    int T;
    int quarter, dime, nickel, penny;
    int price;

    cin >> T;
    for (int i = 0; i < T; i++) {
        cin >> price;
        balance(&price, &quarter, QUARTER);
        balance(&price, &dime, DIME);
        balance(&price, &nickel, NICKEL);
        balance(&price, &penny, PENNY);
        cout << quarter << " " << dime << " " << nickel << " " << penny << '\n';
    }
    return 0;
}