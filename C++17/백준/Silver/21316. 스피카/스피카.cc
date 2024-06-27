#include <iostream>

using namespace std;

typedef long long ll;

int starEdge[13];
int star[13][13];

void init() {
    cin.tie(NULL);
    cout.tie(NULL);
    ios::sync_with_stdio(false);
}

int main() {
    init();
    for (int i = 1; i <= 12; i++) {
        int a, b;
        cin >> a >> b;
        star[a][b] = 1;
        star[b][a] = 1;
        starEdge[a]++;
        starEdge[b]++;
    }
    for (int i = 1; i <= 12; i++) {
        bool flag1 = false, flag2 = false, flag3 = false;
        if (starEdge[i] == 3) {
            for (int j = 1; j <= 12; j++) {
                // i==3
                if (star[i][j] && starEdge[j] == 1)
                    flag1 = true;
                else if (star[i][j] && starEdge[j] == 2)
                    flag2 = true;
                else if (star[i][j] && starEdge[j] == 3)
                    flag3 = true;
            }
            if (flag1 && flag2 && flag3) {
                cout << i << "\n";
                return 0;
            }
        }
    }

    return 0;
}