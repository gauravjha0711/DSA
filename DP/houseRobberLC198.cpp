#include<bits/stdc++.h>
using namespace std;
int memo(vector<int> &nums, int n, vector<int> &dp){
    if(n==0){
        return 0;
    }
    if(n==1){
        return nums[0];
    }
    if(dp[n]!=-1){
        return dp[n];
    }
    int include = memo(nums,n-2,dp) + nums[n-1];
    int exclude = memo(nums,n-1,dp)+0;
    dp[n] = max(include,exclude);
    return dp[n];
}
int tabulation(vector<int> &nums,int n){
    vector<int> dp(n+1,0);
    dp[0] = 0;
    for(int i=1;i<=n;i++){
        int temp = 0;
        if(i-2>=0){
            temp = dp[i-2];
        }
        int include = temp + nums[i-1];
        int exclude = dp[i-1] + 0;

        dp[i] = max(include, exclude);
    }
    return dp[n];
}
// Space Optimized
int spaceOpt(vector<int> &nums,int n){
    int prev2=0;
    int prev1=nums[0];
    int cur=0;
    for(int i=1;i<n;i++){
        int temp = 0;
        if(i-2>=0){
            temp = prev2;
        }
        int include = temp + nums[i];
        int exclude = prev1 + 0;
        cur = max(include, exclude);
        prev2=prev1;
        prev1=cur;
    }
    return prev1;
}
int rob(vector<int>& nums) {
    int n =nums.size();
    // vector<int> dp(n+1,-1);
    // return memo(nums,n,dp);

    // return tabulation(nums,n);

    return spaceOpt(nums,n);
}
int main(){
    vector<int> nums = {2,7,9,3,1};
    cout<<rob(nums)<<endl;
    return 0;
}