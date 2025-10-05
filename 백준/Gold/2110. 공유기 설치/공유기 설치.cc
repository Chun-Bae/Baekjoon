#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

int main() {
    int N, C;
    cin >> N >> C;
    vector<int> router(N);
    for (int i = 0; i < N; i++)
        cin >> router[i];

    sort(router.begin(), router.end());

    int left = 1;
    int right = router[N - 1] - router[0];
    int result = 0;
    while (left <= right) {
        int d = (left + right) / 2;
        int cnt = 1;
        int last = router[0];

        for (int i = 1; i < N; i++) {
            if (router[i] - last >= d) {
                last = router[i];
                cnt++;
            }
        }

        if (cnt >= C) {
            left = d + 1;
            result = d;
        } else {
            right = d - 1;
        }
    }
    cout << result;

    return 0;
}