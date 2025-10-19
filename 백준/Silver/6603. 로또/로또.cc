#include <algorithm>
#include <iostream>
#include <vector>

const int MAX_DEPTH = 6;

using namespace std;

int k;
vector<int> arr;
vector<int> store;
vector<bool> visited;

void bt(int depth) {
    if (depth == MAX_DEPTH) {
        for (int n : store) {
            cout << n << ' ';
        }
        cout << '\n';
        return;
    }

    for (int i = 0; i < k; i++) {
        if (depth > 0)
            if (store[depth - 1] > arr[i])
                continue;

        if (!visited[i]) {
            store[depth] = arr[i];
            visited[i] = true;
            bt(depth + 1);
            visited[i] = false;
        }
    }
}

int main() {
    while (1) {
        cin >> k;
        if (k == 0) break;
        arr.resize(k);
        store.resize(MAX_DEPTH);
        visited.resize(k, false);

        for (int i = 0; i < k; i++)
            cin >> arr[i];

        sort(arr.begin(), arr.end());
        bt(0);
        cout << '\n';
    }

    return 0;
}