#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

int main() {
    vector<int> median_arr(5);
    int n, median, avg = 0;
    for (int i = 0; i < 5; i++) {
        cin >> n;
        median_arr[i] = n;
    }
    for (auto& medi : median_arr) avg += medi;
    avg /= 5;
    sort(median_arr.begin(), median_arr.end(), less<int>());
    median = median_arr[2];
    cout << avg << endl << median << endl;
    return 0;
}