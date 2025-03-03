#include <iostream>
using namespace std;

class TreeNode {
public:
    int data;
    TreeNode* left;
    TreeNode* right;

    TreeNode(int val) {
        data = val;
        left = NULL;
        right = NULL;
    }
};

int maxDepth(TreeNode* root) {
    if (root == NULL) {
        return 0;
    }
    return max(maxDepth(root->left), maxDepth(root->right)) + 1;
}

int main() {
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(5);

    cout << "Maximum depth of the tree: " << maxDepth(root) << endl;

    return 0;
}
