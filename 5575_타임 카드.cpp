#include <iostream>
#include <vector>

using namespace std;

void init() {
    cin.tie(NULL);
    cout.tie(NULL);
    ios::sync_with_stdio(false);
}

int custom_pow(int a, int b) {
    int result = 1;
    while (b--) result *= a;
    return result;
}

int main() {
    init();
    vector<int> start_t(3);
    vector<int> end_t(3);

    for (int i = 0; i < 3; i++) {
        int time_s = 0;
        for (int i = 0; i < 3; i++) cin >> start_t[i];
        for (int i = 0; i < 3; i++) cin >> end_t[i];
        for (int i = 0; i < 3; i++) time_s += end_t[i] * custom_pow(60, 2 - i);
        for (int i = 0; i < 3; i++) time_s -= start_t[i] * custom_pow(60, 2 - i);

        cout << time_s / (60 * 60) << " ";
        time_s %= (60 * 60);
        cout << time_s / (60) << " ";
        time_s %= (60);
        cout << time_s << '\n';
    }

    return 0;
}