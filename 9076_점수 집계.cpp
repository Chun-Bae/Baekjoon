#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

int main() {
    vector<int> score(5);
    int T, n;
    cin >> T;
    for (int i = 0; i < T; i++) {
        for (int j = 0; j < 5; j++) {
            cin >> n;
            score[j] = n;
        }
        sort(score.begin(), score.end(), less<int>());
        if (score[3] - score[1] >= 4)
            cout << "KIN" << endl;
        else
            cout << score[1] + score[2] + score[3] << endl;
    }
    return 0;
}