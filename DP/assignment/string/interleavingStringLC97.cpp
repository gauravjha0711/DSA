#include<bits/stdc++.h>
using namespace std;
int solve(string &s1,string &s2,string&s3,int i,int j,int k){
    if(i==s1.size() && j==s2.size() && k==s3.size()) return true;
    bool flag = false;
    if(i<s1.size() && s1[i]==s3[k])
        flag = flag||solve(s1,s2,s3,i+1,j,k+1);
    if(j<s2.size() && s2[j]==s3[k])
        flag = flag||solve(s1,s2,s3,i,j+1,k+1);
    return flag;
}
int solveMem(string &s1,string &s2,string&s3,int i,int j,int k,vector<vector<vector<int>>>&dp){
    if(i==s1.size() && j==s2.size() && k==s3.size()) return true;
    if(dp[i][j][k] != -1) return dp[i][j][k];
    bool flag = false;
    if(i<s1.size() && s1[i]==s3[k])
        flag = flag||solveMem(s1,s2,s3,i+1,j,k+1,dp);
    if(j<s2.size() && s2[j]==s3[k])
        flag = flag||solveMem(s1,s2,s3,i,j+1,k+1,dp);
    return dp[i][j][k] = flag;
}
int solveTab(string &s1,string &s2,string&s3){
    vector<vector<vector<int>>> dp(s1.size()+1,vector<vector<int>>(s2.size()+1,vector<int>(s3.size()+1,0)));
    dp[s1.size()][s2.size()][s3.size()] = 1;
    for(int i=s1.size();i>=0;i--){
        for(int j=s2.size();j>=0;j--){
            for(int k=s3.size();k>=0;k--){
                if(i==s1.size() && j==s2.size() && k==s3.size()) continue;
                bool flag = false;
                if(i<s1.size() && s1[i]==s3[k])
                    flag = flag||dp[i+1][j][k+1];
                if(j<s2.size() && s2[j]==s3[k])
                    flag = flag||dp[i][j+1][k+1];
                dp[i][j][k] = flag;
            }
        }
    }
    return dp[0][0][0];
}
bool isInterleave(string s1, string s2, string s3) {
    // return solve(s1,s2,s3,0,0,0);

    vector<vector<vector<int>>> dp(s1.size()+1,vector<vector<int>>(s2.size()+1,vector<int>(s3.size()+1,-1)));
    return solveMem(s1,s2,s3,0,0,0,dp);

    // return solveTab(s1,s2,s3);
}
int main(){
    string s1 = "aab", s2 = "axy", s3 = "aabyx";
    cout << isInterleave(s1, s2, s3) << endl; // Output: 1 (true)
    return 0;
}