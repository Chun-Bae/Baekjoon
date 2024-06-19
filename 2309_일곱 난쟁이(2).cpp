#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

vector<int> search(vector<int> d, int s) {
    vector<int> ans;
    for (int i = 0; i < 9; i++) {
        for (int j = i + 1; j < 9; j++) {
            if (d[i] + d[j] == s - 100) {
                ans.push_back(d[i]);
                ans.push_back(d[j]);
                return ans;
            }
        }
    }
}

int main() {
    vector<int> dwarf;
    vector<int> ans;
    int n, sum = 0;
    int a, b;
    for (int i = 0; i < 9; i++) {
        cin >> n;
        sum += n;
        dwarf.push_back(n);
    }
    sort(dwarf.begin(), dwarf.end());
    ans = search(dwarf, sum);
    for (auto& d : dwarf) {
        if (d == ans[0] || d == ans[1]) continue;
        cout << d << endl;
    }

    return 0;
}