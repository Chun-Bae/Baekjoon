#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

vector<vector<int>> adj;
vector<int> candy;
vector<bool> visited;
int n, m, k;

pair<int, int> dfs(int node) {
    visited[node] = true;
    int size = 1;
    int candies = candy[node];

    for (int neighbor : adj[node]) {
        if (!visited[neighbor]) {
            pair<int, int> res = dfs(neighbor);
            size += res.first;
            candies += res.second;
        }
    }

    return {size, candies};
}

void init() {
    cin.tie(NULL);
    cout.tie(NULL);
    ios::sync_with_stdio(false);
}

int main() {
    init();
    cin >> n >> m >> k;
    adj.resize(n + 1);
    candy.resize(n + 1);
    visited.resize(n + 1, false);

    for (int i = 1; i <= n; ++i) {
        cin >> candy[i];
    }

    for (int i = 0, a, b; i < m; ++i) {
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    vector<pair<int, int>> groups;
    for (int i = 1; i <= n; ++i) {
        if (!visited[i]) {
            groups.push_back(dfs(i));
        }
    }

    vector<int> dp(k, 0);

    for (auto &group : groups) {
        int size = group.first;
        int candies = group.second;
        if (size < k) {
            for (int i = k - 1; i >= size; --i) {
                // if k=6 size=3
                // dp[5] = max(dp[5], dp[2] + candies);
                // dp[4] = max(dp[4], dp[1] + candies);
                // dp[3] = max(dp[3], dp[0] + candies);
                // 사이즈가 3인 그룹을 선택했을 때, 다른 그룹과 더해도 k를 넘지 않는 경우를 모두 계산
                dp[i] = max(dp[i], dp[i - size] + candies);
            }
        }
    }

    cout << *max_element(dp.begin(), dp.end()) << endl;

    return 0;
}
