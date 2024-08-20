#include <bitset>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

typedef long long ll;

string transBinMin(ll initV, int cntT) {
    int cntBit = __builtin_popcountll(initV);
    if (cntBit < cntT) return "-1";

    vector<ll> result;
    int range = cntBit - cntT + 1;

    // 1100 & 0100 = 0100
    // 1100 - 0100 = 1000
    // 2 try: 0000
    for (int i = 0; i < range; i++) {
        initV -= (initV & -initV);
    }
    result.push_back(initV);

    while (initV > 0) {
        initV -= (initV & -initV);
        result.push_back(initV);
    }

    string output;
    for (auto value : result) {
        output += to_string(value) + " ";
    }

    return output;
}

void init() {
    cin.tie(NULL);
    cout.tie(NULL);
    ios::sync_with_stdio(false);
}

int main() {
    init();
    ll initV;
    int cntT;
    cin >> initV >> cntT;

    string result = transBinMin(initV, cntT);
    cout << result << endl;

    return 0;
}
