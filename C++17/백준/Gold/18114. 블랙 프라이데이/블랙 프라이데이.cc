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
    int N, C;
    cin >> N >> C;
    vec1 weights(N);

    for (int i = 0; i < N; i++) {
        cin >> weights[i];
    }

    sort(weights.begin(), weights.end());

    for (int i = 0; i < N; i++) {
        if (weights[i] == C) {
            cout << 1 << endl;
            return 0;
        }
    }

    for (int i = 0; i < N; i++) {
        for (int j = i + 1; j < N; j++) {
            if (weights[i] + weights[j] > C) break;
            if (weights[i] + weights[j] == C) {
                cout << 1 << endl;
                return 0;
            }
        }
    }

    for (int i = 0; i < N; i++) {
        for (int j = i + 1; j < N; j++) {
            if (weights[i] + weights[j] >= C) continue;
            int target = C - weights[i] - weights[j];
            if (target <= 0) continue;

            if (binary_search(weights.begin() + j + 1, weights.end(), target)) {
                cout << 1 << endl;
                return 0;
            }
        }
    }

    cout << 0 << endl;
    return 0;
}