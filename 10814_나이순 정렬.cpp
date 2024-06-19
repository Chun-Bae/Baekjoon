#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

bool comp(pair<int, string> a, pair<int, string> b) { return a.first < b.first; }

int main() {
    int T;
    int age;
    string name;
    vector<pair<int, string>> skdltns;
    cin >> T;
    for (int i = 0; i < T; i++) {
        cin >> age >> name;
        skdltns.push_back(make_pair(age, name));
    }
    stable_sort(skdltns.begin(), skdltns.end(), comp);
    for (int i = 0; i < T; i++) cout << skdltns[i].first << " " << skdltns[i].second << '\n';

    return 0;
}