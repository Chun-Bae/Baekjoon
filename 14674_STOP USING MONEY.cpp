#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

bool comp(vector<long long> a, vector<long long> b) {
    long long effectiveness_a = a[2] * b[1]; //부동 소수점 오류
    long long effectiveness_b = b[2] * a[1]; // a2 * b1 > b2*a1 == a2/a1 > b2/b1
    
    if (effectiveness_a != effectiveness_b)
        return effectiveness_a > effectiveness_b;
    else if (a[2] != b[2])
        return a[2] < b[2];

    return a[0] < b[0];
}

int main() {
    vector<vector<long long>> cost;
    vector<long long> tmp(3);
    int N, K;
    int i, c, h;

    cin >> N >> K;
    for (int j = 1; j <= N; j++) {
        cin >> i >> c >> h;
        tmp[0] = i;
        tmp[1] = c;
        tmp[2] = h;
        cost.push_back(tmp);
    }
    stable_sort(cost.begin(), cost.end(), comp);

    for (int j = 0; j < K; j++) {
        cout << cost[j][0] << '\n';
    }
    return 0;
}