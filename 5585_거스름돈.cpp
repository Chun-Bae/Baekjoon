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
    int cnt = 0;
    int money;
    cin >> money;
    money = 1000 - money;
    if (money / 500) {
        cnt += money / 500;
        money %= 500;
    }
    if (money / 100) {
        cnt += money / 100;
        money %= 100;
    }
    if (money / 50) {
        cnt += money / 50;
        money %= 50;
    }
    if (money / 10) {
        cnt += money / 10;
        money %= 10;
    }
    if (money / 5) {
        cnt += money / 5;
        money %= 5;
    }
    cnt += money;
    cout << cnt;
    return 0;
}