#include <iostream>
#include <vector>

using namespace std;

int main() {
    int month, day, sum = 0;
    vector<int> days = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    cin >> month >> day;
    for (int i = 0; i < month - 1; i++) sum += days[i];
    sum += day;
    if (sum == 49) cout << "Special" << endl;
    if (sum < 49) cout << "Before" << endl;
    if (sum > 49) cout << "After" << endl;
    return 0;
}