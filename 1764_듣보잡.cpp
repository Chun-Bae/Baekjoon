#include <algorithm>
#include <iostream>
#include <map>
#include <vector>

using namespace std;

void init() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
}

int main() {
    init();
    int N, M;
    string str;
    map<string, int> dbj;
    vector<string> target;

    cin >> N >> M;
    for (int i = 0; i < N + M; i++) {
        cin >> str;
        dbj[str]++;
        if (dbj[str] > 1) target.push_back(str);
    }
    sort(target.begin(), target.end());
    cout << target.size() << '\n';
    for (auto t : target) cout << t << '\n';
    return 0;
}