#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

int main() {
    vector<int> stair;
    vector<int> max_stairs;
    int T;
    cin >> T;
    max_stairs.resize(T + 1, 0);
    stair.resize(T + 1, 0);
    for (int i = 1; i <= T; i++)
        cin >> stair[i];

    max_stairs[1] = stair[1];
    max_stairs[2] = stair[1] + stair[2];
    max_stairs[3] = max(stair[1] + stair[3], stair[2] + stair[3]);

    for (int i = 4; i <= T; i++) {
        /// x1: 현재 밟은 게 2칸 뛰어서 한 번에 온건지,
        /// x2: 현재 밟은 게 이전에 밟고 온건지, -> 조건1에 위배되는 경우를
        ///     남기지 않기 위해 그 이전에 2칸(i-3) 밟고 i-1을 밟은 걸로 확신해줌.
        int x1 = max_stairs[i - 2] + stair[i];
        int x2 = max_stairs[i - 3] + stair[i - 1] + stair[i];
        max_stairs[i] = max(x1, x2);
    }
    cout<<max_stairs[T];
    return 0;
}