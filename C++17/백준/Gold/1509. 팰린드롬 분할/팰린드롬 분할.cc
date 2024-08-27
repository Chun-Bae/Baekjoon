#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

typedef long long ll;
typedef vector<int> vec1;
typedef vector<vec1> vec2;
typedef vector<vec2> vec3;

void init() {
    cin.tie(NULL);
    cout.tie(NULL);
    ios::sync_with_stdio(false);
}

int main() {
    init();
    string s;
    cin >> s;
    int n = s.length();

    // isPalindrome[i][j]: i부터 j까지 팰린드롬 체크
    vector<vector<bool>> isPalindrome(n, vector<bool>(n, false));

    // "aabb" dp[0] = 1, dp[1] = 1, dp[2] = 2, dp[3] = 2 // (a), (aa), (aa | b), (aa | bb)
    // n으로 초기화하는 이유 : 최악의 경우 n개의 문자를 모두 사용해야 하기 때문
    // "abcd" dp[0] = 1, dp[1] = 2, dp[2] = 3, dp[3] = 4 // (a), (a | b), (a | b | c), (a | b | c | d)
    vec1 dp(n, n);

    // 길이가 1
    for (int i = 0; i < n; i++) {
        isPalindrome[i][i] = true;
    }

    for (int length = 2; length <= n; length++) {
        for (int i = 0; i <= n - length; i++) {
            int j = i + length - 1;
            if (s[i] == s[j]) {
                if (length == 2) {
                    isPalindrome[i][j] = true;
                } else {
                    isPalindrome[i][j] = isPalindrome[i + 1][j - 1];
                }
            }
        }
    }

    for (int i = 0; i < n; i++) {
        if (isPalindrome[0][i]) {
            // 팰린드롬이면 1개 분할만 필요
            dp[i] = 1;
        } else {
            // 팰린드롬이 아니니까 i까지의 문자열의 dp에 이전 문자열까지 얼마나 분할됐는지 더하면서 확인
            for (int j = 1; j <= i; j++) {
                if (isPalindrome[j][i]) {
                    dp[i] = min(dp[i], dp[j - 1] + 1);
                }
            }
        }
    }

    cout << dp[n - 1] << endl;
    return 0;
}