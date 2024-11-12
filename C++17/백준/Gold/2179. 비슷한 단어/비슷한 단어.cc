#include <algorithm>
#include <cstring>
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

struct TrieNode {
    TrieNode* children[26];
    int depth;
    int idx1;
    int idx2;

    TrieNode(int d) : depth(d), idx1(-1), idx2(-1) { memset(children, 0, sizeof(children)); }
};

void insert(TrieNode* root, const string& word, int idx) {
    TrieNode* node = root;
    for (char c : word) {
        int ch = c - 'a';
        if (!node->children[ch]) {
            node->children[ch] = new TrieNode(node->depth + 1);
        }
        node = node->children[ch];
        if (node->idx1 == -1 || idx < node->idx1) {
            node->idx2 = node->idx1;
            node->idx1 = idx;
        } else if ((node->idx2 == -1 || idx < node->idx2) && idx != node->idx1) {
            node->idx2 = idx;
        }
    }
}

void dfs(TrieNode* node, int& maxPrefixLength, int& idxS, int& idxT) {
    if (node->idx1 != -1 && node->idx2 != -1) {
        int depth = node->depth;
        if (depth > maxPrefixLength) {
            maxPrefixLength = depth;
            idxS = node->idx1;
            idxT = node->idx2;
        } else if (depth == maxPrefixLength) {
            if (node->idx1 < idxS || (node->idx1 == idxS && node->idx2 < idxT)) {
                idxS = node->idx1;
                idxT = node->idx2;
            }
        }
    }
    for (int i = 0; i < 26; ++i) {
        if (node->children[i]) {
            dfs(node->children[i], maxPrefixLength, idxS, idxT);
        }
    }
}

int main() {
    init();
    int N;
    cin >> N;
    vector<string> words(N);

    for (int i = 0; i < N; ++i) {
        cin >> words[i];
    }

    TrieNode* root = new TrieNode(0);

    for (int i = 0; i < N; ++i) {
        insert(root, words[i], i);
    }

    int maxPrefixLength = -1;
    int idxS = -1, idxT = -1;

    dfs(root, maxPrefixLength, idxS, idxT);

    if (idxS > idxT) swap(idxS, idxT);
    cout << words[idxS] << endl;
    cout << words[idxT] << endl;

    return 0;
}
