#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

int main() {
    int N;
    vector<int> A;
    int M;
    vector<int> X;

    cin >> N;
    A.resize(N);
    for (int i = 0; i < N; i++) cin >> A[i];

    cin >> M;
    X.resize(M);
    for (int i = 0; i < M; i++) cin >> X[i];

    sort(A.begin(), A.end());

    for (auto target : X) {
        int left = 0;
        int right = N - 1;
        bool is_exist = false;

        while (left <= right) {
            int mid = (right + left) / 2;

            if (A[mid] == target) {
                is_exist = true;
                break;
            } else if (A[mid] < target) {
                left = mid + 1;
            } else {
                right = mid - 1;
            }
        }
        cout << is_exist ? 1 : 0;
        cout << "\n";
    }
}

