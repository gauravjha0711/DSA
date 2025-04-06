#include<bits/stdc++.h>
using namespace std;
bool check( vector<string>& wordDict,string &word){
    for(auto i:wordDict){
        if(i==word) return true;
    }
    return false;
}
bool solve(string s, vector<string>& wordDict,int start){
    if(start==s.size()) return true;
    string word="";
    bool ans = false;
    for(int i=start;i<s.size();i++){
        word+=s[i];
        if(check(wordDict,word)){
            ans = ans || solve(s,wordDict,i+1);
        }
    }
    return ans;
}
bool solveMem(string s, vector<string>& wordDict,int start,vector<int> &dp){
    if(start==s.size()) return true;
    if(dp[start]!=-1) return dp[start];
    string word="";
    bool ans = false;
    for(int i=start;i<s.size();i++){
        word+=s[i];
        if(check(wordDict,word)){
            ans = ans || solveMem(s,wordDict,i+1,dp);
        }
    }
    return dp[start] = ans;
}
bool solveTab(string s, vector<string>& wordDict,vector<bool> &dp){
    dp[s.size()]=true;
    for(int start=s.size()-1;start>=0;start--){
        string word="";
        bool ans = false;
        for(int i=start;i<s.size();i++){
            word+=s[i];
            if(check(wordDict,word)){
                ans = ans || dp[i+1];
            }
        }
        dp[start] = ans;
    }
    return dp[0];
}
bool wordBreak(string s, vector<string>& wordDict) {
    // return solve(s,wordDict,0);

    // vector<int> dp(s.size()+1,-1);
    // return solveMem(s,wordDict,0,dp);

    vector<bool> dp(s.size()+1,true);
    return solveTab(s,wordDict,dp);
}
int main(){
    string s = "leetcode";
    vector<string> wordDict = {"leet","code"};
    cout<<wordBreak(s,wordDict)<<endl;
    return 0;
}