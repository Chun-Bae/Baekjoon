#include <algorithm>
#include <iostream>
#include <unordered_map>
#include <vector>

using namespace std;

typedef long long ll;
typedef vector<int> vec1;
typedef vector<vec1> vec2;
typedef vector<vec2> vec3;

void init() {
    cin.tie(NULL);
    cout.tie(NULL);
    ios::sync_with_stdio(false);
}

ll countZeroSumTriplets(vec1& arr) {
    unordered_map<int, int> freq;
    for (int num : arr) {
        freq[num]++;
    }
    vec1 unique_nums;
    for (auto& p : freq) {
        unique_nums.push_back(p.first);
    }
    sort(unique_nums.begin(), unique_nums.end());
    ll count = 0;
    for (int i = 0; i < unique_nums.size(); ++i) {
        int a = unique_nums[i];
        for (int j = i; j < unique_nums.size(); ++j) {
            int b = unique_nums[j];
            int c = -a - b;
            if (c < b) continue;
            if (freq.find(c) == freq.end()) continue;
            ll count_a = freq[a];
            ll count_b = freq[b];
            ll count_c = freq[c];

            if (a == b && b == c) {
                count += count_a * (count_a - 1) * (count_a - 2) / 6;
            } else if (a == b && b != c) {
                count += count_a * (count_a - 1) / 2 * count_c;
            } else if (a == c && a != b) {
                count += count_a * (count_a - 1) / 2 * count_b;
            } else if (b == c && a != b) {
                count += count_b * (count_b - 1) / 2 * count_a;
            } else {
                count += count_a * count_b * count_c;
            }
        }
    }
    return count;
}

int main() {
    init();
    int N;
    cin >> N;

    vec1 A(N);
    for (int i = 0; i < N; ++i) {
        cin >> A[i];
    }

    ll result = countZeroSumTriplets(A);
    cout << result << endl;
    return 0;
}