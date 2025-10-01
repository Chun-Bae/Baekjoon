#include <iostream>
#include <vector>
#include <sstream>

using namespace std;

void bt(vector<int>& arr, vector<int>& visited, int k, int N, int M) {
    if (k == M) {
        for (int i = 0; i < M; ++i) {
            cout << arr[i] << ' ';
        }
        cout << '\n';
        return;
    }
    for (int i = 1; i <= N; i++) {
        if (visited[i] == 0) {
            arr[k] = i;
            visited[i] = 1;
            bt(arr, visited, k + 1, N, M);
            visited[i] = 0;
        }
    }
}

int main() {
    int N, M;
    vector<int> arr;
    vector<int> visited;
    cin >> N >> M;
    arr.resize(M);
    visited.resize(N + 1);
    bt(arr, visited, 0, N, M);
    return 0;
}