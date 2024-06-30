#include <algorithm>
#include <iostream>

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

    int prevMin[3] = {0, 0, 0}, prevMax[3] = {0, 0, 0};
    int currMin[3], currMax[3];

    for (int i = 0; i < N; i++) {
        cin >> currMin[0] >> currMin[1] >> currMin[2];
        currMax[0] = currMin[0];
        currMax[1] = currMin[1];
        currMax[2] = currMin[2];

        if (i > 0) {
            int tempMin[3], tempMax[3];

            tempMin[0] = currMin[0] + min(prevMin[0], prevMin[1]);
            tempMin[1] = currMin[1] + min({prevMin[0], prevMin[1], prevMin[2]});
            tempMin[2] = currMin[2] + min(prevMin[1], prevMin[2]);

            tempMax[0] = currMax[0] + max(prevMax[0], prevMax[1]);
            tempMax[1] = currMax[1] + max({prevMax[0], prevMax[1], prevMax[2]});
            tempMax[2] = currMax[2] + max(prevMax[1], prevMax[2]);

            for (int j = 0; j < 3; j++) {
                prevMin[j] = tempMin[j];
                prevMax[j] = tempMax[j];
            }
        } else {
            for (int j = 0; j < 3; j++) {
                prevMin[j] = currMin[j];
                prevMax[j] = currMax[j];
            }
        }
    }

    int minScore = min({prevMin[0], prevMin[1], prevMin[2]});
    int maxScore = max({prevMax[0], prevMax[1], prevMax[2]});

    cout << maxScore << " " << minScore << "\n";

    return 0;
}
