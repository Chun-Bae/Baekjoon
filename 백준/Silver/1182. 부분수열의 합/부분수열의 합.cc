#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

int N, S;
vector<int> arr;

int bt(int idx, int sum) {
    if (idx == N) {
        return (sum == S) ? 1 : 0;
    }

    int cnt = 0;
    cnt += bt(idx + 1, sum);
    cnt += bt(idx + 1, sum + arr[idx]);
    return cnt;
}

int main() {
    cin >> N >> S;
    for (int i = 0; i < N; i++) {
        int n;
        cin >> n;
        arr.push_back(n);
    }
    int result = bt(0, 0);
    if (S == 0) result -= 1;

    cout << result;

    return 0;
}