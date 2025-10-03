#include <algorithm>
#include <iostream>
#include <vector>

#define PICK 3

using namespace std;

int main() {
    int N;
    vector<int> U;
    cin >> N;
    U.resize(N);
    for (int i = 0; i < N; i++) cin >> U[i];
    sort(U.begin(), U.end());

    vector<int> P;

    for (int i = 0; i < N; i++) {
        for (int j = i; j < N; j++) {
            P.push_back(U[i] + U[j]);
        }
    }
    sort(P.begin(), P.end());

    for (int i = N - 1; i >= 0; i--) {
        for (int j = i - 1; j >= 0; j--) {
            int target = U[i] - U[j];
            int left = 0;
            int right = P.size() - 1;
            while (left <= right) {
                int mid = (left + right) / 2;
                if (P[mid] == target) {
                    cout << U[i];
                    return 0;
                } else if (P[mid] < target) {
                    left = mid + 1;
                } else {
                    right = mid - 1;
                }
            }
        }
    }
    return 0;
}