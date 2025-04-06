#include<bits/stdc++.h>
using namespace std;
void convertStr(vector<string>& strs,vector<pair<int,int>>&nums){
    for(auto str : strs){
        int zeros = 0, ones = 0;
        for(auto i : str){
            if(i=='0') zeros++;
            else ones++;
        }
        nums.push_back({zeros,ones});
    }
}
int solve(vector<pair<int,int>>&nums,int i, int m,int n){
    if(i==nums.size()) return 0;
    int zeros = nums[i].first;
    int ones = nums[i].second;
    int include = 0, exclude = 0;
    if(m-zeros>=0 && n-ones>=0)
        include = 1+solve(nums,i+1,m-zeros,n-ones);
    exclude = solve(nums,i+1,m,n);
    return max(include,exclude);
}
int solveMem(vector<pair<int,int>>&nums,int i, int m,int n,vector<vector<vector<int>>>&dp){
    if(i==nums.size()) return 0;
    if(dp[i][m][n]!=-1) return dp[i][m][n];
    int zeros = nums[i].first;
    int ones = nums[i].second;
    int include = 0, exclude = 0;
    if(m-zeros>=0 && n-ones>=0)
        include = 1+solveMem(nums,i+1,m-zeros,n-ones,dp);
    exclude = solveMem(nums,i+1,m,n,dp);
    return dp[i][m][n] = max(include,exclude);
}
int solveTab(vector<pair<int,int>>&nums,int i, int m,int n){
    vector<vector<vector<int>>> dp(nums.size()+1,vector<vector<int>>(m+1,vector<int>(n+1,0)));
    for(int i=nums.size()-1;i>=0;i--){
        for(int j=0;j<=m;j++){
            for(int k=0;k<=n;k++){
                int zeros = nums[i].first;
                int ones = nums[i].second;
                int include = 0, exclude = 0;
                if(j-zeros>=0 && k-ones>=0)
                    include = 1+dp[i+1][j-zeros][k-ones];
                exclude = dp[i+1][j][k];
                dp[i][j][k] = max(include,exclude);
            }
        }
    }
    return dp[0][m][n];
}
int findMaxForm(vector<string>& strs, int m, int n) {
    vector<pair<int,int>>nums;
    convertStr(strs,nums);
    
    // return solve(nums,0,m,n);

    // vector<vector<vector<int>>> dp(strs.size()+1,vector<vector<int>>(m+1,vector<int>(n+1,-1)));
    // return solveMem(nums,0,m,n,dp);

    return solveTab(nums,0,m,n);
}
int main(){
    vector<string> strs = {"10", "0001", "111001", "1", "0"};
    int m = 5, n = 3;
    cout<<findMaxForm(strs,m,n)<<endl;
    return 0;
}