#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

typedef long long ll;

void init() {
    cin.tie(NULL);
    cout.tie(NULL);
    ios::sync_with_stdio(false);
}

int binary_search(const vector<int>& arr, double value) {
    int left = 0, right = arr.size();
    while (left < right) {
        int mid = left + (right - left) / 2;
        if (arr[mid] < value) {
            left = mid + 1;
        } else {
            right = mid;
        }
    }
    return left;
}

int main() {
    init();
    int N;
    cin >> N;
    vector<int> file_size(N);
    for (int i = 0; i < N; i++) {
        cin >> file_size[i];
    }

    sort(file_size.begin(), file_size.end());

    ll count = 0;

    for (int j = 0; j < N; j++) {
        double min_size = file_size[j] * 0.9;

        int lower = binary_search(file_size, min_size);

        if (lower < j) {
            count += j - lower;
        }
    }

    cout << count << endl;

    return 0;
}
