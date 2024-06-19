#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    vector<int> dwarf;
    int num, spy, sum = 0;
    for (int i = 0; i < 9; i++) {
        cin >> num;
        dwarf.push_back(num);
        sum += num;
    }
    spy = sum - 100;
    bool found = false;
    for (int i = 0; i < dwarf.size() && !found; i++) {
        for (int j = i + 1; j < dwarf.size() && !found; j++) {
            if (dwarf[i] + dwarf[j] == spy) {
                dwarf.erase(dwarf.begin() + j);
                dwarf.erase(dwarf.begin() + i);
                found = true;
            }
        }
    }
    sort(dwarf.begin(),dwarf.end(),less<int>());
    for (int i = 0; i < dwarf.size(); i++) {
        cout << dwarf[i] << endl;
    }
    return 0;
}