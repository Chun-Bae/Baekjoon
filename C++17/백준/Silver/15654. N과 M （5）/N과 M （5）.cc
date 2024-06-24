#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

typedef long long ll;
vector<int> arr;
vector<int> current;
vector<int> visited;

void init() {
    cin.tie(NULL);
    cout.tie(NULL);
    ios::sync_with_stdio(false);
}

void printResult(int M, int cnt) {
    if (cnt == M) {
        for (int i = 0; i < M; ++i) {
            cout << current[i] << ' ';
        }
        cout << '\n';
        return;
    }
    for (int i = 0; i < arr.size(); ++i) {
        if (!visited[i]) {
            visited[i] = 1;
            current[cnt] = arr[i];
            // i = 0일 때,
            // current: 1, 7 => 1, 8 => 1, 9
            printResult(M, cnt + 1);
            visited[i] = 0;
        }
    }
}

int main() {
    init();
    int N, M;
    cin >> N >> M;
    arr.resize(N);
    current.resize(M);
    visited.resize(N, 0);

    for (int i = 0; i < N; ++i) {
        cin >> arr[i];
    }
    sort(arr.begin(), arr.end());

    printResult(M, 0);

    return 0;
}
