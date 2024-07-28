#include <iostream>
#include <vector>
using namespace std;

void init() {
    cin.tie(NULL);
    cout.tie(NULL);
    ios::sync_with_stdio(false);
}

int main() {
    init();
    int N, M;
    cin >> N >> M;
    vector<vector<char>> crosswords(N, vector<char>(M));
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            cin >> crosswords[i][j];
        }
    }

    int count = 0;
    vector<pair<int, int>> coordinates;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            if (crosswords[i][j] == '.') {
                bool width = false;
                bool height = false;

                // 가로
                if (j == 0 || crosswords[i][j - 1] == '#') {
                    if (j <= M - 3 && crosswords[i][j + 1] == '.' && crosswords[i][j + 2] == '.') {
                        width = true;
                    }
                }

                // 세로
                if (i == 0 || crosswords[i - 1][j] == '#') {
                    if (i <= N - 3 && crosswords[i + 1][j] == '.' && crosswords[i + 2][j] == '.') {
                        height = true;
                    }
                }

                if (width || height) {
                    count++;
                    coordinates.push_back({i + 1, j + 1});
                }
            }
        }
    }

    cout << count << "\n";
    for (int i = 0; i < count; i++) {
        cout << coordinates[i].first << " " << coordinates[i].second << "\n";
    }
    return 0;
}
