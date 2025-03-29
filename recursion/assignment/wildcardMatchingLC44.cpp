#include<bits/stdc++.h>
using namespace std;
// bool solve(string &s, int i, string &p, int j,vector<vector<int>> &dp){
//     if(i==s.size() && j==p.size()){
//         return true;
//     }
//     if(i==s.size() && j<p.size()){
//         while(j<p.size()){
//             if(p[j]!='*'){
//                 return false;
//             }
//             j++;
//         }
//         return true;
//     }
//     if(dp[i][j]!=-1){
//         return dp[i][j];
//     }
//     if(s[i]==p[j] || '?'==p[j]){
//         return dp[i][j] =  solve(s,i+1,p,j+1,dp);
//     }
//     if(p[j]=='*'){
//         bool case1 = solve(s,i,p,j+1,dp);
//         bool case2 = solve(s,i+1,p,j,dp);
//         return dp[i][j] = case1||case2;
//     }
//     return dp[i][j] = false;
// }
// bool isMatch(string s, string p) {
//     int n = s.size(), m = p.size();
//     vector<vector<int>> dp(n+1,vector<int>(m+1,-1));
//     return solve(s,0,p,0,dp);
// }



bool isMatch(string s, string p) {
    int n = s.size(), m = p.size();
    vector<vector<bool>> dp(n + 1, vector<bool>(m + 1, false));

    // Base case: Empty pattern matches empty string
    dp[0][0] = true;

    // Fill first row: '*' can match an empty sequence
    for (int j = 1; j <= m; j++) {
        if (p[j - 1] == '*') {
            dp[0][j] = dp[0][j - 1];
        }
    }

    // Fill DP table
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            if (p[j - 1] == s[i - 1] || p[j - 1] == '?') {
                dp[i][j] = dp[i - 1][j - 1]; // Match current character
            } else if (p[j - 1] == '*') {
                dp[i][j] = dp[i - 1][j] || dp[i][j - 1]; // '*' matches empty or more characters
            }
        }
    }

    return dp[n][m];
}
int main(){
    string s = "adceb";
    string p = "*a*b";
    cout<<isMatch(s,p)<<endl;
    return 0;
}