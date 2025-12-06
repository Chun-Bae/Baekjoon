#include <iostream>
#include <vector>

using namespace std;

int main() {
    int H, W;
    cin >> H >> W;
    vector<vector<char>> cloud(H, vector<char>(W));

    for (int i = 0; i < H; i++) {
        for (int j = 0; j < W; j++) {
            cin >> cloud[i][j];
        }
    }

    for (int i = 0; i < H; i++) {
        int cnt = -1;
        for (int j = 0; j < W; j++) {
            if (cnt >= 0) {
                cnt++;
            }
            if (cloud[i][j] == 'c') {
                cnt = 0;
            }
            cout << cnt << " ";
        }
        cout << "\n";
    }
    return 0;
}