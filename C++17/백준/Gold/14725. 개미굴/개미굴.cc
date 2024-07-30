#include <iostream>
#include <vector>
#include <map>
#include <string>
#include <algorithm>

using namespace std;

struct TreeNode {
    map<string, TreeNode*> children;
};

TreeNode* createNode() {
    return new TreeNode();
}

void insert(TreeNode* root, const vector<string>& path) {
    TreeNode* node = root;
    for (const string& food : path) {
        if (node->children.find(food) == node->children.end()) {
            node->children[food] = createNode();
        }
        node = node->children[food];
    }
}

void print(TreeNode* node, int depth) {
    for (auto& child : node->children) {
        for (int i = 0; i < depth; ++i) {
            cout << "--";
        }
        cout << child.first << endl;
        print(child.second, depth + 1);
    }
}

void deleteTree(TreeNode* node) {
    for (auto& child : node->children) {
        deleteTree(child.second);
    }
    delete node;
}

void init() {
    cin.tie(NULL);
    cout.tie(NULL);
    ios::sync_with_stdio(false);
}

int main() {
    init();
    int N;
    cin >> N;

    TreeNode* root = createNode();

    for (int i = 0; i < N; ++i) {
        int K;
        cin >> K;
        vector<string> path(K);
        for (int j = 0; j < K; ++j) {
            cin >> path[j];
        }
        insert(root, path);
    }

    print(root, 0);
    deleteTree(root);

    return 0;
}
