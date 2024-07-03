#include <iostream>

using namespace std;

int tetromino[501][501];
int tetrominoShape[19][4][2] = {
    // | ㅡ
    {{0, 0}, {0, 1}, {0, 2}, {0, 3}},
    {{0, 0}, {1, 0}, {2, 0}, {3, 0}},
    // ㅁ
    {{0, 0}, {0, 1}, {1, 0}, {1, 1}},

    // ㅜ
    {{0, 0}, {0, 1}, {0, 2}, {1, 1}},
    {{0, 1}, {1, 0}, {1, 1}, {1, 2}},
    {{0, 0}, {1, 0}, {1, 1}, {2, 0}},
    {{0, 1}, {1, 0}, {1, 1}, {2, 1}},

    // ┘ (가로가 긴)
    {{0, 0}, {1, 0}, {2, 0}, {2, 1}},
    // 시계 90도 회전
    {{0, 0}, {0, 1}, {0, 2}, {1, 0}},
    // 시계 180도 회전
    {{0, 0}, {0, 1}, {1, 1}, {2, 1}},
    // 시계 270도 회전    
    {{0, 2}, {1, 0}, {1, 1}, {1, 2}},

    // ┐ (가로가 긴)
    {{0, 1}, {1, 1}, {2, 0}, {2, 1}},
    // ┐ 시계 90도 회전
    {{0, 0}, {1, 0}, {1, 1}, {1, 2}},
    // ┐ 시계 180도 회전
    {{0, 0}, {0, 1}, {1, 0}, {2, 0}},
    // ┐ 시계 270도 회전
    {{0, 0}, {0, 1}, {0, 2}, {1, 2}},

    // └┐
    {{0, 1}, {0, 2}, {1, 0}, {1, 1}},
    // └┐ 시계 90도 회전
    {{0, 0}, {1, 0}, {1, 1}, {2, 1}},

    // ┌┘
    {{0, 0}, {0, 1}, {1, 1}, {1, 2}},
    // ┌┘ 시계 90도 회전
    {{0, 1}, {1, 0}, {1, 1}, {2, 0}}};

void init() {
    cin.tie(NULL);
    cout.tie(NULL);
    ios::sync_with_stdio(false);
}

int main() {
    init();
    int N, M;
    int maxSum = 0;
    cin >> N >> M;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            cin >> tetromino[i][j];
        }
    }

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            for (int t = 0; t < 19; t++) {
                int currentSum = 0;
                bool isValid = true;
                for (int k = 0; k < 4; k++) {
                    int x = i + tetrominoShape[t][k][0];
                    int y = j + tetrominoShape[t][k][1];
                    if (x >= 0 && x < N && y >= 0 && y < M) {
                        currentSum += tetromino[x][y];
                    } else {
                        isValid = false;
                        break;
                    }
                }
                if (isValid) {
                    maxSum = max(maxSum, currentSum);
                }
            }
        }
    }

    cout << maxSum << endl;

    return 0;
}