#include <algorithm>
#include <iostream>
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

int main() {
    init();
    int N;
    cin >> N;

    vector<int> A(N);
    for (int i = 0; i < N; ++i) {
        cin >> A[i];
    }

    vector<int> lis;
    for (int i = 0; i < N; ++i) {
        auto it = lower_bound(lis.begin(), lis.end(), A[i]);

        if (it == lis.end()) {
            lis.push_back(A[i]);
        } else {
            *it = A[i];
        }
    }

    cout << lis.size() << "\n";

    return 0;
}