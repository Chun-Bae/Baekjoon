#include <iostream>
#include <vector>

using namespace std;

int main() {
    int N, k;
    cin >> N >> k;

    vector<int> program(k);
    for (int i = 0; i < k; i++) cin >> program[i];

    // 모든 전등이 켜진 상태에서 시작 (true = on)
    vector<bool> ville(N + 1, true);
    int cur_on = N;        // 현재 켜져 있는 개수
    int max_off = 0;       // 동시에 꺼져 있는 개수의 최댓값

    for (int idx = 0; idx < k; idx++) {
        int step = program[idx];

        // step의 배수마다 toggle
        for (int t = step; t <= N; t += step) {
            if (ville[t]) {
                // 켜져 있던 걸 끄는 경우
                ville[t] = false;
                cur_on--;
            } else {
                // 꺼져 있던 걸 켜는 경우
                ville[t] = true;
                cur_on++;
            }
        }

        int cur_off = N - cur_on;      // 지금 꺼져 있는 전등의 개수
        if (cur_off > max_off) max_off = cur_off;
    }

    cout << max_off;

    return 0;
}