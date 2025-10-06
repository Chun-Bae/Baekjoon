#include <iostream>

using namespace std;

struct Node {
    char value;
    Node* left = nullptr;
    Node* right = nullptr;
};

void preorder(Node* node) {
    if (node == nullptr) return;
    cout << node->value;
    preorder(node->left);
    preorder(node->right);
}

void inorder(Node* node) {
    if (node == nullptr) return;
    inorder(node->left);
    cout << node->value;
    inorder(node->right);
}

void postorder(Node* node) {
    if (node == nullptr) return;
    postorder(node->left);
    postorder(node->right);
    cout << node->value;
}

int main() {
    int N;
    cin >> N;
    Node nodes[26];
    for (int i = 0; i < 26; i++)
        nodes[i].value = char('A' + i);

    Node* root = &nodes[0];
    for (int i = 0; i < N; i++) {
        char v, l, r;
        cin >> v >> l >> r;
        Node* cur = &nodes[v - 'A'];
        cur->left = (l == '.') ? nullptr : &nodes[l - 'A'];
        cur->right = (r == '.') ? nullptr : &nodes[r - 'A'];
    }

    preorder(root);
    cout << '\n';
    inorder(root);
    cout << '\n';
    postorder(root);
    cout << '\n';

    return 0;
}