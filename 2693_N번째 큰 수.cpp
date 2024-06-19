#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

int main() {
    vector<int> num(10);
    int T, n;

    cin >> T;
    for (int i = 0; i < T; i++) {
        for (int j = 0; j < 10; j++) {
            cin >> n;
            num[j] = n;
        }
        sort(num.begin(), num.end(), greater<int>());
        cout << num[2] << endl;
    }
    return 0;
}