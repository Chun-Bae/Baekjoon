#include <iostream>

using namespace std;

typedef long long ll;
// 전체 i자리수 중 j개가 1이 포함될 수 있는 개수
ll dp[33][33];
string bin;

void init() {
    cin.tie(NULL);
    cout.tie(NULL);
    ios::sync_with_stdio(false);
}

void bin_search(int N, int L, ll I) {

    if (N == 0) return;
    if (L == 0) {
        for (int i = 0; i < N; i++) bin += '0';
        return;
    }
    ll cumulative = 0;

    for (int i = 0; i <= L; i++) cumulative += dp[N - 1][i];
    // cout << "=============" << endl;
    // cout << "bin: " << bin << endl;
    // cout << "cumulative: " << cumulative << endl;
    // cout << "+++++" << endl;
    // cout << "N,L,I: " << N << " " << L << " " << I << endl;
    // cout << "+++++" << endl;
    // printDP(N - 1);
    // 5비트에서 3개이하 경우 15/19번째 // 1 --> 이제 1번째 비트제외 하면 그 아래의 4번째 비트를구하는 방식으로
    // 4비트에서 2개이하 경우 7/4번째 // 10 --> 초과하므로 그 아랫단 비트에서 찾아도 됌
    // 3비트에서 2개이하 경우 4/4번째 // 100 --> 초과는 아니지만 개수가 남기 때문에 초과로 해도 상관 없음.
    // 2비트에서 2개이하 경우 2/4번째 // 1001
    // 1비트에서 1개이하 경우 1/2번째 // 10011
    if (cumulative >= I) {
        bin += '0';
        bin_search(N - 1, L, I);

    } else {
        bin += '1';
        bin_search(N - 1, L - 1, I - cumulative);
    }

    return;
}

int main() {
    init();
    int N, L;
    ll I;
    cin >> N >> L >> I;  // N에서 L자리수 이하 중 I번째

    dp[0][0] = 1;
    for (int i = 1; i < 33; i++) {
        dp[i][0] = 1;
        dp[i][i] = 1;
    }
    // 파스칼 표 만들기
    for (int i = 2; i <= N; i++) {
        for (int j = 1; j <= i; j++) {
            dp[i][j] = dp[i - 1][j - 1] + dp[i - 1][j];
        }
    }
    bin_search(N, L, I);
    cout << bin;
    return 0;
}