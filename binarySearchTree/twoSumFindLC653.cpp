#include <iostream>
#include <vector>
using namespace std;

// Definition for a binary tree node.
class TreeNode {
public:
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

// Helper function to perform inorder traversal of the BST
void addInorder(TreeNode* root, vector<int>& ans) {
    if (root == NULL) {
        return;
    }
    addInorder(root->left, ans);  // Traverse the left subtree
    ans.push_back(root->val);      // Add the current node's value
    addInorder(root->right, ans);  // Traverse the right subtree
}

// Function to check if there are two elements in the BST that sum up to k
bool findTarget(TreeNode* root, int k) {
    vector<int> ans;
    addInorder(root, ans);  // Perform inorder traversal to get the sorted values

    int s = 0;
    int e = ans.size() - 1;

    // Use two pointers to find if there's a pair that sums up to k
    while (s < e) {
        int sum = ans[s] + ans[e];
        if (sum == k) {
            return true;  // Found the pair
        }
        else if (sum > k) {
            e--;  // Decrease the sum by moving the right pointer left
        }
        else {
            s++;  // Increase the sum by moving the left pointer right
        }
    }
    return false;  // No pair found
}

int main() {
    // Example: Create a sample binary search tree
    TreeNode* root = new TreeNode(5);
    root->left = new TreeNode(3);
    root->right = new TreeNode(6);
    root->left->left = new TreeNode(2);
    root->left->right = new TreeNode(4);
    root->right->right = new TreeNode(7);

    int target = 9;
    if (findTarget(root, target)) {
        cout << "Yes, there are two elements whose sum is " << target << endl;
    } else {
        cout << "No, there are no two elements whose sum is " << target << endl;
    }
    return 0;
}