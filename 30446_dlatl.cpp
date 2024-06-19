#include <algorithm>
#include <iostream>
#include <string>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);
    int n, ans = 0;
    cin >> n;
    int tmp = n;
    string s = to_string(n);
    for (int i = 0; i < s.size() / 2; i++) tmp /= 10;
    while (tmp) {
        string l = to_string(tmp);
        string r = l;
        reverse(r.begin(), r.end());
        string value = l + r;
        int num = stoll(value);
        if (num <= n) ans++;
        for (int i = 0; i < 10; i++) {
            string value2 = "";
            value2 += l;
            value2 += i + 48;
            value2 += r;
            int num2 = stoll(value2);
            if (num2 <= n) ans++;
        }
        tmp--;
    }
    if (n >= 9)
        ans += 9;
    else
        ans += n;
    cout << ans << '\n';
    return 0;
}