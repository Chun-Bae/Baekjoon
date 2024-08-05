#include <iostream>
#include <vector>

using namespace std;

void init() {
    cin.tie(NULL);
    cout.tie(NULL);
    ios::sync_with_stdio(false);
}

int main() {
    init();
    
    int N, K;
    cin >> N >> K;
    vector<int> blob(N);
    for (int i = 0; i < N; ++i) {
        cin >> blob[i];
    }

    vector<int> extended_blob(N + K - 1);
    for (int i = 0; i < N + K - 1; ++i) {
        extended_blob[i] = blob[i % N];
    }

    int current_sum = 0;
    for (int i = 0; i < K; ++i) {
        current_sum += extended_blob[i];
    }
    int max_sum = current_sum;

    for (int i = K; i < N + K - 1; ++i) {
        current_sum += extended_blob[i] - extended_blob[i - K];
        max_sum = max(max_sum, current_sum);
    }

    cout << max_sum << "\n";

    return 0;
}
