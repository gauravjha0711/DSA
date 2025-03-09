#include <bits/stdc++.h>
using namespace std;

// Definition for a Binary Tree Node
class TreeNode {
public:
    int val;
    TreeNode* left;
    TreeNode* right;

    // Constructor
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

// Function to calculate range sum of BST
int rangeSumBST(TreeNode* root, int low, int high) {
    if (!root) return 0;  // Base case: if root is null, return 0
    
    int ans = 0;
    bool isRange = false;

    // Check if the current node's value is within the range
    if (root->val >= low && root->val <= high) {
        isRange = true;
        ans += root->val;
    }
    
    // Recurse on left and right subtrees based on the current node's value
    if (isRange) {
        ans += rangeSumBST(root->left, low, high) + rangeSumBST(root->right, low, high);
    } 
    else if (root->val < low) {
        ans += rangeSumBST(root->right, low, high);  // Only recurse right since left subtree values are smaller than low
    } 
    else if (root->val > high) {
        ans += rangeSumBST(root->left, low, high);  // Only recurse left since right subtree values are larger than high
    }

    return ans;
}

// Helper function to insert nodes into the BST
TreeNode* insert(TreeNode* root, int key) {
    if (!root) return new TreeNode(key);
    if (key < root->val) root->left = insert(root->left, key);
    else root->right = insert(root->right, key);
    return root;
}

// Main function to test the solution
int main() {
    TreeNode* root = NULL;

    // Construct the tree [10, 5, 15, 3, 7, 13, 18]
    root = insert(root, 10);
    root = insert(root, 5);
    root = insert(root, 15);
    root = insert(root, 3);
    root = insert(root, 7);
    root = insert(root, 13);
    root = insert(root, 18);

    int low = 7, high = 15;
    
    // Get the range sum
    int result = rangeSumBST(root, low, high);
    
    // Print the result
    cout << "Range Sum of BST between " << low << " and " << high << ": " << result << endl;

    return 0;
}
