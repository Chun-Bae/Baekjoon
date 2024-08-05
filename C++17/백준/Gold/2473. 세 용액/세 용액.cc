#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

typedef long long ll;
using namespace std;

void init() {
    cin.tie(NULL);
    cout.tie(NULL);
    ios::sync_with_stdio(false);
}

int main() {
    init();
    
    int n;
    cin >> n;
    
    vector<ll> solutions(n);
    for (int i = 0; i < n; ++i) {
        cin >> solutions[i];
    }
    
    sort(solutions.begin(), solutions.end());
    
    ll closest_sum = 3000000000; 
    vector<ll> result(3);
    
    for (int i = 0; i < n - 2; ++i) {
        int left = i + 1;
        int right = n - 1;
        
        while (left < right) {
            ll sum = solutions[i] + solutions[left] + solutions[right];
            
            if (abs(sum) < abs(closest_sum)) {
                closest_sum = sum;
                result[0] = solutions[i];
                result[1] = solutions[left];
                result[2] = solutions[right];
            }
            
            if (sum < 0) {
                ++left;
            } else {
                --right;
            }
        }
    }
    
    sort(result.begin(), result.end());
    for (int i = 0; i < 3; ++i) {
        cout << result[i] << " ";
    }
    cout << "\n";
    
    return 0;
}
