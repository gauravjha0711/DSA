#include<bits/stdc++.h>
using namespace std;
int maxLen = 1, start=0;
bool check(string &s, int i, int j){
    if(i>=j) return true;
    bool flag = false;
    if(s[i]==s[j]) flag = check(s,i+1,j-1);
    if(flag){
        int curLen = j-i+1; 
        if(curLen>maxLen){
            maxLen = curLen;
            start = i;
        }
    }
    return flag;
}
bool checkMem(string &s, int i, int j,vector<vector<int>> &dp){
    if(i>=j) return true;
    if(dp[i][j]!=-1) return dp[i][j];
    bool flag = false;
    if(s[i]==s[j]) flag = checkMem(s,i+1,j-1,dp);
    if(flag){
        int curLen = j-i+1; 
        if(curLen>maxLen){
            maxLen = curLen;
            start = i;
        }
    }
    return dp[i][j] = flag;
}
string longestPalindrome(string s) {
    vector<vector<int>> dp(s.size(),vector<int>(s.size(),-1));
    for(int i=0;i<s.size();i++){
        for(int j=0;j<s.size();j++){
            // bool t = check(s,i,j);

            bool t = checkMem(s,i,j,dp);
        }
    }
    return s.substr(start,maxLen);
}
int main(){
    string s = "babad";
    cout<<longestPalindrome(s)<<endl;
    return 0;
}