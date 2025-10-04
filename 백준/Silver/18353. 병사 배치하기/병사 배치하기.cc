#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

int main() {
    int n;
    cin >> n;
    vector<int> soldier(n);
    vector<int> dp(n, 1);

    for (int i = 0; i < n; i++)
        cin >> soldier[i];

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < i; j++) {
            if (soldier[i] < soldier[j]) {
                dp[i] = max(dp[i], dp[j] + 1);
            }
        }
    }

    cout << n - *max_element(dp.begin(), dp.end());

    return 0;
}