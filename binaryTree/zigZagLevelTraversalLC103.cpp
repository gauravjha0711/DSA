#include <iostream>
#include <vector>
#include <queue>
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

// Function for zigzag level order traversal
vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
    vector<vector<int>> ans;
    if (!root) return ans;

    bool LtoRdir = true;  // Left to Right direction
    queue<TreeNode*> q;
    q.push(root);

    while (!q.empty()) {
        int width = q.size();
        vector<int> oneLevel(width);

        for (int i = 0; i < width; i++) {
            TreeNode* front = q.front();
            q.pop();

            // Decide the index based on zigzag direction
            int index = LtoRdir ? i : (width - i - 1);
            oneLevel[index] = front->val;

            if (front->left) {
                q.push(front->left);
            }
            if (front->right) {
                q.push(front->right);
            }
        }

        LtoRdir = !LtoRdir; // Toggle direction for next level
        ans.push_back(oneLevel);
    }
    return ans;
}

// Main function to test the implementation
int main() {
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(5);
    root->right->left = new TreeNode(6);
    root->right->right = new TreeNode(7);

    vector<vector<int>> result = zigzagLevelOrder(root);

    cout << "Zigzag Level Order Traversal:" << endl;
    for (const auto& level : result) {
        for (int val : level) {
            cout << val << " ";
        }
        cout << endl;
    }

    return 0;
}
