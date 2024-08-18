#include <algorithm>
#include <iostream>
#include <vector>
#include <cmath>
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
    cin >> N;
    vector<int> v(8001, 0);  // 0 = -4000,1= -3999, ... , 3999 = -1, ... ,4000 = 0, 4001 = 1, ... 8000 = 4000

    double total = 0;
    int maxV = -4000;
    int minV = 4000;
    vector<pair<int, int>> mode;
    vector<int> exist;
    for (int i = 0; i < N; i++) {
        int num;
        cin >> num;
        v[num + 4000]++;
        // 평균용 총합
        total += (double)num;
        // 최대최소
        if (num > maxV) maxV = num;
        if (num < minV) minV = num;
        // 중앙값용
        exist.push_back(num);
        // 최빈값용
        if (mode.empty()) {
            mode.push_back({num, v[num + 4000]});
        } else {
            for (auto m : mode) {
                if (m.second < v[num + 4000]) {
                    mode.clear();
                    mode.push_back({num, v[num + 4000]});
                    break;
                } else if (m.second == v[num + 4000]) {
                    mode.push_back({num, v[num + 4000]});
                    break;
                }
            }
        }
    }
    sort(exist.begin(), exist.end());
    sort(mode.begin(), mode.end(), [](pair<int, int> a, pair<int, int> b) {
        if (a.second == b.second) {
            return a.first < b.first;
        }
        return a.second > b.second;
    });

    cout << int(round(total / (double)N)) << '\n';
    cout << exist[N / 2] << '\n';
    if (mode.size() > 1 && mode[0].second == mode[1].second) {
        cout << mode[1].first << '\n';
    } else {
        cout << mode[0].first << '\n';
    }
    cout << exist[N - 1] - exist[0] << '\n';

    return 0;
}