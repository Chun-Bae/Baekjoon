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
    unsigned short birthYear, birthMonth, birthDay;
    unsigned short currentYear, currentMonth, currentDay;
    cin >> birthYear >> birthMonth >> birthDay;
    cin >> currentYear >> currentMonth >> currentDay;

    if (currentMonth > birthMonth || (currentMonth == birthMonth && currentDay >= birthDay)) {
        cout << currentYear - birthYear << '\n';
    } else {
        cout << currentYear - birthYear - 1 << '\n';
    }
    cout << currentYear - birthYear + 1 << '\n';
    cout << currentYear - birthYear << '\n';
    
    return 0;
}