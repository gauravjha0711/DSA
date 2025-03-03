#include <iostream>
#include <vector>
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

// Helper function to find all root-to-leaf paths with the given sum
void solve(TreeNode* root, int targetSum, int sum, vector<int> temp, vector<vector<int>> &ans) {
    if (root == NULL) {
        return;
    }

    sum += root->val;
    temp.push_back(root->val);

    if (root->left == NULL && root->right == NULL) {
        if (sum == targetSum) {
            ans.push_back(temp);
        } else {
            return;
        }
    }

    solve(root->left, targetSum, sum, temp, ans);
    solve(root->right, targetSum, sum, temp, ans);
}

// Function to return all root-to-leaf paths where the sum equals targetSum
vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
    int sum = 0;
    vector<vector<int>> ans;
    vector<int> temp;
    solve(root, targetSum, sum, temp, ans);
    return ans;
}

// Function to print the list of paths
void printPaths(vector<vector<int>> paths) {
    if (paths.empty()) {
        cout << "No path with the given sum found.\n";
        return;
    }
    
    cout << "Paths with the given sum:\n";
    for (const auto& path : paths) {
        cout << "[ ";
        for (int num : path) {
            cout << num << " ";
        }
        cout << "]\n";
    }
}

int main() {
    // Creating the tree:
    TreeNode* root = new TreeNode(5);
    root->left = new TreeNode(4);
    root->right = new TreeNode(8);
    root->left->left = new TreeNode(11);
    root->right->left = new TreeNode(13);
    root->right->right = new TreeNode(4);
    root->left->left->left = new TreeNode(7);
    root->left->left->right = new TreeNode(2);
    root->right->right->left = new TreeNode(5);
    root->right->right->right = new TreeNode(1);

    int targetSum = 22;
    vector<vector<int>> result = pathSum(root, targetSum);
    printPaths(result);

    return 0;
}
