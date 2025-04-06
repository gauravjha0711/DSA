#include<bits/stdc++.h>
using namespace std;
vector<string> solve(string &s,unordered_map<string,bool> &dict,int i){
    if(i==s.size()) return {""};
    vector<string> ans;
    string word;
    for(int j=i;j<s.size();j++){
        word.push_back(s[j]);
        if(dict.find(word)==dict.end()) continue;
        auto right = solve(s,dict,j+1);
        for(auto eachPart : right){
            string endPart;
            if(eachPart.size()>0)
                endPart = " "+eachPart;
            ans.push_back(word+endPart);
        }
    }
    return ans;
}
vector<string> solveMem(string &s,unordered_map<string,bool> &dict,int i,unordered_map<int,vector<string>> &dp){
    if(i==s.size()) return {""};
    if(dp.find(i)!=dp.end()) return dp[i];
    vector<string> ans;
    string word;
    for(int j=i;j<s.size();j++){
        word.push_back(s[j]);
        if(dict.find(word)==dict.end()) continue;
        auto right = solveMem(s,dict,j+1,dp);
        for(auto eachPart : right){
            string endPart;
            if(eachPart.size()>0)
                endPart = " "+eachPart;
            ans.push_back(word+endPart);
        }
    }
    return dp[i] = ans;
}
vector<string> wordBreak(string s, vector<string>& wordDict) {
    unordered_map<string,bool> dict;
    for(auto word : wordDict){
        dict[word] = 1;
    }
    // return solve(s,dict,0);

    unordered_map<int,vector<string>> dp;
    return solveMem(s,dict,0,dp);
}
int main() {
    string s = "catsanddog";
    vector<string> wordDict = {"cat", "cats", "and", "sand", "dog"};
    vector<string> result = wordBreak(s, wordDict);
    
    // Print the result
    for (const string& sentence : result) {
        cout << sentence << endl;
    }
    
    return 0;
}