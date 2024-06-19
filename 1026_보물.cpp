#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

int main() {
    vector<int> A, B;
    int T, n, sum = 0;
    cin >> T;
    for (int i = 0; i < T; i++) {
        cin >> n;
        A.push_back(n);
    }
    for (int i = 0; i < T; i++) {
        cin >> n;
        B.push_back(n);
    }
    sort(A.begin(), A.end(), less<int>());
    sort(B.begin(), B.end(), greater<int>());
    for (int i = 0; i < T; i++) sum += A[i] * B[i];
    cout << sum << endl;
    return 0;
}