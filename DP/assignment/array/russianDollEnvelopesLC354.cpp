#include<bits/stdc++.h>
using namespace std;
int solve(vector<vector<int>>& env,int pre, int i){
    if(i==env.size()) return 0;
    int include = INT_MIN;
    if(pre==-1 || (env[pre][0]<env[i][0] && env[pre][1]<env[i][1]))
        include = 1+solve(env,i,i+1);
    int exclude = solve(env,pre,i+1);
    return max(include,exclude);
}
int solveMem(vector<vector<int>>& env,int pre, int i,vector<vector<int>> &dp){
    if(i==env.size()) return 0;
    if(dp[pre+1][i]!=-1) return dp[pre+1][i];
    int include = INT_MIN;
    if(pre==-1 || (env[pre][0]<env[i][0] && env[pre][1]<env[i][1]))
        include = 1+solveMem(env,i,i+1,dp);
    int exclude = solveMem(env,pre,i+1,dp);
    return dp[pre+1][i] = max(include,exclude);
}
static bool comp(vector<int>&a, vector<int>&b){
    if(a[0]==b[0]) return a[1]>b[1];
    return a[0]<b[0];
}
int solveOptimal(vector<vector<int>> &arr){
    sort(arr.begin(),arr.end(),comp);
    if(arr.size()==0){
        return 0;
    }
    vector<int> ans;
    ans.push_back(arr[0][1]);
    for(int i=1;i<arr.size();i++){
        if(arr[i][1]>ans.back()){
            ans.push_back(arr[i][1]);
        }
        else{
            int index = lower_bound(ans.begin(),ans.end(),arr[i][1]) - ans.begin();
            ans[index] = arr[i][1];
        }
    }
    return ans.size();
}
int maxEnvelopes(vector<vector<int>>& envelopes) {
    // sort(envelopes.begin(),envelopes.end());
//     return solve(envelopes,-1,0);

    // vector<vector<int>>dp(envelopes.size()+1,vector<int>(envelopes.size()+1,-1));
    // return solveMem(envelopes,-1,0,dp);

    return solveOptimal(envelopes);
}
int main(){
    vector<vector<int>> envelopes = {{5,4},{6,4},{6,7},{2,3}};
    cout << maxEnvelopes(envelopes) << endl; // Output: 3
    return 0;
}