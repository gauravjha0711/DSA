#include<bits/stdc++.h>
using namespace std;
int solveRec(string a,string b,int i,int j){
    if(i==a.length())
        return 0;
    if(j==b.length())
        return 0;
    int ans = 0;
    if(a[i]==b[j])
        ans = 1+solveRec(a,b,i+1,j+1);
    else
        ans = 0+max(solveRec(a,b,i+1,j),solveRec(a,b,i,j+1));
    return ans;
}
int solveMem(string &a,string &b,int i,int j,vector<vector<int>> &dp){
    if(i==a.length())
        return 0;
    if(j==b.length())
        return 0;
    if(dp[i][j]!=-1){
        return dp[i][j];
    }
    int ans = 0;
    if(a[i]==b[j])
        ans = 1+solveMem(a,b,i+1,j+1,dp);
    else
        ans = 0+max(solveMem(a,b,i+1,j,dp),solveMem(a,b,i,j+1,dp));
    dp[i][j] = ans;
    return dp[i][j];
}
int solveTab(string a, string b){
    vector<vector<int>> dp(a.length()+1,vector<int>(b.length()+1,0));
    for(int i=a.length()-1;i>=0;i--){
        for(int j=b.length()-1;j>=0;j--){
            int ans = 0;
            if(a[i]==b[j])
                ans = 1+dp[i+1][j+1];
            else
                ans = 0+max(dp[i+1][j],dp[i][j+1]);
            dp[i][j] = ans;
        }
    }
    return dp[0][0];
}
int longestCommonSubsequence(string text1, string text2) {
    // int i=0, j=0;
    // return solveRec(text1,text2,i,j);

    // vector<vector<int>> dp(text1.length()+1,vector<int>(text2.length()+1,-1));
    // return solveMem(text1,text2,i,j,dp);

    return solveTab(text1,text2);
}
int main(){
    string a = "abcde";
    string b = "ace";
    cout<<longestCommonSubsequence(a,b)<<endl;
    return 0;
}