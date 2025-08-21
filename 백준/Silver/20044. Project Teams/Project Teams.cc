#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

int main() {
    int n;
    vector<int> scores;
    vector<int> teams;
    cin >> n;
    int student_num = 2 * n;

    for (int i = 0; i < student_num; i++) {
        int s;
        cin >> s;
        scores.push_back(s);
    }
    sort(scores.begin(), scores.end(), [](int a, int b) { return a < b; });

    for (int i = 0; i < n; i++) {
        teams.push_back(scores[i] + scores[scores.size() - 1 - i]);
    }

    auto it = min_element(teams.begin(), teams.end());
    cout << *it;
    return 0;
}