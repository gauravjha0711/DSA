#include<bits/stdc++.h>
using namespace std;
int solve(int n, int k){
    if(n==1){
        return k;
    }
    if(n==2){
        return (k+k*(k-1));
    }
    int ans = (solve(n-2,k)+solve(n-1,k))*(k-1);
    return ans;
}
// Memoization
int solveMemo(int n, int k,vector<int> &dp){
    if(n==1){
        return k;
    }
    if(n==2){
        return (k+k*(k-1));
    }
    if(dp[n]!=-1){
        return dp[n];
    }
    dp[n] = (solveMemo(n-2,k,dp)+solveMemo(n-1,k,dp))*(k-1);
    return dp[n]; 
}
// Tabulation
int tabul(int n, int k){
    vector<int> dp(n+1,0);
    dp[1]=k;
    dp[2]= (k+k*(k-1));
    for(int i=3;i<=n;i++){
        dp[i] = (dp[i-2]+dp[i-1])*(k-1);
    }
    return dp[n];
}
//space optimized
int spaceOpt(int n, int k){
    int prev1=k;
    int prev2=(k+k*(k-1));
    int cur=0;
    for(int i=3;i<=n;i++){
        cur = (prev2+prev1)*(k-1);
        prev2=prev1;
        prev1=cur;
    }
    return prev1;
}
int countWays(int n, int k) {
    // code here
    // return solve(n,k);
    // vector<int> dp(n+1,-1);
    // int ans = solveMemo(n,k,dp);
    
    // int ans = tabul(n,k);

    int ans = spaceOpt(n,k);
    return ans;
}
int main(){
    int n=3,k=2;
    cout<<countWays(n,k)<<endl;
    return 0;
}