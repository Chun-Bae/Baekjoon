#include <iostream>
#define LOGSCAYLE 19
using namespace std;

int scarse[200001][LOGSCAYLE];

void init() {
    cin.tie(NULL);
    cout.tie(NULL);
    ios::sync_with_stdio(false);
}

int main() {
    init();
    int m, q;
    cin >> m;

    for (int i = 1; i <= m; i++) cin >> scarse[i][0];

    for (int i = 1; i < LOGSCAYLE; i++) {
        for (int j = 0; j <= m; j++) {
            scarse[j][i] = scarse[scarse[j][i - 1]][i - 1];
        }
    }
    // for (int i = 1; i <= m; i++) {
    //     for (int j = 0; j < LOGSCAYLE; j++) {
    //         cout << scarse[i][j]<<" ";
    //     }
    //     cout<<endl;
    // }

    cin >> q;
    while (q--) {
        int n, x, log = 0;
        cin >> n >> x;
        while (n > 0) {
            if (n % 2) {  // 1이면 로그테이블 값
                x = scarse[x][log];
            }
            n >>= 1;
            log++;
        }
        cout << x << '\n';
    }
}