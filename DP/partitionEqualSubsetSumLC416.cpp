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

    vector<vector<int>> dp(nums.size(), vector<int>(target+1, -1));
    return solveMemo(nums,index,target,dp);
}
int main(){
    vector<int> nums = {1,5,11,5};
    cout<<canPartition(nums)<<endl;
    return 0;
}