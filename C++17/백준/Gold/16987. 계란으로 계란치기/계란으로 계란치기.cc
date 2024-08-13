#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

int N;
vector<pair<int, int>> eggs;  // 내구도, 무게
int maxBroken = 0;

void dfs(int idx) {
    if (idx == N) {
        int brokenCount = 0;
        for (int i = 0; i < N; i++) {
            if (eggs[i].first <= 0) brokenCount++;
        }
        maxBroken = max(maxBroken, brokenCount);
        return;
    }

    if (eggs[idx].first <= 0) {
        dfs(idx + 1);
        return;
    }

    bool allBroken = true;
    for (int i = 0; i < N; i++) {
        if (i == idx || eggs[i].first <= 0) continue;
        allBroken = false;

        // 1로 2치고 3치는 거랑, 1로 3치고 2치는 거랑 다름. 원상복구 이유

        // 현재 계란과 i번째 계란의 충돌 처리
        eggs[idx].first -= eggs[i].second;
        eggs[i].first -= eggs[idx].second;

        dfs(idx + 1);

        // 원상 복구
        eggs[idx].first += eggs[i].second;
        eggs[i].first += eggs[idx].second;
    }

    if (allBroken) {
        dfs(idx + 1);
    }
}

void init() {
    cin.tie(NULL);
    cout.tie(NULL);
    ios::sync_with_stdio(false);
}

int main() {
    init();
    cin >> N;
    eggs.resize(N);
    for (int i = 0; i < N; i++) {
        cin >> eggs[i].first >> eggs[i].second;
    }

    dfs(0);

    cout << maxBroken << endl;
    return 0;
}
