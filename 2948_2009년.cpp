#include <iostream>
#include <vector>

using namespace std;

int main() {
    vector<string> days = {"Wednesday", "Thursday", "Friday", "Saturday", "Sunday", "Monday", "Tuesday"};
    vector<int> lastdays = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    int D, M, sum = 0;
    cin >> D >> M;
    sum += D;
    for (int i = 0; i < M - 1; i++) {
        sum += lastdays[i];
    }
    cout << days[sum % 7] << endl;
    return 0;
}