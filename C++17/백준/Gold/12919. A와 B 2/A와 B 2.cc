#include <algorithm>
#include <iostream>
#include <string>
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
bool canTransform(string S, string T) {
    if (S.length() > T.length()) return false;
    if (S == T) return true;

    bool result = false;

    if (T.back() == 'A') {
        string next_T = T;
        next_T.pop_back();
        if (canTransform(S, next_T)) return true;
    }

    if (T.front() == 'B') {
        string next_T = T;
        reverse(next_T.begin(), next_T.end());
        next_T.pop_back();
        if (canTransform(S, next_T)) return true;
    }

    return false;
}

int main() {
    init();
    string S, T;
    cin >> S >> T;

    if (canTransform(S, T)) {
        cout << 1 << endl;
    } else {
        cout << 0 << endl;
    }

    return 0;
}