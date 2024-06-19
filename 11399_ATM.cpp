#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

int main() {
    vector<int> atm;
    int T, n, sum = 0, ac = 0;
    cin >> T;
    for (int i = 0; i < T; i++) {
        cin >> n;
        atm.push_back(n);
    }
    sort(atm.begin(), atm.end(), less<int>());
    for (auto a : atm) {
        ac += a;
        sum += ac;
    }
    cout << sum;
    return 0;
}