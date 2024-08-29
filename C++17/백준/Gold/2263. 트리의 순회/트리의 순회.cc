#include <algorithm>
#include <iostream>
#include <unordered_map>
#include <vector>

using namespace std;

typedef long long ll;
typedef vector<int> vec1;
typedef vector<vec1> vec2;
typedef vector<vec2> vec3;

vec1 inorder, postorder, preorder;
unordered_map<int, int> inorder_index_map;

void buildPreorder(int inStart, int inEnd, int postStart, int postEnd) {
    if (inStart > inEnd || postStart > postEnd) return;

    int root = postorder[postEnd];  
    preorder.push_back(root);

    int rootIndex = inorder_index_map[root];
    int leftSize = rootIndex - inStart;

    buildPreorder(inStart, rootIndex - 1, postStart, postStart + leftSize - 1);
    buildPreorder(rootIndex + 1, inEnd, postStart + leftSize, postEnd - 1);
}
void init() {
    cin.tie(NULL);
    cout.tie(NULL);
    ios::sync_with_stdio(false);
}

int main() {
    init();
    int n;
    cin >> n;

    inorder.resize(n);
    postorder.resize(n);
    preorder.reserve(n);

    for (int i = 0; i < n; ++i) cin >> inorder[i];
    for (int i = 0; i < n; ++i) cin >> postorder[i];
    for (int i = 0; i < n; ++i) inorder_index_map[inorder[i]] = i;

    buildPreorder(0, n - 1, 0, n - 1);
    for (int i = 0; i < n; ++i) cout << preorder[i] << " ";
    
    return 0;
}