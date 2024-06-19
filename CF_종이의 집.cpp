#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

typedef long long ll;

void init() {
    cin.tie(NULL);
    cout.tie(NULL);
    ios::sync_with_stdio(false);
}

int main() {
    init();
    int N;
    vector<int> A;
    cin >> N;
    for (int i = 0; i < N; i++) {
        int n;
        cin >> n;
        A.push_back(n);
    }
    sort(A.begin(), A.end(), greater<int>());
    cout << A[0] + A[1] << endl;
    return 0;
}