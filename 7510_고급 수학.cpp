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
    cin >> N;
    for (int i = 0; i < N; i++) {
        vector<ll> arr(3);
        cin >> arr[0] >> arr[1] >> arr[2];
        sort(arr.begin(), arr.end());

        cout << "Scenario #" << i + 1 << ":\n";
        if (arr[0] * arr[0] + arr[1] * arr[1] == arr[2] * arr[2])
            cout << "yes\n\n";
        else
            cout << "no\n\n";
    }
    return 0;
}