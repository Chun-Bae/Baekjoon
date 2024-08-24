#include <iostream>
#include <vector>
#include <deque>
#include <algorithm>

using namespace std;

int main() {
    int n;
    cin >> n;

    vector<int> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }

    deque<int> maxDeque, minDeque;
    int left = 0, maxLen = 0;

    for (int right = 0; right < n; ++right) {
        while (!maxDeque.empty() && a[maxDeque.back()] <= a[right]) {
            maxDeque.pop_back();
        }
        maxDeque.push_back(right);

        while (!minDeque.empty() && a[minDeque.back()] >= a[right]) {
            minDeque.pop_back();
        }
        minDeque.push_back(right);

        while (a[maxDeque.front()] - a[minDeque.front()] > 2) {
            left++;

            if (maxDeque.front() < left) {
                maxDeque.pop_front();
            }
            if (minDeque.front() < left) {
                minDeque.pop_front();
            }
        }

        maxLen = max(maxLen, right - left + 1);
    }

    cout << maxLen << endl;
    return 0;
}
