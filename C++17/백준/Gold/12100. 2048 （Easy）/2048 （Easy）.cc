#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

typedef long long ll;
typedef vector<int> vec1;
typedef vector<vec1> vec2;
typedef vector<vec2> vec3;
int N;
int maxBlock = 0;

void init() {
    cin.tie(NULL);
    cout.tie(NULL);
    ios::sync_with_stdio(false);
}

void slide(vec1 &line) {
    vec1 newLine;
    int last = 0;

    for (int i = 0; i < line.size(); i++) {
        if (line[i] != 0) {  // 블록이 0이 아닌 경우 (빈 칸이 아닌 경우)
            if (last == line[i]) {
                newLine.back() *= 2;  // 마지막 블록과 현재 블록이 같으면 합침
                last = 0;             // 한번 합쳐진 블록은 다시 합쳐지지 않도록 last를 0으로 설정
            } else {
                newLine.push_back(line[i]);  // 같은 값이 아니라면 newLine에 추가
                last = line[i];              // last에 현재 블록 값을 저장
            }
        }
    }

    while (newLine.size() < line.size()) {
        newLine.push_back(0);
    }

    line = newLine;
}

void move(vec2 &board, int dir) {
    for (int i = 0; i < N; i++) {
        vec1 line;
        for (int j = 0; j < N; j++) {
            if (dir == 0)
                line.push_back(board[i][j]);  // left (1행 가져오기 ㅡ)
            else if (dir == 1)
                line.push_back(board[i][N - 1 - j]);  // right (1행 뒤집어서 가져오기 ㅡ)
            else if (dir == 2)
                line.push_back(board[j][i]);  // up (1열 가져오기 ㅣ)
            else if (dir == 3)
                line.push_back(board[N - 1 - j][i]);  // down (1열 뒤집어서 가져오기 ㅣ)
        }

        slide(line);

        for (int j = 0; j < N; j++) {
            if (dir == 0)
                board[i][j] = line[j];
            else if (dir == 1)
                board[i][N - 1 - j] = line[j];
            else if (dir == 2)
                board[j][i] = line[j];
            else if (dir == 3)
                board[N - 1 - j][i] = line[j];
        }
    }
}

void dfs(vec2 board, int count) {
    if (count == 5) {
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < N; j++) {
                maxBlock = max(maxBlock, board[i][j]);
            }
        }
        return;
    }

    for (int dir = 0; dir < 4; dir++) {
        vec2 newBoard = board;
        move(newBoard, dir);
        dfs(newBoard, count + 1);
    }
}
int main() {
    init();
    cin >> N;
    vec2 board(N, vec1(N));

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cin >> board[i][j];
        }
    }

    dfs(board, 0);

    cout << maxBlock << endl;
    return 0;
}