#include <iostream>
#include <vector>
#include <iomanip>
#include <string>
#include <sstream>

using namespace std;

typedef long long ll;

int getDiceSides(string dice) {
    return stoi(dice.substr(1));
}

void init(){
    cin.tie(NULL);
    cout.tie(NULL);
    ios::sync_with_stdio(false);
}


int main() {
    init();
    string input;
    while (getline(cin, input)) {
        if (input == "0") break;

        stringstream ss(input);
        int d, x;
        ss >> d;

        vector<int> sides(d);
        for (int i = 0; i < d; i++) {
            string dice;
            ss >> dice;
            sides[i] = getDiceSides(dice);
        }

        ss >> x;

        vector<ll> dp(1001, 0);
        dp[0] = 1;
        // 주사위 개수 만큼
        for (int i = 0; i < d; i++) {

            vector<ll> new_dp(1001, 0);
            for (int j = 0; j <= 1000; j++) {
                if (dp[j] > 0) {
                    // d4 면 4번 반복
                    for (int k = 1; k <= sides[i]; k++) {
                        if (j + k <= 1000) {
                            new_dp[j + k] += dp[j];
                        }
                    }
                }
            }
            dp = new_dp;
        }

        ll total_outcomes = 1;
        // 주사위 면수 곱하기: 모든 경우의 수
        for (int i = 0; i < d; i++) {
            total_outcomes *= sides[i];
        }

        double probability = 0.0;
        if (x <= 1000) {
            probability = static_cast<double>(dp[x]) / total_outcomes;
        }

        cout << fixed << setprecision(5) << probability << endl;
    }

    return 0;
}
