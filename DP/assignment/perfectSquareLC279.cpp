#include<bits/stdc++.h>
using namespace std;
int solveRec(int n){
    if(n==0){
        return 1;
    }
    if(n<0){
        return 0;
    }
    int ans = INT_MAX;
    int i =1;
    int end = sqrt(n);
    while(i<=end){
        int perfectSquare = i*i;
        int numberOfPerfectSquares = 1 + solveRec(n-perfectSquare);
        if(numberOfPerfectSquares<ans){
            ans = numberOfPerfectSquares;
        }
        i++;
    }
    return ans;
}
int solveMem(int n,vector<int> &dp){
    if(n==0){
        return 1;
    }
    if(n<0){
        return 0;
    }
    if(dp[n]!=-1){
        return dp[n];
    }
    int ans = INT_MAX;
    int i =1;
    int end = sqrt(n);
    while(i<=end){
        int perfectSquare = i*i;
        int numberOfPerfectSquares = 1 + solveMem(n-perfectSquare,dp);
        if(numberOfPerfectSquares<ans){
            ans = numberOfPerfectSquares;
        }
        i++;
    }
    dp[n] = ans;
    return dp[n];
}
int solveTab(int n){
    vector<int> dp(n+1,-1);
    dp[0] = 1;
    for(int j=1;j<=n;j++){
        int ans = INT_MAX;
        int i =1;
        int end = sqrt(j);
        while(i<=end){
            int perfectSquare = i*i;
            int numberOfPerfectSquares = 1 + dp[j-perfectSquare];
            if(numberOfPerfectSquares<ans){
                ans = numberOfPerfectSquares;
            }
            i++;
        }
        dp[j] = ans;
    }
    return dp[n];
}
int numSquares(int n) {
    // return solveRec(n)-1;

    // vector<int> dp(n+1,-1);
    // return solveMem(n,dp)-1;

    return solveTab(n)-1;
}
int main(){
    int n = 12;
    cout<<numSquares(n)<<endl;
    return 0;
}