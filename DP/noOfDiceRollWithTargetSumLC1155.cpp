#include<bits/stdc++.h>
using namespace std;
long long int MOD = 1000000007;
int solveRec(int n, int k, int target){
    if(n<0){
        return 0;
    }
    if(n==0 && target==0)
        return 1;
    if(n==0 && target!=0)
        return 0;
    if(n!=0 && target==0)
        return 0;
    int ans = 0;
    for(int i=1;i<=k;i++){
        ans += solveRec(n-1,k,target-i);
    }
    return ans;
}
int solveMemo(int n, int k, int target, vector<vector<int>> &dp){
    if(n<0){
        return 0;
    }
    if(n==0 && target==0)
        return 1;
    if(n==0 && target!=0)
        return 0;
    if(n!=0 && target==0)
        return 0;
    long long int ans = 0;
    if(dp[n][target]!=-1){
        return dp[n][target];
    }
    for(int i=1;i<=k;i++){
        long long int ansRec = 0;
        if(target-i>=0){
            ansRec = solveMemo(n-1,k,target-i,dp);
        }
        ans = (ans%MOD + ansRec%MOD)%MOD;
    }
    dp[n][target] = ans;
    return dp[n][target];
}
int solveTab(int n,int k, int target){
    vector<vector<int>> dp(n+1,vector<int>(target+1,0));
    dp[0][0]=1;
    for(int index=1;index<=n;index++){
        for(int t=1;t<=target;t++){
            long long int ans = 0;
            for(int i=1;i<=k;i++){
                long long int ansRec = 0;
                if(t-i>=0){
                    ansRec = dp[index-1][t-i];
                }
                ans = (ans%MOD + ansRec%MOD)%MOD;
            }
            dp[index][t] = ans;
        }
    }
    return dp[n][target];
}
int solveSopt(int n,int k, int target){
    vector<int> cur(target+1,0);
    vector<int> prev(target+1,0);
    prev[0]=1;
    for(int index=1;index<=n;index++){
        for(int t=1;t<=target;t++){
            long long int ans = 0;
            for(int i=1;i<=k;i++){
                long long int ansRec = 0;
                if(t-i>=0){
                    ansRec = prev[t-i];
                }
                ans = (ans%MOD + ansRec%MOD)%MOD;
            }
            cur[t] = ans;
        }
        prev = cur;
    }
    return cur[target];
}
int numRollsToTarget(int n, int k, int target) {
    // return solveRec(n,k,target);

    // vector<vector<int>> dp(n+1, vector<int>(target+1, -1));
    // return solveMemo(n,k,target,dp);

    // return solveTab(n,k,target);

    return solveSopt(n,k,target);
}
int main(){
    int n = 30;
    int k = 30;
    int target = 500;
    cout<<numRollsToTarget(n,k,target)<<endl;
    return 0;
}