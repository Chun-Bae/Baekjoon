#include <algorithm>
#include <climits>
#include <iostream>
#include <vector>

using namespace std;
typedef vector<int> vec1;
typedef vector<vector<int>> vec2;
typedef vector<vector<vector<int>>> vec3;

int cost(int from, int to) {
    if (from == to) return 1;
    if (from == 0) return 2;
    if ((from == 1 && to == 3) || (from == 3 && to == 1)) return 4;
    if ((from == 2 && to == 4) || (from == 4 && to == 2)) return 4;
    return 3;
}

void init() {
    cin.tie(NULL);
    cout.tie(NULL);
    ios::sync_with_stdio(false);
}

int main() {
    init();
    vec1 ddr;
    int n;
    while (cin >> n && n != 0) {
        ddr.push_back(n);
    }

    int len = ddr.size();
    // 모든 조합 * 길이
    vec3 step(len + 1, vec2(5, vec1(5, INT_MAX)));

    step[0][0][0] = 0;

    for (int i = 0; i < len; ++i) {
        int next = ddr[i];
        for (int l = 0; l < 5; ++l) {
            for (int r = 0; r < 5; ++r) {
                if (step[i][l][r] != INT_MAX) {
                    // 왼발
                    step[i + 1][next][r] = min(step[i + 1][next][r], step[i][l][r] + cost(l, next));
                    // 오른발
                    step[i + 1][l][next] = min(step[i + 1][l][next], step[i][l][r] + cost(r, next));
                }
            }
        }
    }

    int result = INT_MAX;
    for (int l = 0; l < 5; ++l) {
        for (int r = 0; r < 5; ++r) {
            result = min(result, step[len][l][r]);
        }
    }

    cout << result << endl;

    return 0;
}
