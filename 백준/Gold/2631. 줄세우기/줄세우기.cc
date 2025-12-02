#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

int main() {
    int N;
    cin >> N;

    vector<int> chd(N);
    vector<int> dp(N);

    for (int i = 0; i < N; i++) {
        cin >> chd[i];
    }

    // LIS: Longest Increasing Subsequence
    // 최장 증가 수열을 찾는 알고리즘
    // 안움직일 애들은 최대한 움직이지 않는다.
    // 안움직이는 애들 제외한 사람만 움직이면 됌.
    // 3 7 5 2 6 1 4
    // 3 - 5 - 6 - -
    // (-)부분만 배열을 정렬하면 됌. 근데 정렬 횟수가 아니라,
    // 옮겨지는 아이들이니, 7 - 3 = 4
    
    for (int i = 0; i < N; i++) {
        dp[i] = 1;
        for (int j = 0; j < i; j++) {
            if (chd[j] < chd[i]) {
                dp[i] = max(dp[i], dp[j] + 1);
            }
        }
    }

    int K = *max_element(dp.begin(), dp.end());

    cout << N - K;
    return 0;
}