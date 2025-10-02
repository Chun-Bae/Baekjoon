#include <algorithm>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#define MAX 6
using namespace std;

vector<int> arr;
vector<int> store;
vector<bool> visited;

int k;

void bt(int depth) {
    if (depth == MAX) {
        for (auto n : store) {
            cout << n << " ";
        }
        cout<<endl;
        return;
    }
    for (int i = 0; i < k; i++) {
        if (store[depth - 1] > arr[i]) continue;
        if (visited[i] == false) {
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
        store.resize(MAX);
        visited.resize(k, false);
        for (int i = 0; i < k; i++)
            cin >> arr[i];

        sort(arr.begin(), arr.end());
        bt(0);
        cout << endl;
    }
    return 0;
}