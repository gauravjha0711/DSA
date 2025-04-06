#include<bits/stdc++.h>
using namespace std;
int solve(string &s,string &t,int i,int j){
    if(j==t.size()) return 1;
    if(i==s.size()) return 0;
    int ans =0;
    if(s[i]==t[j]) 
        ans+= solve(s,t,i+1,j+1);
    ans+=solve(s,t,i+1,j);
    return ans;
}
int solveMem(string &s,string &t,int i,int j,vector<vector<int>> &dp){
    if(j==t.size()) return 1;
    if(i==s.size()) return 0;
    if(dp[i][j]!=-1) return dp[i][j];
    int ans =0;
    if(s[i]==t[j]) 
        ans+= solveMem(s,t,i+1,j+1,dp);
    ans+=solveMem(s,t,i+1,j,dp);
    return dp[i][j] = ans;
}
int solveTab(string &s,string &t,vector<vector<unsigned long long>> &dp){
    for(int x=0;x<=s.size();x++){
        dp[x][t.size()] =1;
    }
    for(int i=s.size()-1;i>=0;i--){
        for(int j=t.size()-1;j>=0;j--){
            long long ans =0;
            if(s[i]==t[j]) 
                ans+=dp[i+1][j+1];
            ans+=dp[i+1][j];
            dp[i][j] = ans;
        }
    }
    return static_cast<int>(dp[0][0]);
}
int numDistinct(string s, string t) {
    // return solve(s,t,0,0);

    // vector<vector<int>> dp(s.size()+1,vector<int>(t.size()+1,-1));
    // return solveMem(s,t,0,0,dp);

    vector<vector<unsigned long long>> dp(s.size()+1,vector<unsigned long long>(t.size()+1,0));
    return solveTab(s,t,dp);
}
int main(){
    string s = "rabbbit", t = "rabbit";
    cout << numDistinct(s, t) << endl; // Output: 3
    return 0;
}