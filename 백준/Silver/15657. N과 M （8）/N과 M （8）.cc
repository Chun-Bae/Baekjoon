#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

int N, M;
vector<int> arr;
vector<int> store;

void bt(int k) {
    if (k == M) {
        for (int i = 0; i < M; i++)
            cout << store[i] << " ";
        cout << "\n";
        return;
    }

    for (int i = 0; i < N; i++) {
        if (k > 0 && store[k - 1] > arr[i]) continue;
        store[k] = arr[i];
        bt(k + 1);
    }
}

int main() {
    cin >> N >> M;
    arr.resize(N);
    store.resize(M);
    for (int i = 0; i < N; i++) cin >> arr[i];
    sort(arr.begin(), arr.end());
    bt(0);
    return 0;
}