#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

typedef long long ll;
typedef vector<int> vec1;
typedef vector<vec1> vec2;
typedef vector<vec2> vec3;

void init() {
    cin.tie(NULL);
    cout.tie(NULL);
    ios::sync_with_stdio(false);
}

int soundex(char c) {
    if (c == 'B' || c == 'F' || c == 'P' || c == 'V') return 1;
    if (c == 'C' || c == 'G' || c == 'J' || c == 'K' || c == 'Q' || c == 'S' || c == 'X' || c == 'Z') return 2;
    if (c == 'D' || c == 'T') return 3;
    if (c == 'L') return 4;
    if (c == 'M' || c == 'N') return 5;
    if (c == 'R') return 6;
    return 0;
}

int main() {
    init();
    string str;
    while (cin >> str) {
        int prev = 0;
        for (auto s : str) {
            int num = soundex(s);
            if (num != 0 && num != prev) {
                cout << num;
            }
            prev = num;
        }
        cout << '\n';
    }
    return 0;
}