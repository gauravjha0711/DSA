#include<bits/stdc++.h>
using namespace std;
int solveRec(vector<int>& arr,int cur, int prev){
    if(cur>=arr.size()){
        return 0;
    }
    int include = 0;
    if(prev==-1 || arr[cur]>arr[prev]){
        include = 1 + solveRec(arr,cur+1,cur);
    }
    int exclude = solveRec(arr,cur+1,prev);
    int ans = max(include,exclude);
    return ans;
}
int solveMem(vector<int>& arr,int cur, int prev,vector<vector<int>> &dp){
    if(cur>=arr.size()){
        return 0;
    }
    if(dp[cur][prev+1]!=-1){
        return dp[cur][prev+1];
    }
    int include = 0;
    if(prev==-1 || arr[cur]>arr[prev]){
        include = 1 + solveMem(arr,cur+1,cur,dp);
    }
    int exclude = solveMem(arr,cur+1,prev,dp);
    dp[cur][prev+1] = max(include,exclude);
    return dp[cur][prev+1];
}
int solveTab(vector<int>& arr){
    int n =arr.size();
    vector<vector<int>> dp(n+1,vector<int>(n+1,0));
    for(int cur=n-1;cur>=0;cur--){
        for(int prev=cur-1;prev>=-1;prev--){
            int include = 0;
            if(prev==-1 || arr[cur]>arr[prev]){
                include = 1 + dp[cur+1][cur+1];
            }
            int exclude = dp[cur+1][prev+1];
            dp[cur][prev+1] = max(include,exclude);
        }
    }
    return dp[0][0];
}
int solveSo(vector<int>& arr){
    int n =arr.size();
    vector<int> curRow(n+1,0);
    vector<int> nextRow(n+1,0);
    for(int cur=n-1;cur>=0;cur--){
        for(int prev=cur-1;prev>=-1;prev--){
            int include = 0;
            if(prev==-1 || arr[cur]>arr[prev]){
                include = 1 + nextRow[cur+1];
            }
            int exclude = nextRow[prev+1];
            curRow[prev+1] = max(include,exclude);
        }
        nextRow = curRow;
    }
    return curRow[0];
}
int solveOptimal(vector<int> &arr){
    if(arr.size()==0){
        return 0;
    }
    vector<int> ans;
    ans.push_back(arr[0]);
    for(int i=1;i<arr.size();i++){
        if(arr[i]>ans.back()){
            ans.push_back(arr[i]);
        }
        else{
            int index = lower_bound(ans.begin(),ans.end(),arr[i]) - ans.begin();
            ans[index] = arr[i];
        }
    }
    return ans.size();
}
int lengthOfLIS(vector<int>& nums) {
    int cur=0, prev=-1;
    // return solveRec(nums,cur,prev);

    // vector<vector<int>> dp(nums.size(),vector<int>(nums.size()+1,-1));
    // return solveMem(nums,cur,prev,dp);

    // return solveTab(nums);

    // return solveSo(nums);

    return solveOptimal(nums);
}
int main(){
    vector<int> arr = {10,9,2,5,3,7,101,18};
    cout<<lengthOfLIS(arr)<<endl;
    return 0;
}