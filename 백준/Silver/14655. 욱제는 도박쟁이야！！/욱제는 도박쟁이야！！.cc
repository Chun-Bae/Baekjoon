#include <iostream>
#include <vector>
#define FOR(i, n) for (int i = 0; i < (n); i++)

using namespace std;

// 연속된 3개, 양 쪽 2개, 양 쪽 1개 뒤집기
// 여러 번 뒤집기 가능

int N;
int total = 0;

vector<vector<int>> stage;

int main() {
    cin >> N;
    stage.assign(2, vector<int>(N, 0));

    FOR(step, 2) {
        FOR(i, N) {
            cin >> stage[step][i];
            int t = stage[step][i];

            if (step == 0) {
                if (t > 0)
                    total += t;
                else
                    total += (-t);
            } else if (step == 1) {
                if (t <= 0)
                    total += (-t);
                else
                    total += t;
            }
        }
    }
    cout << total;

    // 애드 훅인가? 저 만큼의 조합이면,
    // 모든 걸 양수로 만들거나 음수로 만들 수 있을 거 같단 생각이 드는데

    return 0;
}
