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

struct TrieNode {
    TrieNode* children[10];
    bool isEndOfNumber;

    TrieNode() {
        for (int i = 0; i < 10; ++i) {
            children[i] = nullptr;
        }
        isEndOfNumber = false;
    }
};

bool insert(TrieNode* root, const string& number) {
    TrieNode* current = root;

    for (char c : number) {
        int idx = c - '0';
        if (!current->children[idx]) {
            current->children[idx] = new TrieNode();
        }
        current = current->children[idx];
        if (current->isEndOfNumber) {
            return false;
        }
    }

    current->isEndOfNumber = true;
    for (int i = 0; i < 10; ++i) {
        if (current->children[i]) {
            return false;
        }
    }

    return true;
}

bool isConsistent(const vector<string>& numbers) {
    TrieNode* root = new TrieNode();

    for (const string& number : numbers) {
        if (!insert(root, number)) {
            return false;
        }
    }

    return true;
}

int main() {
    init();

    int t;
    cin >> t;

    while (t--) {
        int n;
        cin >> n;

        vector<string> phoneNumbers(n);
        for (int i = 0; i < n; ++i) cin >> phoneNumbers[i];

        sort(phoneNumbers.begin(), phoneNumbers.end());

        if (isConsistent(phoneNumbers)) {
            cout << "YES\n";
        } else {
            cout << "NO\n";
        }
    }

    return 0;
}
