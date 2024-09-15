#include <algorithm>
#include <climits>
#include <iostream>
#include <set>
#include <vector>

using namespace std;

typedef long long ll;
typedef vector<ll> vec1;
typedef vector<vec1> vec2;
typedef vector<vec2> vec3;
int N;
vector<vector<char>> grid;
vector<vector<set<ll>>> dp;

ll calc(ll a, char op, ll b) {
    if (op == '+') return a + b;
    if (op == '-') return a - b;
    if (op == '*') return a * b;
    return 0;
}

void init() {
    cin.tie(NULL);
    cout.tie(NULL);
    ios::sync_with_stdio(false);
}

int main() {
    init();
    cin >> N;
    grid.assign(N, vector<char>(N));
    dp.assign(N, vector<set<ll>>(N));

    for (int i = 0; i < N; ++i)
        for (int j = 0; j < N; ++j) cin >> grid[i][j];

    dp[0][0].insert(grid[0][0] - '0');

    int dx[] = {0, 1};
    int dy[] = {1, 0};

    for (int x = 0; x < N; ++x) {
        for (int y = 0; y < N; ++y) {
            if ((x + y) % 2 == 0) {
                for (ll val : dp[x][y]) {
                    for (int dir = 0; dir < 2; ++dir) {
                        int nx = x + dx[dir];
                        int ny = y + dy[dir];
                        if (nx >= N || ny >= N) continue;
                        if ((nx + ny) % 2 == 1) { 
                            char op = grid[nx][ny];
                            for (int ndir = 0; ndir < 2; ++ndir) {
                                int nnx = nx + dx[ndir];
                                int nny = ny + dy[ndir];
                                if (nnx >= N || nny >= N) continue;
                                if ((nnx + nny) % 2 == 0) {
                                    ll num = grid[nnx][nny] - '0';
                                    ll next_val = calc(val, op, num);
                                    dp[nnx][nny].insert(next_val);
                                }
                            }
                        }
                    }
                }
            }
        }
    }

    ll max_result = LLONG_MIN;
    ll min_result = LLONG_MAX;
    for (ll val : dp[N - 1][N - 1]) {
        if (val > max_result) max_result = val;
        if (val < min_result) min_result = val;
    }

    cout << max_result << " " << min_result << endl;
    return 0;
}