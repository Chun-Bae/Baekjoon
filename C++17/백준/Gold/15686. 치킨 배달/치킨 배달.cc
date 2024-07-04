#include <algorithm>
#include <iostream>
#include <vector>
#define MAX 987654321

using namespace std;

int N, M;
vector<vector<int>> street;
vector<pair<int, int>> houses;
vector<pair<int, int>> chickenHouses;

int total_dist(vector<pair<int, int>>& selectedChicken) {
    int totalDist = 0;
    for (const auto& house : houses) {
        int minDist = MAX;
        for (const auto& chicken : selectedChicken) {
            int distance = abs(house.first - chicken.first) + abs(house.second - chicken.second);
            minDist = min(minDist, distance);
        }
        totalDist += minDist;
    }
    return totalDist;
}

void init() {
    cin.tie(NULL);
    cout.tie(NULL);
    ios::sync_with_stdio(false);
}

int main() {
    init();
    cin >> N >> M;
    street.resize(N, vector<int>(N));
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < N; ++j) {
            cin >> street[i][j];
            if (street[i][j] == 1) {
                houses.push_back({i, j});
            } else if (street[i][j] == 2) {
                chickenHouses.push_back({i, j});
            }
        }
    }
    vector<int> selection(chickenHouses.size(), 0);
    // 5개의 치킨집 중 3개를 선택하는 경우
    // 0 0 0 1 1
    fill(selection.end() - M, selection.end(), 1);

    int minDist = MAX;
    do {
        vector<pair<int, int>> selectedChicken;
        for (int i = 0; i < selection.size(); ++i) {
            if (selection[i] == 1) {
                selectedChicken.push_back(chickenHouses[i]);
            }
        }
        int curDist = total_dist(selectedChicken);
        minDist = min(minDist, curDist);
        // 다음 순열
    } while (next_permutation(selection.begin(), selection.end()));
    cout << minDist << endl;

    return 0;
}