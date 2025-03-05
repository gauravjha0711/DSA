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

vector<vector<int>> verticalTraversal(TreeNode* root) {
    vector<vector<int>> ans;
    if (!root) return ans;
    
    queue<pair<TreeNode*, pair<int, int>>> q;
    q.push({root, {0, 0}});
    map<int, map<int, multiset<int>>> mp;
    
    while (!q.empty()) {
        auto front = q.front();
        q.pop();
        TreeNode*& node = front.first;
        auto& coordinate = front.second;
        int& row = coordinate.first;
        int& col = coordinate.second;
        
        mp[col][row].insert(node->val);
        
        if (node->left) {
            q.push({node->left, {row + 1, col - 1}});
        }
        if (node->right) {
            q.push({node->right, {row + 1, col + 1}});
        }
    }
    
    for (auto it : mp) {
        vector<int> vLine;
        for (auto colMapIt : it.second) {
            vLine.insert(vLine.end(), colMapIt.second.begin(), colMapIt.second.end());
        }
        ans.push_back(vLine);
    }
    return ans;
}

// Utility function to print the result
void printVerticalOrder(vector<vector<int>>& result) {
    for (const auto& vec : result) {
        for (int num : vec) {
            cout << num << " ";
        }
        cout << endl;
    }
}

int main() {
    TreeNode* root = new TreeNode(3);
    root->left = new TreeNode(9);
    root->right = new TreeNode(20);
    root->right->left = new TreeNode(15);
    root->right->right = new TreeNode(7);
    
    vector<vector<int>> result = verticalTraversal(root);
    
    cout << "Vertical Order Traversal:" << endl;
    printVerticalOrder(result);
    
    return 0;
}
