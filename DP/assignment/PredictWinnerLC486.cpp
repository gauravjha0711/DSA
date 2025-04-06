#include<bits/stdc++.h>
using namespace std;
int solveRec(vector<int> &nums,int start,int end){
    if(start==end) return nums[start];
    int startDif = nums[start]-solveRec(nums,start+1,end);
    int endDif = nums[end]-solveRec(nums,start,end-1);
    return max(startDif,endDif);
}
int solveMem(vector<int> &nums,int start,int end,vector<vector<int>> &dp){
    if(start==end) return nums[start];
    if(dp[start][end]!=-1) return dp[start][end];
    int startDif = nums[start]-solveMem(nums,start+1,end,dp);
    int endDif = nums[end]-solveMem(nums,start,end-1,dp);
    return dp[start][end] = max(startDif,endDif);
}
int solveTab(vector<int> &nums,int start,int end,vector<vector<int>> &dp){
    for(int i=0;i<nums.size();i++) dp[i][i]=nums[i];
    int i = nums.size();
    for(int start=nums.size()-1;start>=0;start--){
        for(int end=i;end<nums.size();end++){
            int startDif = nums[start]-dp[start+1][end];
            int endDif = nums[end]-dp[start][end-1];
            dp[start][end] = max(startDif,endDif);
        }
        i--;
    }
    return dp[0][nums.size()-1];
}
bool predictTheWinner(vector<int>& nums) {
    // return solveRec(nums,0,nums.size()-1)>=0;

    // vector<vector<int>> dp(nums.size(),vector<int>(nums.size(),-1));
    // return solveMem(nums,0,nums.size()-1,dp)>=0;

    vector<vector<int>> dp(nums.size(),vector<int>(nums.size()+1,-1));
    return solveTab(nums,0,nums.size()-1,dp)>=0;
}
int main(){
    vector<int> nums = {1,5,2};
    cout<<predictTheWinner(nums)<<endl;
    return 0;
}