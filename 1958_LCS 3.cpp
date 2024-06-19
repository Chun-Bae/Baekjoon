#include <iostream>

using namespace std;

typedef long long ll;

int dp[101][101][101];

void init() {
    cin.tie(NULL);
    cout.tie(NULL);
    ios::sync_with_stdio(false);
}

int main() {
    init();
    string _1, _2, _3;
    cin >> _1 >> _2 >> _3;

    for (int i = 0; i <= _3.size(); i++) {
        // cout << "dimension" << endl;
        for (int j = 0; j <= _2.size(); j++) {
            for (int k = 0; k <= _1.size(); k++) {
                if (i && j && k) {
                    if (_3[i - 1] == _2[j - 1] && _1[k - 1] == _2[j - 1] && _3[i - 1] == _1[k - 1]) {
                        dp[i][j][k] = dp[i - 1][j - 1][k - 1] + 1;
                        // cout << "why: " << _3[i] << " " << _2[j] << " " << _1[k] << endl;
                    } else {
                        int t1, t2, t3;
                        t1 = dp[i][j][k - 1];
                        t2 = dp[i][j - 1][k];
                        t3 = dp[i - 1][j][k];
                        dp[i][j][k] = max(max(t1, t2), t3);
                    }
                }

                // cout << dp[i][j][k] << "   ";
            }
            // cout << endl;
        }
    }
    cout << dp[_3.size()][_2.size()][_1.size()] ? dp[_3.size()][_2.size()][_1.size()] : 0 << '\n';
    return 0;
}