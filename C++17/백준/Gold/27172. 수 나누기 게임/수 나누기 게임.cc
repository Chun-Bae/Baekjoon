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

    int N;
    cin >> N;
    vector<int> cards(N);
    vector<int> count(1000001, 0);
    vector<int> scores(1000001, 0);

    for (int i = 0; i < N; ++i) {
        cin >> cards[i];
        count[cards[i]]++;
    }

    for (int i = 1; i <= 1000000; ++i) {
        if (count[i] > 0) {
            for (int j = i * 2; j <= 1000000; j += i) {
                if (count[j] > 0) {
                    scores[j]--;
                    scores[i]++;
                }
            }
        }
    }

    vector<int> final_scores(N);
    for (int i = 0; i < N; ++i) {
        final_scores[i] = scores[cards[i]];
    }

    for (int i = 0; i < N; ++i) {
        cout << final_scores[i] << " ";
    }

    return 0;
}
