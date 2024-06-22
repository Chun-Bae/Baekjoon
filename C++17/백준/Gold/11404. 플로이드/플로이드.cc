#include <iostream>
#include <vector>

#define INF 1e9

using namespace std;

void init() {
    cin.tie(NULL);
    cout.tie(NULL);
    ios::sync_with_stdio(false);
}

int main() {
    init();
    int n, m;
    cin >> n >> m;
    vector<vector<int>> bus(n + 1, vector<int>(n + 1, INF));

    for (int i = 1; i <= n; i++) {
        bus[i][i] = 0;
    }

    for (int i = 0; i < m; i++) {
        int a, b, c;
        cin >> a >> b >> c;
        if (bus[a][b] > c) {
            bus[a][b] = c;
        }
    }

    for (int k = 1; k <= n; k++) {
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= n; j++) {
                if (bus[i][j] > bus[i][k] + bus[k][j]) {
                    bus[i][j] = bus[i][k] + bus[k][j];
                }
            }
        }
    }

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            if (bus[i][j] == INF) {
                cout << 0 << " ";
            } else {
                cout << bus[i][j] << " ";
            }
        }
        cout << "\n";
    }

    return 0;
}
