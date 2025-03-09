#include <bits/stdc++.h>
using namespace std;

// Definition for a binary tree node.
class TreeNode {
public:
    int val;
    TreeNode* left;
    TreeNode* right;

    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

// Function to build BST from preorder traversal
TreeNode* build(int &i, int min, int max, vector<int> &preorder) {
    if (i >= preorder.size()) {
        return NULL;
    }
    TreeNode* root = NULL;
    if (preorder[i] > min && preorder[i] < max) {
        root = new TreeNode(preorder[i++]);
        root->left = build(i, min, root->val, preorder);
        root->right = build(i, root->val, max, preorder);
    }
    return root;
}

// Function to construct BST from preorder
TreeNode* bstFromPreorder(vector<int>& preorder) {
    int min = INT_MIN, max = INT_MAX, i = 0;
    return build(i, min, max, preorder);
}

// Function to print inorder traversal (for checking correctness)
void inorder(TreeNode* root) {
    if (!root) return;
    inorder(root->left);
    cout << root->val << " ";
    inorder(root->right);
}

int main() {
    vector<int> preorder = {8, 5, 1, 7, 10, 12};
    
    TreeNode* root = bstFromPreorder(preorder);

    cout << "Inorder Traversal of BST: ";
    inorder(root);
    cout << endl;

    return 0;
}
