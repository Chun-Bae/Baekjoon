#include <algorithm>
#include <iostream>
#include <string>
#include <unordered_map>
#include <vector>
#define MOD 900528
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
    string chars, password;
    cin >> chars >> password;

    unordered_map<char, int> charIndex;
    int len = chars.size();

    for (int i = 0; i < len; i++) {
        charIndex[chars[i]] = i;
    }

    int passwordLen = password.size();
    ll result = 0;

    for (int i = 0; i < passwordLen; i++) {
        result = result * len + charIndex[password[i]];
        result %= MOD;
    }
    ll factor = 1;
    for (int i = 1; i < passwordLen; i++) {
        factor = factor * len % MOD;
        result = (result + factor) % MOD;
    }

    cout << (result + 1) % MOD << endl;
    return 0;
}