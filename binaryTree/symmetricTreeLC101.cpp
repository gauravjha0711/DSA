#include <iostream>
using namespace std;

class TreeNode {
public:
    int val;
    TreeNode* left;
    TreeNode* right;

    TreeNode(int x) {
        val = x;
        left = right = nullptr;
    }
};

// Function to check if two trees are mirror images of each other
bool isMirror(TreeNode* p, TreeNode* q) {
    if (!p && !q) {
        return true;
    }
    if (p && q) {
        return (p->val == q->val) && isMirror(p->left, q->right) 
            && isMirror(p->right, q->left);
    }
    return false;
}

// Function to check if a tree is symmetric
bool isSymmetric(TreeNode* root) {
    if (!root) return true;
    return isMirror(root->left, root->right);
}

// Main function to test the implementation
int main() {
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(2);
    root->left->left = new TreeNode(3);
    root->left->right = new TreeNode(4);
    root->right->left = new TreeNode(4);
    root->right->right = new TreeNode(3);

    if (isSymmetric(root)) {
        cout << "The tree is symmetric." << endl;
    } else {
        cout << "The tree is not symmetric." << endl;
    }

    return 0;
}
