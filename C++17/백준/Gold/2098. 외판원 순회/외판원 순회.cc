#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

typedef long long ll;
typedef vector<int> vec1;
typedef vector<vec1> vec2;

const int INF = 987654321;

int n;
vec2 cities;
vec2 salesmans;

void init() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
}

int dfs(int cur, int bitmask) {
    if (bitmask == (1 << n) - 1) {
        return (cities[cur][0] != 0) ? cities[cur][0] : INF;
    }

    if (salesmans[cur][bitmask] != -1) return salesmans[cur][bitmask];

    salesmans[cur][bitmask] = INF;

    for (int i = 0; i < n; i++) {
        if (cities[cur][i] == 0) continue;
        if (bitmask & (1 << i)) continue;
        salesmans[cur][bitmask] = min(salesmans[cur][bitmask], cities[cur][i] + dfs(i, bitmask | (1 << i)));
    }

    return salesmans[cur][bitmask];
}

int main() {
    init();

    cin >> n;
    cities.resize(n, vec1(n));
    salesmans.resize(n, vec1(1 << n, -1));

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> cities[i][j];
        }
    }

    cout << dfs(0, 1) << endl;

    return 0;
}
