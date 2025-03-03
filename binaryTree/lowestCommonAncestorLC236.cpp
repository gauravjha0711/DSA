#include <iostream>
using namespace std;

class TreeNode {
public:
    int val;
    TreeNode* left;
    TreeNode* right;

    TreeNode(int value) {
        val = value;
        left = right = nullptr;
    }
};

// Function to find the Lowest Common Ancestor
TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
    if (root == nullptr || root == p || root == q) {
        return root;
    }

    TreeNode* leftAns = lowestCommonAncestor(root->left, p, q);
    TreeNode* rightAns = lowestCommonAncestor(root->right, p, q);

    if (leftAns == nullptr) return rightAns;
    if (rightAns == nullptr) return leftAns;

    return root;
}

int main() {
    TreeNode* root = new TreeNode(3);
    root->left = new TreeNode(5);
    root->right = new TreeNode(1);
    root->left->left = new TreeNode(6);
    root->left->right = new TreeNode(2);
    root->right->left = new TreeNode(0);
    root->right->right = new TreeNode(8);
    root->left->right->left = new TreeNode(7);
    root->left->right->right = new TreeNode(4);

    TreeNode* p = root->left;  // Node with value 5
    TreeNode* q = root->left->right->right; // Node with value 4

    TreeNode* lca = lowestCommonAncestor(root, p, q);
    if (lca) {
        cout << "Lowest Common Ancestor: " << lca->val << endl;
    } else {
        cout << "No common ancestor found!" << endl;
    }

    return 0;
}
