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
    int T;
    cin >> T;
    while (T--) {
        int H, W, N;
        cin >> H >> W >> N;
        int floor = N % H;
        int room = N / H + 1;
        // 꼭대기층일 경우
        if (floor == 0) {
            floor = H;
            room -= 1;
        }
        cout << floor * 100 + room << '\n';
    }
    return 0;
}