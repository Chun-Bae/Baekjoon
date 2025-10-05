#include <algorithm>
#include <iostream>
#include <numeric>
#include <vector>

using namespace std;

int main() {
    int N, M;
    cin >> N;
    vector<int> budget(N);
    for (int i = 0; i < N; i++)
        cin >> budget[i];
    cin >> M;

    int left = 0;
    int right = M;
    int result = 0;

    if (accumulate(budget.begin(), budget.end(), 0) <= M) {
        result = *max_element(budget.begin(), budget.end());
    } else {
        while (left <= right) {
            int mid = (left + right) / 2;

            int sum = 0;
            for (int i = 0; i < N; i++)
                if (budget[i] > mid)
                    sum += mid;
                else
                    sum += budget[i];

            if (sum == M) {
                result = mid;
                break;

            } else if (sum > M) {
                right = mid - 1;
                result = right;

            } else {
                left = mid + 1;
                result = left;
            }
        }
    }

    cout << result;
    return 0;
}