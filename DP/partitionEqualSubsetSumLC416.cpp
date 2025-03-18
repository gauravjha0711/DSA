#include<bits/stdc++.h>
using namespace std;
bool solve(vector<int> &nums, int index, int target){
    if(index>=nums.size()){
        return 0;
    }
    if(target < 0){
        return 0;
    }
    if(target ==0){
        return 1;
    }
    int include = solve(nums,index+1,target-nums[index]);
    int exclude = solve(nums,index+1,target);
    return (include || exclude);
}
bool solveMemo(vector<int> &nums, int index, int target,vector<vector<int>> &dp){
    if(index>=nums.size()){
        return 0;
    }
    if(target < 0){
        return 0;
    }
    if(target ==0){
        return 1;
    }
    if(dp[index][target]!=-1){
        return dp[index][target];
    }
    int include = solveMemo(nums,index+1,target-nums[index],dp);
    int exclude = solveMemo(nums,index+1,target,dp);
    dp[index][target] = (include || exclude);
    return dp[index][target];
}
bool solveUsingTabulation(vector<int> &nums, int target){
    int n = nums.size();
    vector<vector<int>> dp(n+1,vector<int>(target+1,0));
    for(int i=0;i<=n;i++){
        dp[i][0] = 1;
    }
    for(int index = n-1;index>=0;index--){
        for(int t=1;t<=target;t++){
            bool include = 0;
            if(t-nums[index]>=0){
                include = dp[index+1][t-nums[index]];
            }
            bool exclude = dp[index+1][t];
            dp[index][t] = (include || exclude);
        }
    }
    return dp[0][target];
}
bool solveUsingSpaceOpt(vector<int> &nums, int target){
    int n = nums.size();
    vector<int> cur(target+1, 0);
    vector<int> next(target+1,0);
    for(int i=0;i<n;i++){
        next[0] = 1;
    }
    for(int index = n-1;index>=0;index--){
        for(int t=1;t<=target;t++){
            bool include = 0;
            if(t-nums[index]>=0){
                include = next[t-nums[index]];
            }
            bool exclude = next[t];
            cur[t] = (include || exclude);
        }
        // cur = next;
        next = cur;
    }
    return cur[target];
}
bool canPartition(vector<int>& nums) {
    int sum=0;
    int n = nums.size();
    for(int i=0;i<n;i++){
        sum += nums[i];
    }
    if(sum&1){
        return false; 
    }
    int target = sum/2;
    int index = 0;
    // return solve(nums,index,target);

    // vector<vector<int>> dp(nums.size(), vector<int>(target+1, -1));
    // return solveMemo(nums,index,target,dp);

    // return solveUsingTabulation(nums,target);

    return solveUsingSpaceOpt(nums,target);
}
int main(){
    vector<int> nums = {1,5,11,5};
    cout<<canPartition(nums)<<endl;
    return 0;
}