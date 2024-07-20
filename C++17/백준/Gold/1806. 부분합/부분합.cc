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
    int N, S;
    cin >> N >> S;
    vector<int> arr(N);
    for (int i = 0; i < N; i++) {
        cin >> arr[i];
    }

    int minLength = N + 1;
    int sum = 0;
    int start = 0;

    for (int end = 0; end < N; end++) {
        sum += arr[end];

        // 부분합이 S 이상이 되는 경우, start를 증가시켜가며 최소 길이를 찾는다.
        while (sum >= S) {
            minLength = min(minLength, end - start + 1);
            sum -= arr[start++];
        }
    }

    if (minLength == N + 1) {
        cout << 0;
    } else {
        cout << minLength;
    }

    return 0;
}
