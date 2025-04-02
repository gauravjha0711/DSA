#include<bits/stdc++.h>
using namespace std;
class TreeNode {
public:
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};
int solveRec(TreeNode* root){
    if(!root) return 0;
    int addRoot = 0, notAddRoot = 0;
    addRoot+=root->val;
    if(root->left){
        addRoot+=solveRec(root->left->left)+solveRec(root->left->right);
    } 
    if(root->right){
        addRoot+=solveRec(root->right->left)+solveRec(root->right->right);
    }
    notAddRoot+=solveRec(root->left)+solveRec(root->right);
    return max(addRoot,notAddRoot);
}
int solvedp(TreeNode* root,unordered_map<TreeNode*,int>&dp){
    if(!root) return 0;
    if(dp.find(root)!=dp.end()) return dp[root];
    int addRoot = 0, notAddRoot = 0;
    addRoot+=root->val;
    if(root->left){
        addRoot+=solvedp(root->left->left,dp)+solvedp(root->left->right,dp);
    } 
    if(root->right){
        addRoot+=solvedp(root->right->left,dp)+solvedp(root->right->right,dp);
    }
    notAddRoot+=solvedp(root->left,dp)+solvedp(root->right,dp);
    return dp[root] = max(addRoot,notAddRoot);
}
int rob(TreeNode* root) {
    // return solveRec(root);

    unordered_map<TreeNode*,int>dp;
    return solvedp(root,dp);
}
int main(){
    TreeNode* root = new TreeNode(3);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->right = new TreeNode(3);
    root->right->right = new TreeNode(1);
    cout<<rob(root)<<endl;
    return 0;
}