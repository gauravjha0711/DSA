#include<bits/stdc++.h>
using namespace std;
class TreeNode {
public:
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};
vector<TreeNode*> solve(int start, int end){
    if(start>end) return {0};
    if(start==end) return {new TreeNode(start)};
    vector<TreeNode*> ans;
    for(int i=start;i<=end;i++){
        vector<TreeNode*>left = solve(start,i-1);
        vector<TreeNode*>right = solve(i+1,end);
        for(int j=0;j<left.size();j++){
            for(int k=0;k<right.size();k++){
                TreeNode* root = new TreeNode(i);
                root->left = left[j];
                root->right = right[k];
                ans.push_back(root);
            }
        }
    }
    return ans;
}
vector<TreeNode*> solveMem(int start, int end,map<pair<int,int>,vector<TreeNode*>>&dp){
    if(start>end) return {0};
    if(start==end) return {new TreeNode(start)};
    if(dp.find({start,end})!=dp.end()) return dp[{start,end}];
    vector<TreeNode*> ans;
    for(int i=start;i<=end;i++){
        vector<TreeNode*>left = solveMem(start,i-1,dp);
        vector<TreeNode*>right = solveMem(i+1,end,dp);
        for(int j=0;j<left.size();j++){
            for(int k=0;k<right.size();k++){
                TreeNode* root = new TreeNode(i);
                root->left = left[j];
                root->right = right[k];
                ans.push_back(root);
            }
        }
    }
    return dp[{start,end}] = ans;
}
vector<TreeNode*> generateTrees(int n) {
    if(n==0) return {};
    // return solve(1,n);

    map<pair<int,int>,vector<TreeNode*>>dp;
    return solveMem(1,n,dp);
}
int main() {
    int n = 3; // Example input
    vector<TreeNode*> trees = generateTrees(n);
    
    // Print the number of unique BSTs generated
    cout << "Number of unique BSTs: " << trees.size() << endl;
    
    return 0;
}