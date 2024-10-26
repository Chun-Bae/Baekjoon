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

int main() {
    init();
    int T, S;
    cin >> T >> S;

    if (12 <= T && T <= 16 && S == 0) {
        cout << 320 << endl;
    } else {
        cout << 280 << endl;
    }

    return 0;
}