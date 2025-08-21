#include <iostream>
#include <vector>
using namespace std;

int main() {
    int N, L;
    int count = 0;
    vector<vector<int>> mat;

    cin >> N >> L;
    // 지도에 정보 넣기
    for (int r = 0; r < N; r++) {
        vector<int> row;
        for (int c = 0; c < N; c++) {
            int square;
            cin >> square;
            row.push_back(square);
        }
        mat.push_back(row);
    }

    int step = 2 * N;
    // 총 길 개수 만큼 확인하기 위한 작업
    for (int s = 0; s < step; s++) {
        // 가로, 세로 각각 길을 확인하기 위해서 분기문으로 나눈 거임.
        vector<int> load;
        vector<int> ramps(N, 0);
        if (s < N) {
            for (int i = 0; i < N; i++) {
                load.push_back(mat[s % N][i]);
            }
        } else {
            for (int i = 0; i < N; i++) {
                load.push_back(mat[i][s % N]);
            }
        }

        // 여기다가 알고리즘
        bool isBlocked = 0;
        int idx = 0;
        for (auto it = load.begin(); it != load.end() - 1; it++, idx++) {
            // 다음 칸이 높은 칸인 경우:
            if (*(it + 1) == *(it) + 1) {
                int i = 0;
                for (; i < L; i++) {
                    // 이미 경사로가 깔린 경우
                    if (ramps[idx - i] == 1) {
                        isBlocked = true;
                        break;
                    }
                    // 범위 바깥
                    if (idx - i < 0) {
                        isBlocked = true;
                        break;
                    }
                    // L개 만큼 있는지 체크.
                    if (*(it - i) == *(it)) {
                        continue;
                    } else {
                        isBlocked = true;
                        break;
                    }
                }
                // 경사로 설치 확인
                if (i == L) {
                    for (int j = 0; j < L; j++) {
                        ramps[idx - j] = 1;
                    }
                }
            }
            // 다음 칸이 낮은 칸인 경우:
            else if (*(it + 1) == *(it)-1) {
                int i = 1;
                for (; i < L + 1; i++) {
                    // 이미 경사로가 깔린 경우
                    if (ramps[idx + i] == 1) {
                        isBlocked = true;
                        break;
                    }
                    // 범위 바깥
                    if (idx + i > N) {
                        isBlocked = true;
                        break;
                    }
                    // L개 만큼 있는지 체크.
                    if (*(it + i) == *(it + 1)) {
                        continue;
                    } else {
                        isBlocked = true;
                        break;
                    }
                }
                // 경사로 설치 확인
                if (i == L + 1) {
                    for (int j = 1; j < L + 1; j++) {
                        ramps[idx + j] = 1;
                    }
                }
            }
            // 다음 칸이 같은 경우:
            else if (*(it + 1) == *(it)) {
                continue;
            } else {
                isBlocked = true;
                break;
            }
        }
        if (isBlocked == false) {
            count++;
            // cout << s << "\n";
        }
    }
    cout << count;
    return 0;
}