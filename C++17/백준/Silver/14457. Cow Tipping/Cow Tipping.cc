#include <iostream>

using namespace std;

typedef long long ll;

void init() {
    cin.tie(NULL);
    cout.tie(NULL);
    ios::sync_with_stdio(false);
}

int main() {
    init();
    int N;
    char arr[10][10];
    cin >> N;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cin >> arr[i][j];
        }
    }
    int tipping = 0;
    for (int i = N - 1; i >= 0; i--) {
        for (int j = N - 1; j >= 0; j--) {
            if (arr[i][j] == '1') {
                tipping++;
                for (int y = 0; y <= i; y++) {
                    for (int x = 0; x <= j; x++) {
                        arr[y][x] == '1' ? arr[y][x] = '0' : arr[y][x] = '1';
                    }
                }
            }
        }
    }
    cout << tipping << '\n';
    return 0;
}