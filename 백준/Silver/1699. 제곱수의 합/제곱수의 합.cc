#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

int main() {
    int N;
    cin >> N;

    vector<int> dp(N+1,1e9);

    dp[0]=0;
    for (int i=1; i<=N; i++) {
        for (int j=1; j*j<=i; j++) {
            // 1씩 더하는 게 많은 수가 되지만, 그와 동시에 최소이기도 함.
            // 그래서 1씩 더하는 게 아닌 어떤 제곱 수가 더해진다면 최소한으 항으로 확보가 가능해짐.
            // i에서 j*j 만큼 빠진 건, 어떤 수에서 j*j만큼 더한 게 i라는 것.
            dp[i]=min(dp[i],dp[i-j*j]+1);
            // printf("%d %d\n",i,j);
            // for (int k=0; k<=N; k++) {
            //     printf("%10d ",dp[k]);
            // }
            // cout<<'\n';
        }
    }
    cout<<dp[N]<<'\n';

    return 0;
}