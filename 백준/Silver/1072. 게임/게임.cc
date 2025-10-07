#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;
typedef long long ll;

int winning(double X, double Y) {
    return (ll)(Y * 100 / X);
}

int main() {
    double X, Y;
    cin >> X >> Y;

    ll Z = winning(X, Y);
    if (Z >= 99) {
        cout << -1;
        return 0;
    }
    ll left = 0;
    ll right = 1e9;
    while (left <= right) {
        ll mid = (left + right) / 2;
        // cout <<"mid: "<< mid << endl;

        if (winning(X + mid, Y + mid) >= Z + 1) {
            right = mid - 1;
        } else {
            left = mid + 1;
        }
    }
    if (winning(X + left, Y + left) == Z)
        cout << -1;
    else
        cout << left;
    return 0;
}