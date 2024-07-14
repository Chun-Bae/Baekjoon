#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

vector<pair<double, double>> coordinates;

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
    coordinates.resize(N);
    for (int i = 0; i < N; i++) {
        cin >> coordinates[i].first >> coordinates[i].second;
    }
    ll result = 0;
    for (int i = 0; i < N; i++) {
        if (i == N - 1)
            result += (coordinates[i].first * coordinates[0].second) - (coordinates[i].second * coordinates[0].first);
        else
            result += (coordinates[i].first * coordinates[(i + 1) % N].second) - (coordinates[i].second * coordinates[(i + 1) % N].first);
    }
    cout << fixed;
    cout.precision(1);
    cout << abs(result) / 2.0;  

    return 0;
}
