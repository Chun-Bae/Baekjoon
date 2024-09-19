#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

typedef long long ll;
typedef vector<int> vec1;
typedef vector<vec1> vec2;
typedef vector<vec2> vec3;

void init() {
    cin.tie(NULL);
    cout.tie(NULL);
    ios::sync_with_stdio(false);
}

int main() {
    init();
    int N, M;
    cin >> N >> M;
    vec2 matrix1(N, vec1(M));
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            cin >> matrix1[i][j];
        }
    }
    int m, K;
    cin >> m >> K;
    vec2 matrix2(M, vec1(K));
    for (int i = 0; i < M; i++) {
        for (int j = 0; j < K; j++) {
            cin >> matrix2[i][j];
        }
    }

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < K; j++) {
            int sum = 0;
            for (int k = 0; k < M; k++) {
                sum += matrix1[i][k] * matrix2[k][j];
            }
            cout << sum << ' ';
        }
        cout << '\n';
    }

    return 0;
}