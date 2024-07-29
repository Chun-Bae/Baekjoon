#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void init(){
    cin.tie(NULL);
    cout.tie(NULL);
    ios::sync_with_stdio(false);
}

int main(){
    init();
    int N, M;
    cin >> N >> M;
    vector<int> memory(N);
    vector<int> cost(N);
    for(int i = 0; i < N; i++){
        cin >> memory[i];
    }
    for(int i = 0; i < N; i++){
        cin >> cost[i];
    }
    
    // dp[c] = m: cost c로 확보할 수 있는 최대 메모리 m
    // 즉 cost c일 때 확보할 수 있는 최대 메모리를 저장
    vector<int> dp(10001, 0);

    for(int i = 0; i < N; i++){
        for(int j = 10000; j >= cost[i]; j--){
            // j는 현재 앱을 추가하기 전의 cost
            // j-cost[i]로 확보할 수 있는 메모리 + 현재 앱을 추가했을 때의 메모리와
            // j로 확보할 수 있는 메모리 중 큰 값을 선택

            // 즉 현재 앱을 추가했을 때와 추가하지 않았을 때 중 큰 값을 선택하는 것을
            // 모든 cost에 대해 반복

            // 더 쉽게 보자면 j를 10이라고 할때 cost[i]가 3이라면
            // dp[10]은 비용 10으로 확보할 수 있는 메모리이고
            // dp[10-3=7]은 비용 7로 확보할 수 있는 메모리로 여기에
            // cost[i]만큼 비용이 드는 메모리와  비용 10짜리 메모리를 더한 값이
            // dp[10]이 되므로 기존의 dp[10]에 대해 비교하여 큰 값을 선택하는 것이다.
            dp[j] = max(dp[j], dp[j - cost[i]] + memory[i]);
            
            // 역순으로 하는 이유는 갱신과정에서 중복 업데이트가 발생할 수 있기 때문
            // j = 3일 때
            // dp[3] = max(dp[3], dp[0] + 30) = 30
            // 결과: dp[3] = 30

            // j = 4일 때
            // dp[4] = max(dp[4], dp[1] + 30) = 30
            // 결과: dp[4] = 30

            // j = 5일 때
            // dp[5] = max(dp[5], dp[2] + 30) = 30
            // 결과: dp[5] = 30

            // j = 6일 때
            // dp[6] = max(dp[6], dp[3] + 30) = 60
            // 결과: dp[6] = 60 --> 중복 업데이트 발생
        }
    }

    int result = 0;
    while(dp[result] < M) result++;
    cout << result << endl;

    return 0;
}
