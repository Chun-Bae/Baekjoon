#include <iostream>
#include <vector>

using namespace std;

void init() {
    cin.tie(NULL);
    cout.tie(NULL);
    ios::sync_with_stdio(false);
}

struct TreeNode {
    int key;
    TreeNode* left;
    TreeNode* right;
    // 생성자: key를 x로 초기화하고, left와 right는 NULL로 초기화
    TreeNode(int x) : key(x), left(NULL), right(NULL) {}
};

// 이진 검색 트리에 노드를 삽입하는 함수
TreeNode* insert(TreeNode* root, int key) {
    if (!root) return new TreeNode(key);  // 루트가 NULL이면 새로운 노드를 생성
    if (key < root->key)
        root->left = insert(root->left, key);  // key가 루트의 key보다 작으면 왼쪽 서브트리에 삽입
    else
        root->right = insert(root->right, key);  // key가 루트의 key보다 크면 오른쪽 서브트리에 삽입
    return root;
}

void postOrder(TreeNode* root) {
    if (!root) return;          // 루트가 NULL이면 리턴
    postOrder(root->left);      // 왼쪽 서브트리를 후위 순회
    postOrder(root->right);     // 오른쪽 서브트리를 후위 순회
    cout << root->key << "\n";  
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    vector<int> preOrder;
    int key;

    while (cin >> key) {
        preOrder.push_back(key);
    }

    TreeNode* root = NULL;
    for (int key : preOrder) {
        root = insert(root, key);
    }
    postOrder(root);

    return 0;
}