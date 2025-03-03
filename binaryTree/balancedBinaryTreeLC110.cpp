#include <iostream>
#include <cmath>
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
int height(TreeNode* root) {
    if (!root) return 0;
    return max(height(root->left), height(root->right)) + 1;
}
bool isBalanced(TreeNode* root) {
    if(root==nullptr){
        return true;
    }
    int leftHeight = height(root->left);
    int rightHeight = height(root->right);
    int diff = abs(leftHeight-rightHeight);
    bool currNode = (diff<=1);
    bool leftAns = isBalanced(root->left);
    bool rightAns = isBalanced(root->right);
    if(currNode && leftAns && rightAns){
        return true;
    }
    else{
        return false;
    }
}

int main() {
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(5);
    
    if (isBalanced(root)) {
        cout << "Tree is balanced\n";
    } else {
        cout << "Tree is not balanced\n";
    }

    return 0;
}
