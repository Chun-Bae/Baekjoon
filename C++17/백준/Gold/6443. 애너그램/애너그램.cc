#include <algorithm>
#include <iostream>
#include <set>
#include <vector>

using namespace std;

typedef long long ll;
typedef vector<string> vec1_str;
typedef vector<bool> vec1_bool;

void init() {
    cin.tie(NULL);
    cout.tie(NULL);
    ios::sync_with_stdio(false);
}
void backtrack(string &s, vec1_bool &used, string &cur, set<string> &result) {
    if (cur.size() == s.size()) {
        result.insert(cur);
        return;
    }

    for (int i = 0; i < s.size(); i++) {
        if (used[i] || (i > 0 && s[i] == s[i - 1] && !used[i - 1])) {
            continue;
        }
        used[i] = true;
        cur.push_back(s[i]);
        backtrack(s, used, cur, result);
        cur.pop_back();
        used[i] = false;
    }
}
set<string> mkAnagram(string &str) {
    set<string> result;
    sort(str.begin(), str.end());
    vec1_bool used(str.size(), false);
    string cur;
    backtrack(str, used, cur, result);
    return result;
}
int main() {
    init();
    int N;
    cin >> N;
    vec1_str words(N);

    for (int i = 0; i < N; i++) cin >> words[i];
    for (int i = 0; i < N; i++) {
        set<string> anagrams = mkAnagram(words[i]);
        for (const string &anagram : anagrams) {
            cout << anagram << "\n";
        }
    }

    return 0;
}