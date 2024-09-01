#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

typedef long long ll;
typedef vector<char> vec1;
typedef vector<vec1> vec2;
typedef vector<vec2> vec3;

void init() {
    cin.tie(NULL);
    cout.tie(NULL);
    ios::sync_with_stdio(false);
}

void rStar(vec2& isStar, int x, int y, int depth, int N) {
    if (depth == N) {
        isStar[x][y] = '*';
        return;
    }

    int len = 1 << (N - depth - 1);
    rStar(isStar, x, y, depth + 1, N);
    rStar(isStar, x, y + len, depth + 1, N);
    rStar(isStar, x + len, y, depth + 1, N);
}

int main() {
    init();
    int N;
    cin >> N;

    int size = 1 << N;
    vec2 isStar(size, vec1(size, ' '));

    rStar(isStar, 0, 0, 0, N);

    for (int i = 0; i < size; ++i) {
        for (int j = 0; j < size - i; ++j) {
            cout << isStar[i][j];
        }
        cout << '\n';
    }

    return 0;
}
