#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

int day2int(int day, int month, int year) {
    int lastday[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    int result = 0;
    result += day;
    for (int i = 1; i < month; i++) result += lastday[i];
    result += year * 365;
    return result;
}
int main() {
    int N;
    string name_tmp;
    int day_tmp, month_tmp, year_tmp;

    vector<string> name;
    vector<int> day_size;

    cin >> N;
    for (int i = 0; i < N; i++) {
        cin >> name_tmp;
        cin >> day_tmp;
        cin >> month_tmp;
        cin >> year_tmp;
        name.push_back(name_tmp);
        day_size.push_back(day2int(day_tmp, month_tmp, year_tmp));
    }
    int max_idx = max_element(day_size.begin(), day_size.end()) - day_size.begin();
    int min_idx = min_element(day_size.begin(), day_size.end()) - day_size.begin();

    cout << name[max_idx] << endl << name[min_idx];
    return 0;
}