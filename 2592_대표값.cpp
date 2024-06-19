#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

int main() {
    int n, mode, avg = 0, max = 0;
    vector<pair<int, int>> mode_and_cnt;

    for (int i = 0; i < 10; i++) {
        cin >> n;
        avg += n;
        auto it = find_if(mode_and_cnt.begin(), mode_and_cnt.end(), [n](const pair<int, int>& element) { return element.first == n; });

        if (it != mode_and_cnt.end())
            it->second++;
        else
            mode_and_cnt.push_back(make_pair(n, 1));
    }

    avg /= 10;
    for (auto& mac : mode_and_cnt) {
        if (max < mac.second) {
            max = mac.second;
            mode = mac.first;
        }
    }

    cout << avg << endl << mode;
}