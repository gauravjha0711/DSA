#include<bits/stdc++.h>
using namespace std;
int topDown(int n, vector<int> &dp){
    if(n ==1 || n==0){
        return n;
    }
    if(dp[n] != -1){
        return dp[n];
    }
    dp[n] = topDown(n-1,dp) + topDown(n-2,dp);
    return dp[n];
}

int bottomUp(int n){
    vector<int> dp(n+1,-1);
    dp[0]=0;
    if(n==0){
        return dp[0];
    }
    dp[1]=1;
    if(n==1){
        return dp[1];
    }
    for(int i=2;i<=n;i++){
        dp[i] = dp[i-1]+dp[i-2];
    }
    return dp[n];
}
int fib(int n) {
    // int ans = solve(n);
    // return ans;

    // vector<int> dp(n+1,-1);
    // return topDown(n,dp);

    return bottomUp(n);
}
int main(){
    int n = 10;
    cout<<fib(n)<<endl;
    return 0;
}