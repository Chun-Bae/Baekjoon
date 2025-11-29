#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

int main() {
    int n;
    cin >> n;
    vector<int> wine(n);
    vector<int> dp(n);
    for (int i = 0; i < n; i++)
        cin >> wine[i];

    if(n==1){
        cout<<wine[0];
        return 0;
    }

    if(n==2){
        cout<<wine[0]+wine[1];
        return 0;
    }

    dp[0] = wine[0];
    dp[1] = wine[0]+wine[1];
    dp[2] = max({
        wine[0]+wine[1],
        wine[1]+wine[2],
        wine[0]+wine[2],
    });

    for (int i = 3; i < n; i++) {
        // 현재 안 마시는 경우
        int a = dp[i - 1];
        // 이전 거를 안마시고 현재 마시는 경우
        int b = dp[i - 2] + wine[i];
        // 이전 이전 거를 안마시고 이전거와 현재거를 마심
        int c = dp[i - 3] + wine[i - 1] + wine[i];

        dp[i] = max({a, b, c});
    }
    cout << dp[n-1];

    return 0;
}
