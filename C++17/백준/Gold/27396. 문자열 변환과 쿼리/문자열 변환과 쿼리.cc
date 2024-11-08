#include <iostream>
#include <string>
#include <unordered_map>
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
    string S;
    int n;
    cin >> S >> n;

    vector<string> results;
    unordered_map<char, char> transform;

    for (char c = 'A'; c <= 'Z'; c++) transform[c] = c;
    for (char c = 'a'; c <= 'z'; c++) transform[c] = c;

    for (int i = 0; i < n; i++) {
        int query_type;
        cin >> query_type;

        if (query_type == 1) {
            char i1, i2;
            cin >> i1 >> i2;

            for (auto& kv : transform) {
                if (kv.second == i1) {
                    kv.second = i2;
                }
            }
        } else if (query_type == 2) {
            string result = S;
            for (char& c : result) {
                c = transform[c];
            }
            results.push_back(result);
        }
    }

    for (const string& result : results) {
        cout << result << "\n";
    }

    return 0;
}
