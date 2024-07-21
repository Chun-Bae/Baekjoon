#include <iostream>
#include <vector>
#include <cmath>
#include <limits>
using namespace std;

typedef long long ll;

void init(){
    cin.tie(NULL);
    cout.tie(NULL);
    ios::sync_with_stdio(false);
}

int main(){
    init();
    int N;
    cin >> N;
    vector<int> arr(N);
    for(int i = 0; i < N; i++){
        cin >> arr[i];
    }

    int left = 0;
    int right = N - 1;
    int bestLeft = left;
    int bestRight = right;
    ll closestSum = numeric_limits<ll>::max();

    while (left < right) {
        ll currentSum = arr[left] + arr[right];
        if (abs(currentSum) < abs(closestSum)) {
            closestSum = currentSum;
            bestLeft = left;
            bestRight = right;
        }

        if (currentSum < 0) {
            left++;
        } else {
            right--;
        }
    }

    cout << arr[bestLeft] << " " << arr[bestRight] << endl;

    return 0;
}
