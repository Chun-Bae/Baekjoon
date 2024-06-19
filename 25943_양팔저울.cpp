#include <iostream>

using namespace std;

void init() {
    cin.tie(NULL);
    cout.tie(NULL);
    ios::sync_with_stdio(false);
}

int main() {
    init();
    int T, n;
    int left = 0;
    int right = 0;
    cin >> T;
    for (int i = 0; i < T; i++) {
        cin >> n;
        if (i == 0)
            left += n;
        else if (i == 1)
            right += n;
        else if (left == right)
            left += n;
        else if (left - right > 0)
            right += n;
        else if (left - right < 0)
            left += n;
        
    }
    int diff = abs(left - right);
    
    int cnt = 0;

    if (diff / 100) {
        cnt += diff / 100;
        diff %= 100;
    }
    if (diff / 50) {
        cnt += diff / 50;
        diff %= 50;
    }
    if (diff / 20) {
        cnt += diff / 20;
        diff %= 20;
    }
    if (diff / 10) {
        cnt += diff / 10;
        diff %= 10;
    }
    if (diff / 5) {
        cnt += diff / 5;
        diff %= 5;
    }
    if (diff / 2) {
        cnt += diff / 2;
        diff %= 2;
    }
    cnt += diff;

    cout << cnt;

    return 0;
}