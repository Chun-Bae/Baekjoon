#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

typedef long long ll;

void init(){
    cin.tie(NULL);
    cout.tie(NULL);
    ios::sync_with_stdio(false);
}

int trimMean(vector<int>& arr) {
    int n = arr.size();
    if (n == 0) {
        return 0;
    }

    sort(arr.begin(), arr.end());

    int trim_count = round(0.15 * n);
    if (trim_count > 0) {
        arr.erase(arr.begin(), arr.begin() + trim_count);
        arr.erase(arr.end() - trim_count, arr.end());
    }

    if (arr.empty()) {
        return 0;
    }

    int sum = 0;
    for (int n : arr) {
        sum += n;
    }
    int average = round(static_cast<double>(sum) / arr.size());

    return average;
}

int main(){
    init();

    int n;
    cin >> n;

    vector<int> arr(n);
    for (int i = 0; i < n; ++i) {
        cin >> arr[i];
    }

    int difficulty = trimMean(arr);
    cout << difficulty << '\n';

    return 0;
}
