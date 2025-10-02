#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int N, M;
vector<int> arr;
vector<int> store;
vector<bool> visited;

void bt(int k) {
    if (k == M) {
        for (int i = 0; i < M; i++) {
            cout << store[i] << " ";
        }
        cout << "\n";
        return;
    }
    for (int i = 0; i < N; i++) {
        if (store[k - 1] > arr[i]) continue;
        if (visited[i] == false) {
            store[k] = arr[i];
            visited[i] = true;
            bt(k + 1);
            visited[i] = false;
        }
    }
}

int main() {
    cin >> N >> M;
    arr.resize(N);
    store.resize(M);
    visited.resize(N, false);
    for (int i = 0; i < N; i++) {
        int n;
        cin >> n;
        arr[i] = n;
    }

    sort(arr.begin(), arr.end());
    bt(0);
    return 0;
}