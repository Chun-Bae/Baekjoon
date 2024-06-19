#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

int main() {
    vector<int> three_num(3);
    int input;
    for (int i = 0; i < 3; i++) {
        cin >> input;
        three_num[i] = input;
    }
    sort(three_num.begin(), three_num.end(), less<int>());
    for (int i = 0; i < 3; i++) {
        cout << three_num[i] << " ";
    }

    return 0;
}