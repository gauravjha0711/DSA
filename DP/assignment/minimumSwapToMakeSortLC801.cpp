#include<bits/stdc++.h>
using namespace std;
int solve(vector<int>& nums1, vector<int>& nums2,int i,int p1,int p2){
    if(i==nums1.size()) return 0;
    int swaps =INT_MAX, noswap = INT_MAX;
    if(p1<nums2[i] && p2<nums1[i]){
        swaps = 1+solve(nums1,nums2,i+1,nums2[i],nums1[i]);
    }
    if(p1<nums1[i] && p2<nums2[i])
        noswap = solve(nums1,nums2,i+1,nums1[i],nums2[i]);
    return min(swaps,noswap);
    
}
int solveMem(vector<int>& nums1, vector<int>& nums2,int i,int p1,int p2,vector<vector<int>> &dp,int isSwap){
    if(i==nums1.size()) return 0;
    if(dp[i][isSwap]!=-1) return dp[i][isSwap];
    int swaps =INT_MAX, noswap = INT_MAX;
    if(p1<nums2[i] && p2<nums1[i]){
        swaps = 1+solveMem(nums1,nums2,i+1,nums2[i],nums1[i],dp,1);
    }
    if(p1<nums1[i] && p2<nums2[i])
        noswap = solveMem(nums1,nums2,i+1,nums1[i],nums2[i],dp,0);
    return dp[i][isSwap] =  min(swaps,noswap);
    
}
int solveTab(vector<int>&nums1,vector<int>&nums2){
    vector<vector<int>> dp(nums1.size()+1,vector<int>(2,0));
    for(int i=nums1.size()-1;i>=1;i--){
        for(int j=1;j>=0;j--){
            int p1 = nums1[i-1];
            int p2 = nums2[i-1];
            if(j) swap(p1,p2);
            int swaps =INT_MAX, noswap = INT_MAX;
            if(p1<nums2[i] && p2<nums1[i]){
                swaps = 1+dp[i+1][1];
            }
            if(p1<nums1[i] && p2<nums2[i])
                noswap = dp[i+1][0];
            dp[i][j] =  min(swaps,noswap);
        }
    }
    return dp[1][0];
}
int minSwap(vector<int>& nums1, vector<int>& nums2) {
    // return solve(nums1,nums2,0,-1,-1);

    // vector<vector<int>> dp(nums1.size(),vector<int>(2,-1));
    // return solveMem(nums1,nums2,0,-1,-1,dp,1);

    nums1.insert(nums1.begin(),-1);
    nums2.insert(nums2.begin(),-1);
    return solveTab(nums1,nums2);
}
int main(){
    vector<int> nums1 = {1,3,5,4};
    vector<int> nums2 = {1,2,3,7};
    cout<<minSwap(nums1,nums2)<<endl;
    return 0;
}