#include <iostream>
#include <vector>

using namespace std;

int rectSum(const vector<vector<int>>& ps, int r, int c, int K) {
    int r1 = r + 1;
    int c1 = c + 1;
    int r2 = r + K;
    int c2 = c + K;
    return ps[r2][c2] - ps[r1 - 1][c2] - ps[r2][c1 - 1] + ps[r1 - 1][c1 - 1];
}

int main() {
    int ans = 1e9;
    int N, M, K;
    vector<vector<int>> board;
    /// predict
    vector<vector<int>> predW;
    vector<vector<int>> predB;
    /// missing
    vector<vector<int>> misW;
    vector<vector<int>> misB;
    /// presum
    vector<vector<int>> psW;
    vector<vector<int>> psB;

    cin >> N >> M >> K;
    board.assign(N, vector<int>(M));
    predW.assign(N, vector<int>(M));
    predB.assign(N, vector<int>(M));
    misW.assign(N, vector<int>(M, 0));
    misB.assign(N, vector<int>(M, 0));
    psW.assign(N + 1, vector<int>(M + 1, 0));
    psB.assign(N + 1, vector<int>(M + 1, 0));

    /// B = 1
    /// W = 0
    for (int r = 0; r < N; r++) {
        for (int c = 0; c < M; c++) {
            char chr;
            cin >> chr;

            if (chr == 'B')
                board[r][c] = 1;
            if (chr == 'W')
                board[r][c] = 0;

            predW[r][c] = (r + c) % 2;
            predB[r][c] = (r + c + 1) % 2;
        }
    }

    /// 예측된 보드와 다름을 나타내는 배열
    /// Black Start와 White Start에 대해 정상적인 패턴과 얼마나 다른지를 확인
    for (int r = 0; r < N; r++) {
        for (int c = 0; c < M; c++) {
            if (board[r][c] != predB[r][c]) {
                misB[r][c] = 1;
            }
            if (board[r][c] != predW[r][c]) {
                misW[r][c] = 1;
            }
        }
    }

    /// 2D 누적합(presum) 구하기
    /// : 누적합 없이 그냥 구하면 N^2의 시간복잡도가 걸리기 때문.
    /// : mis(n, n)에 누적합은 ps(n+1, n+1)에 저장.
    for (int r = 1; r <= N; r++) {
        for (int c = 1; c <= M; c++) {
            psW[r][c] = psW[r - 1][c] + psW[r][c - 1] - psW[r - 1][c - 1] + misW[r - 1][c - 1];
            psB[r][c] = psB[r - 1][c] + psB[r][c - 1] - psB[r - 1][c - 1] + misB[r - 1][c - 1];
        }
    }

    /// K x K 크기를 순회하면서 값 찾기
    for (int r = 0; r <= N - K; r++) {
        for (int c = 0; c <= M - K; c++) {
            int cnt1 = rectSum(psW, r, c, K);
            int cnt2 = rectSum(psB, r, c, K);

            ans = min(ans, min(cnt1, cnt2));
        }
    }
    printf("%d", ans);
}