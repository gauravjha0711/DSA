#include <bits/stdc++.h>
using namespace std;

// Definition for a binary tree node
class TreeNode {
public:
    int val;
    TreeNode* left;
    TreeNode* right;
    
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

int ans = 0;

void pathFromOneRoot(TreeNode* root, long long sum) {
    if (!root) return;
    if (sum == root->val) {
        ans++;
    }
    pathFromOneRoot(root->left, sum - root->val);
    pathFromOneRoot(root->right, sum - root->val);
}

int pathSum(TreeNode* root, long long targetSum) {
    if (root) {
        pathFromOneRoot(root, targetSum);
        pathSum(root->left, targetSum);
        pathSum(root->right, targetSum);
    }
    return ans;
}

// Utility function to create a sample tree and test the function
int main() {
    TreeNode* root = new TreeNode(10);
    root->left = new TreeNode(5);
    root->right = new TreeNode(-3);
    root->left->left = new TreeNode(3);
    root->left->right = new TreeNode(2);
    root->right->right = new TreeNode(11);
    root->left->left->left = new TreeNode(3);
    root->left->left->right = new TreeNode(-2);
    root->left->right->right = new TreeNode(1);
    
    int result = pathSum(root, 8);
    
    cout << "Number of paths with sum 8: " << result << endl;
    
    return 0;
}