#include <algorithm>
#include <iostream>
#include <limits>
#include <vector>
using namespace std;

/// type r, c
///  [ ┐ ] [ ┘ ] [ └ ] [ ┌ ]
const int tr[4][3] = {{0, 1, 0}, {0, -1, 0}, {0, -1, 0}, {0, 1, 0}};
const int tc[4][3] = {{0, 0, -1}, {0, 0, -1}, {0, 0, 1}, {0, 0, 1}};

int N, M;
int max_intensity;
vector<vector<int>> woodboard;
vector<vector<bool>> visited;

/// 부메랑 모양이 가능한지 검증
bool is_possible(int r, int c, int type) {
    for (int v = 0; v < 3; v++) {
        int nr = r + tr[type][v];
        int nc = c + tc[type][v];

        if (nr < 0 || nr >= N ||
            nc < 0 || nc >= M ||
            visited[nr][nc]) {
            return false;
        }
    }
    return true;
}

/// 부메랑의 강도 계산
int calc_intensity(int r, int c, int type) {
    int total_intensity = 0;
    for (int v = 0; v < 3; v++) {
        int nr = r + tr[type][v];
        int nc = c + tc[type][v];

        if (v == 0)
            total_intensity += 2 * woodboard[nr][nc];
        else
            total_intensity += woodboard[nr][nc];
    }
    return total_intensity;
}

/// visited 토글
void toggle_visit(int r, int c, int type, bool flag) {
    for (int v = 0; v < 3; v++) {
        int nr = r + tr[type][v];
        int nc = c + tc[type][v];

        visited[nr][nc] = flag;
    }
}

void build_boomerang(int depth, int sum) {
    if (depth == N * M) {
        max_intensity = max(max_intensity, sum);
        return;
    }
    /// current r,c
    int cr = depth / M;
    int cc = depth % M;

    // 0 1 2 3 4 5
    // 0 0 -- 0
    // 0 1 -- 1
    // 0 2 -- 2
    // 1 0 -- 3
    // 1 1 -- 4
    // 1 2 -- 5

    /// 현재 칸이 사용 중 이라면 다음 칸으로 넘어가기
    if (visited[cr][cc]) {
        build_boomerang(depth + 1, sum);
        return;
    }

    /// 현재 칸을 사용하지 않는 경우도 고려
    /// 재귀 효과로 인해 여러 칸 뛰는 효과도 있음
    build_boomerang(depth + 1, sum);

    /// type
    /// 부메랑 강도 계산
    for (int t = 0; t < 4; t++) {
        if (is_possible(cr, cc, t)) {
            int score = calc_intensity(cr, cc, t);
            toggle_visit(cr, cc, t, true);
            /// 해당 부메랑 type에서,
            /// 다른 조합들을 backtraking을 통해
            /// 각 부메랑들의 세기를 가져온다.
            build_boomerang(depth + 1, sum + score);
            /// 원상 복구
            toggle_visit(cr, cc, t, false);
        }
    }
}

int main() {
    cin >> N >> M;
    woodboard.assign(N, vector<int>(M, 0));
    visited.assign(N, vector<bool>(M, false));
    max_intensity = 0;

    for (int r = 0; r < N; r++) {
        for (int c = 0; c < M; c++) {
            cin >> woodboard[r][c];
        }
    }
    build_boomerang(0, 0);
    cout << max_intensity;

    return 0;
}