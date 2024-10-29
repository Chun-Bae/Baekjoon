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
int N, K;
vector<string> words;
int maxCount = 0;
const int essential = (1 << ('a' - 'a')) | (1 << ('n' - 'a')) | (1 << ('t' - 'a')) | (1 << ('i' - 'a')) | (1 << ('c' - 'a'));

int countReadableWords(int learned) {
    int count = 0;
    for (const string& word : words) {
        bool readable = true;
        for (char ch : word) {
            if (!(learned & (1 << (ch - 'a')))) {
                readable = false;
                break;
            }
        }
        if (readable) count++;
    }
    return count;
}

void dfs(int learned, int idx, int depth) {
    if (depth == K - 5) {
        maxCount = max(maxCount, countReadableWords(learned));
        return;
    }
    for (int i = idx; i < 26; ++i) {
        if (!(learned & (1 << i))) {
            dfs(learned | (1 << i), i + 1, depth + 1);
        }
    }
}

int main() {
    init();
    cin >> N >> K;
    if (K < 5) {
        cout << 0 << endl;
        return 0;
    }

    words.resize(N);
    for (int i = 0; i < N; ++i) {
        cin >> words[i];
        words[i] = words[i].substr(4, words[i].size() - 8);
    }

    dfs(essential, 0, 0);

    cout << maxCount << endl;
    return 0;
}