#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

int main() {
    int N, d, reward, double_check, max_dice, max_reward = 0;
    cin >> N;
    for (int i = 0; i < N; i++) {
        vector<int> dice(6, 0);
        vector<int> double_idx(2);
        double_check = 0;
        max_dice = 0;
        for (int j = 0; j < 4; j++) {
            cin >> d;
            dice[d - 1]++;
            if (max_dice < d) max_dice = d;
        }
        for (int j = 0; j < 6; j++) {
            if (dice[j] == 4) {
                reward = 50000 + (j + 1) * 5000;
                double_check = -1;
                break;
            } else if (dice[j] == 3) {
                reward = 10000 + (j + 1) * 1000;
                double_check = -1;
                break;
            } else if (dice[j] == 2) {
                double_idx[double_check++] = (j + 1);
            };
        }

        if (double_check == 2) {
            reward = 2000 + double_idx[0] * 500 + double_idx[1] * 500;
        } else if (double_check == 1) {
            reward = 1000 + double_idx[0] * 100;
        } else if (double_check == 0) {
            reward = max_dice * 100;
        }

        if (max_reward < reward) max_reward = reward;
    }
    cout << max_reward << endl;
    return 0;
}