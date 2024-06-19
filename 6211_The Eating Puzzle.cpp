#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

int C, B;
vector<int> calories;
int max_calories = 0;

void init() {
    cin.tie(NULL);
    cout.tie(NULL);
    ios::sync_with_stdio(false);
}

void findBestCombination(int index, int current_sum) {
    if (current_sum > C) return;
    max_calories = max(max_calories, current_sum);
    if (index == B) return;

    findBestCombination(index + 1, current_sum);
    findBestCombination(index + 1, current_sum + calories[index]);
}

int main() {
    // Reading input
    cin >> C >> B;
    calories.resize(B);
    for (int i = 0; i < B; i++) {
        cin >> calories[i];
    }

    // Finding the best combination
    findBestCombination(0, 0);

    // Output the result
    cout << max_calories << endl;

    return 0;
}