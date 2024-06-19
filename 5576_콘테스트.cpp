#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

int main() {
    vector<int> uni(10);
    int n, w, k;
    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < 10; j++) {
            cin >> n;
            uni[j] = n;
        }
        sort(uni.begin(), uni.end(), greater<int>());
        if (!i) w = uni[0] + uni[1] + uni[2];
        if (i) k = uni[0] + uni[1] + uni[2];
    }
    cout << w << " " << k << endl;
    return 0;
}