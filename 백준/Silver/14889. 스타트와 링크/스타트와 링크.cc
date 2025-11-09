#include <algorithm>
#include <iostream>
#include <vector>
#define INF 1e9

using namespace std;

int N;
int min_diff = INF;
vector<vector<int>> S;
vector<vector<int>> P;
vector<int> visited;

void calc_diff() {
    int start_sum = 0;
    int link_sum = 0;

    for (int i = 1; i <= N; i++) {
        for (int j = i + 1; j <= N; j++) {
            if (visited[i] && visited[j]) {
                start_sum += (S[i][j] + S[j][i]);

            } else if (!visited[i] && !visited[j]) {
                link_sum += (S[i][j] + S[j][i]);
            }
        }
    }
    min_diff = min(min_diff, abs(start_sum - link_sum));
}

void dfs(int k, int cnt) {
    if (cnt == N / 2) {
        calc_diff();
        // for (int i = 1; i <= N; i++) {
        //     printf("%d ", visited[i]);
        // }
        // printf("\n");
        return;
    }

    for (int i = k; i <= N; i++) {
        if (!visited[i]) {
            visited[i] = 1;
            dfs(i + 1, cnt + 1);
            visited[i] = 0;
        }
    }
}

int main() {
    cin >> N;
    S.assign(N + 1, vector<int>(N + 1, 0));
    visited.assign(N + 1, 0);
    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= N; j++) {
            cin >> S[i][j];
        }
    }
    visited[1] = 1;
    dfs(1, 1);
    cout << min_diff;
}

// 만약 N이 6이면,
// team1 = S_12 + S_21 + S_23 + S_32 + S_13 + S_31
// team2 = S_45 + S_54 + S_56 + S_65 + S_46 + S_64
// 근데, 이 조합이 아니라 이런식으로의 조합에서 차이가 최소값이 되는 조합 찾기
