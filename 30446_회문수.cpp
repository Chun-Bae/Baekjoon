#include <algorithm>
#include <iostream>

typedef long long ll;
using namespace std;

void init() {
    cin.tie(NULL);
    cout.tie(NULL);
    ios::sync_with_stdio(false);
}

int ll_size(ll n) {
    int cnt = 0;
    while (n) {
        n /= 10;
        cnt++;
    }
    return cnt;
}

int main() {
    init();
    ll n;
    int cnt = 0;
    cin >> n;

    if (n <= 9) {
        cnt += n;
    } else {
        cnt += 9;
        int size = ll_size(n);
        // n: 123456 => 123
        for (int p = 1; p < 100000; p++) {
            // palindrome: 123321
            string left = to_string(p);
            string right = left;
            reverse(right.begin(), right.end());
            string palindrome = left + right;

            ll palindrome_n = stoll(palindrome);
            // 짝수 count.
            if (palindrome_n <= n) cnt++;
        }
        for (int p = 1; p < 10000; p++) {
            string left = to_string(p);
            string right = left;
            reverse(right.begin(), right.end());            
            // palindrome: 1230321 1231321 1232321 ...
            // 홀수 count.
            for (int mid = 0; mid <= 9; mid++) {
                string palindrome = left + to_string(mid) + right;
                ll palindrome_n = stoll(palindrome);
                if (palindrome_n <= n) cnt++;
            }
        }
    }
    cout << cnt;
    return 0;
}