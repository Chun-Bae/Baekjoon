#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

int main() {
    int K, N, score, min, max, lg;
    cin >> K;
    for (int i = 1; i <= K; i++) {
        cin >> N;
        vector<int> scores;
        for (int j = 0; j < N; j++) {
            cin >> score;
            scores.push_back(score);
        }

        sort(scores.begin(), scores.end(), greater<int>());
        lg = 0;
        for (int j = 0; j < N; j++)
            if (j && lg < scores[j - 1] - scores[j]) lg = scores[j - 1] - scores[j];
        max = scores[0];
        min = scores[N - 1];
        cout << "Class " << i << endl;
        cout << "Max " << max << ", Min " << min << ", Largest gap " << lg << endl;
    }
    return 0;
}