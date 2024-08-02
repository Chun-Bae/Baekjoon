#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>

using namespace std;

typedef long long ll;

void init() {
    cin.tie(NULL);
    cout.tie(NULL);
    ios::sync_with_stdio(false);
}

int main() {
    init();
    
    int n;
    cin >> n;
    
    vector<int> A(n), B(n), C(n), D(n);
    
    for (int i = 0; i < n; ++i) {
        cin >> A[i] >> B[i] >> C[i] >> D[i];
    }
    
    unordered_map<int, int> sumAB;
    
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            int sum = A[i] + B[j];
            sumAB[sum]++;
        }
    }
    
    ll count = 0;
    
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            int sum = C[i] + D[j];
            if (sumAB.find(-sum) != sumAB.end()) {
                count += sumAB[-sum];
            }
        }
    }
    
    cout << count << '\n';
    
    return 0;
}
