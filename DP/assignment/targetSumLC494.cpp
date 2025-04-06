#include<bits/stdc++.h>
using namespace std;
int solve(vector<int>& nums, int target,int i){
    if(i>=nums.size()) return target==0 ? 1:0;
    int plus = solve(nums,target-nums[i],i+1);
    int minus = solve(nums,target+nums[i],i+1);
    return plus+minus;
}
int solveMem(vector<int>& nums, int target,int i,map<pair<int,int>,int> &dp){
    if(i>=nums.size()) return target==0 ? 1:0;
    if(dp.find({i,target})!=dp.end()) return dp[{i,target}];
    int plus = solveMem(nums,target-nums[i],i+1,dp);
    int minus = solveMem(nums,target+nums[i],i+1,dp);
    return dp[{i,target}]= plus+minus;
}
int findTargetSumWays(vector<int>& nums, int target) {
    // return solve(nums,target,0);

    map<pair<int,int>,int> dp;//i,target,,no. of ways
    return solveMem(nums,target,0,dp);
}
int main(){
    vector<int> nums = {1,1,1,1,1};
    int target = 3;
    cout<<findTargetSumWays(nums,target)<<endl;
    return 0;
}