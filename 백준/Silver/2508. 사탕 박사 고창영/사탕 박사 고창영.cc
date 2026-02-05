#include <iostream>
#include <vector>

using namespace std;

int t;
int R, C;
int total;
vector<vector<char>> box;

void check_candy(int cr, int cc) {
    if (!(cr - 1 < 0) && box[cr - 1][cc] == 'v') {
        if (!(cr + 1 >= R) && box[cr + 1][cc] == '^') {
            total++;
        }
    }
    if (!(cc - 1 < 0) && box[cr][cc - 1] == '>') {
        if (!(cc + 1 >= C) && box[cr][cc + 1] == '<') {
            total++;
        }
    }
}

int main() {
    cin >> t;

    while (t--) {
        cin >> R >> C;
        total = 0;
        box.assign(R, vector<char>(C, '0'));

        for (int r = 0; r < R; r++) {
            for (int c = 0; c < C; c++) {
                cin >> box[r][c];
            }
        }

        for (int r = 0; r < R; r++) {
            for (int c = 0; c < C; c++) {
                if (box[r][c] == 'o') {
                    check_candy(r, c);
                }
            }
        }

        printf("%d\n", total);
    }

    return 0;
}