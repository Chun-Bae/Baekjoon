#include <algorithm>
#include <iostream>
#include <limits>
#include <vector>
#define INF std::numeric_limits<int>::max()

using namespace std;
typedef long long ll;

int main() {
    int N;
    cin >> N;
    vector<int> solution(N);
    for (int i = 0; i < N; i++) {
        cin >> solution[i];
    }
    sort(solution.begin(), solution.end());

    int l = 0;
    int bl = 0;
    int r = N - 1;
    int br = N - 1;
    ll best = INF;
    while (l < r) {
        int sum = solution[l] + solution[r];
        // cout << sum << endl;
        if (abs(sum) < best) {
            best = abs(sum);
            bl = l;
            br = r;
        }
        if (sum > 0)
            r--;
        else
            l++;
    }
    printf("%d %d", solution[bl], solution[br]);

    return 0;
}