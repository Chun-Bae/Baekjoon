#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

void init() {
    cin.tie(NULL);
    cout.tie(NULL);
    ios::sync_with_stdio(false);
}

vector<int> num2digit(int n) {
    vector<int> d;
    while (n) {
        d.push_back(n % 10);
        n /= 10;
    }
    reverse(d.begin(), d.end());
    return d;
}

int power(int a, int b) {
    int ret = 1;
    for (int i = 0; i < b; i++) {
        ret *= a;
    }
    return ret;
}

vector<int> number_plus_case(vector<int>& d) {
    vector<int> ret;
    int n = d.size();
    int total_cases = 1 << (n - 1);

    for (int mask = 0; mask < total_cases; ++mask) {
        int current_number = 0;
        int sum = 0;

        for (int i = 0; i < n; ++i) {
            current_number = current_number * 10 + d[i];

            if (mask & (1 << i) || i == n - 1) {
                sum += current_number;
                current_number = 0;
            }
        }

        ret.push_back(sum);
    }

    return ret;
}

int main() {
    init();
    int T;
    cin >> T;
    while (T--) {
        int n;
        cin >> n;
        vector<int> d = num2digit(n);

        vector<int> cases = number_plus_case(d);
        int m_count = 0;

        for (int m = 1; m <= 31; m++) {
            for (auto sum : cases) {
                int powered_sum = 0;
                for (auto digit : d) {
                    powered_sum += power(digit, m);
                }
                if (powered_sum == sum) {
                    m_count++;
                    break;
                }
            }
        }
        if (m_count == 31) {
            cout << "Hello, BOJ 2023!" << endl;
        } else {
            cout << m_count << endl;
        }
    }
    return 0;
}