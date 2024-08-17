#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

vector<int> averages;

bool validPeople(int people, const vector<int>& averages) {
    for (int avg : averages) {
        bool is_match = false;
        for (int total = 0; total <= 10 * people; ++total) {
            int score = (total * 1000) / people;

            if (score == avg) {
                is_match = true;
                break;
            }
        }

        if (!is_match) {
            return false;
        }
    }
    return true;
}

void init() {
    cin.tie(NULL);
    cout.tie(NULL);
    ios::sync_with_stdio(false);
}

int main() {
    init();
    int n;
    cin >> n;
    averages.resize(n);

    for (int i = 0; i < n; ++i) {
        string input;
        cin >> input;

        input.erase(remove(input.begin(), input.end(), '.'), input.end());
        averages[i] = stoi(input);
    }

    for (int people = 1; people <= 1000; ++people) {
        if (validPeople(people, averages)) {
            cout << people << endl;
            break;
        }
    }

    return 0;
}
