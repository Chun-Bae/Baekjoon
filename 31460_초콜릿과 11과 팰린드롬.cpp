#include <algorithm>
#include <iostream>

typedef long long ll;
using namespace std;

void init() {
    cin.tie(NULL);
    cout.tie(NULL);
    ios::sync_with_stdio(false);
}

// int c_pow(int a, int b) {
//     int result = 1;
//     while (b--) result *= a;
//     return result;
// }

int main() {
    init();
    int T;
    cin >> T;
    // T=18;
    // while (T--) {
    //     int n;
    //     n= 18-T;
    //     ll divide_11;
    //     bool is_mid;
    //     bool is_divide_11 = false;
    //     //cin >> n;
    //     if (n == 1) {
    //         is_divide_11 = true;
    //         divide_11 = 0;
    //     } else {
    //         n % 2 == 1 ? is_mid = true : is_mid = false;
    //         n /= 2;
    //         for (int i = c_pow(10, n - 1); i < c_pow(10, n); i++) {
    //             string left;
    //             string right;
    //             string palindrome;
    //             left = to_string(i);
    //             string tmp = left;
    //             reverse(tmp.begin(), tmp.end());
    //             right = tmp;
    //             if (is_mid) {
    //                 for (int mid = 0; mid <= 9; mid++) {
    //                     palindrome = left + to_string(mid) + right;
    //                     ll palindrome_n = stoll(palindrome);
    //                     if (palindrome_n % 11 == 0) {
    //                         is_divide_11 = true;
    //                         divide_11 = palindrome_n;
    //                         break;
    //                     }
    //                 }
    //                 if (is_divide_11) break;
    //             } else {
    //                 palindrome = left + right;
    //                 ll palindrome_n = stoll(palindrome);
    //                 if (palindrome_n % 11 == 0) {
    //                     is_divide_11 = true;
    //                     divide_11 = palindrome_n;
    //                     break;
    //                 }
    //             }
    //         }
    //     }
    //     is_divide_11 ? cout << divide_11 << '\n' : cout << -1 << '\n';
    // }
    for (int i = 0; i < T; i++) {
        int n;
        cin >> n;        
        string palindrome;
        if (n % 4 == 1) {
            if (n == 1)
                cout << "0";
            else {
                string mid = "9";
                int half = n / 4;
                string left = "1";
                for (int k = 0; k < half * 2 - 1; k++) left += "0";
                string right = left;
                reverse(right.begin(), right.end());
                palindrome = left + mid + right;
            }
        } else if (n % 4 == 2) {
            int half = n / 4;
            string left = "1";
            for (int k = 0; k < half * 2; k++) left += "0";
            string right = left;
            reverse(right.begin(), right.end());
            palindrome = left + right;
        } else if (n % 4 == 3) {
            string mid = "2";
            int half = n / 4;
            string left = "1";
            for (int k = 0; k < half * 2; k++) left += "0";
            string right = left;
            reverse(right.begin(), right.end());
            palindrome = left + mid + right;

        } else if (n % 4 == 0) {
            int half = n / 4;
            string left = "1";
            for (int k = 0; k < half * 2 - 1; k++) left += "0";
            string right = left;
            reverse(right.begin(), right.end());
            palindrome = left + right;
        }
        cout << palindrome << '\n';
    }
    return 0;
}