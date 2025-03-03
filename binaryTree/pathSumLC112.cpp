#include <iostream>
using namespace std;

class TreeNode {
public:
    int val;
    TreeNode* left;
    TreeNode* right;

    TreeNode(int value) {
        val = value;
        left = right = NULL;
    }
};

// Function to check if there is a root-to-leaf path with the given sum
bool hasPathSum(TreeNode* root, int targetSum) {
    if(root==NULL){
        return false;
    }
    targetSum-=root->val;
    if(root->left==NULL && root->right==NULL){
        if(targetSum==0){
            return true; 
        }
        else{
        return false;
        }
    }
    bool leftAns = hasPathSum(root->left, targetSum);
    bool rightAns = hasPathSum(root->right, targetSum);
    return leftAns || rightAns;
}

int main() {
    TreeNode* root = new TreeNode(5);
    root->left = new TreeNode(4);
    root->right = new TreeNode(8);
    root->left->left = new TreeNode(11);
    root->right->left = new TreeNode(13);
    root->right->right = new TreeNode(4);
    root->left->left->left = new TreeNode(7);
    root->left->left->right = new TreeNode(2);
    root->right->right->right = new TreeNode(1);

    int targetSum = 22;
    if (hasPathSum(root, targetSum)) {
        cout << "Path with sum " << targetSum << " exists.\n";
    } else {
        cout << "No path with sum " << targetSum << " found.\n";
    }

    return 0;
}
