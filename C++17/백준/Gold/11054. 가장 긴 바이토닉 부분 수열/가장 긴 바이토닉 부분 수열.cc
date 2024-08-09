#include <algorithm>
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
    int N;
    cin >> N;
    vector<int> A(N);
    for (int i = 0; i < N; i++) {
        cin >> A[i];
    }

    vector<int> inc(N, 1);
    vector<int> dec(N, 1);

    for (int i = 1; i < N; i++) {
        for (int j = 0; j < i; j++) {
            // 이전 값이 현재 값보다 작은 경우에 그 원소 위치에 대한 증가 수열의 길이를 갱신한다.
            if (A[i] > A[j]) {
                inc[i] = max(inc[i], inc[j] + 1);
            }
        }
    }

    for (int i = N - 2; i >= 0; i--) {
        for (int j = N - 1; j > i; j--) {
            // 역순으로 똑같이 하는 거임
            if (A[i] > A[j]) {
                dec[i] = max(dec[i], dec[j] + 1);
            }
        }
    }

    int maxLength = 0;
    for (int i = 0; i < N; i++) {
        maxLength = max(maxLength, inc[i] + dec[i] - 1);
    }

    cout << maxLength << "\n";
    return 0;
}
