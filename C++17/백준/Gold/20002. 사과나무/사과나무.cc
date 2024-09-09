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
    int N;
    cin >> N;

    vec2 orchard(N, vec1(N));
    vec2 prefix_sum(N + 1, vec1(N + 1, 0));

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cin >> orchard[i][j];
        }
    }

    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= N; j++) {
            prefix_sum[i][j] = orchard[i - 1][j - 1] + prefix_sum[i - 1][j] + prefix_sum[i][j - 1] - prefix_sum[i - 1][j - 1];
        }
    }

    int max_profit = -1001;

    for (int k = 1; k <= N; k++) {
        for (int i = k; i <= N; i++) {
            for (int j = k; j <= N; j++) {
                int total_profit = prefix_sum[i][j] - prefix_sum[i - k][j] - prefix_sum[i][j - k] + prefix_sum[i - k][j - k];
                max_profit = max(max_profit, total_profit);
            }
        }
    }

    cout << max_profit << endl;
    return 0;
}