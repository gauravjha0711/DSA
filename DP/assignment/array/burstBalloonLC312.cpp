#include<bits/stdc++.h>
using namespace std;
int solve(vector<int>&nums,int start,int end){
    if(start>end) return 0;
    int coin = INT_MIN;
    for(int i=start;i<=end;i++){
        coin=max(coin,nums[start-1]*nums[i]*nums[end+1]+solve(nums,start,i-1)+solve(nums,i+1,end));
    }
    return coin;
}
int solveMem(vector<int>&nums,int start,int end,vector<vector<int>>&dp){
    if(start>end) return 0;
    if(dp[start][end]!=-1) return dp[start][end];
    int coin = INT_MIN;
    for(int i=start;i<=end;i++){
        coin=max(coin,nums[start-1]*nums[i]*nums[end+1]+solveMem(nums,start,i-1,dp)+solveMem(nums,i+1,end,dp));
    }
    return dp[start][end] = coin;
}
int solveTab(vector<int>& nums, int start, int end) {
    int n = nums.size();
    vector<vector<long long>> dp(n, vector<long long>(n, 0));
    for (int start = n - 2; start >= 1; start--) {
        for (int end = start; end <= n - 2; end++) {
            long long coin = LLONG_MIN;
            for (int i = start; i <= end; i++) {
                long long current = 1LL * nums[start - 1] * nums[i] * nums[end + 1] +
                                    dp[start][i - 1] + dp[i + 1][end];
                coin = max(coin, current);
            }
            dp[start][end] = coin;
        }
    }
    return (int)dp[1][n - 2];
}
int maxCoins(vector<int>& nums) {
    nums.insert(nums.begin(),1);
    nums.insert(nums.end(),1);
    // return solve(nums,1,nums.size()-2);

    // vector<vector<int>> dp(nums.size(),vector<int>(nums.size(),-1));
    // return solveMem(nums,1,nums.size()-2,dp);

    return solveTab(nums,1,nums.size()-2);
}
int main(){
    vector<int> nums = {3,1,5,8};
    cout << maxCoins(nums) << endl; // Output: 167
    return 0;
}