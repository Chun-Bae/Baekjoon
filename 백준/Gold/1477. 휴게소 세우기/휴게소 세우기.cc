#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

int main() {
    int N, M, L;
    cin >> N >> M >> L;
    vector<int> rest(N + 2);
    vector<int> dist(N + 1);

    for (int i = 1; i <= N; i++)
        cin >> rest[i];
    rest[0] = 0;
    rest[N + 1] = L;
    sort(rest.begin(), rest.end());

    // for (int i = 0; i < N + 1; i++) {
    //     cout << rest[i] << " ";
    // }
    // cout << endl;
    for (int i = 0; i < N + 1; i++) {
        dist[i] = rest[i + 1] - rest[i];
        // cout << dist[i] << " ";
    }

    int left = 1;
    int right = *max_element(dist.begin(), dist.end());

    while (left <= right) {
        int mid = (left + right) / 2;
        // cout << mid << endl;
        int sum = 0;
        for (auto d : dist) {
            sum += ((d - 1) / mid);
        }
        if (sum > M) {
            left = mid + 1;
        } else {
            right = mid - 1;
        }
    }
    cout << left;

    return 0;
}