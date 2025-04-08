#include<bits/stdc++.h>
using namespace std;
int solve(vector<int>&piles,int i,int M,int alice){
    if(i==piles.size()) return 0;
    int total = 0;
    int ans = alice ? INT_MIN:INT_MAX;
    for(int x=1;x<=2*M;x++){
        if(i+x-1>=piles.size()) break;
        total += piles[i+x-1];
        if(alice){
            ans = max(ans, total+solve(piles,i+x,max(M,x),!alice));
        }
        else{
            ans = min(ans,solve(piles,i+x,max(M,x),!alice));
        }
    }
    return ans;
}
int solveMem(vector<int>&piles,int i,int M,int alice,vector<vector<vector<int>>>&dp){
    if(i==piles.size()) return 0;
    if(dp[i][M][alice]!=-1) return dp[i][M][alice];
    int total = 0;
    int ans = alice ? INT_MIN:INT_MAX;
    for(int x=1;x<=2*M;x++){
        if(i+x-1>=piles.size()) break;
        total += piles[i+x-1];
        if(alice){
            ans = max(ans, total+solveMem(piles,i+x,max(M,x),!alice,dp));
        }
        else{
            ans = min(ans,solveMem(piles,i+x,max(M,x),!alice,dp));
        }
    }
    return dp[i][M][alice] =  ans;
}
int solveTab(vector<int>&piles){
    vector<vector<vector<int>>> dp(piles.size()+1,vector<vector<int>>(piles.size()+1,vector<int>(2,0)));
    for(int i=piles.size()-1;i>=0;i--){
        for(int M=piles.size();M>=1;M--){
            for(int alice=0;alice<=1;alice++){
                int total = 0;
                int ans = alice ? INT_MIN:INT_MAX;
                for(int x=1;x<=2*M;x++){
                    if(i+x-1>=piles.size()) break;
                    total += piles[i+x-1];
                    if(alice){
                        ans = max(ans, total+dp[i+x][max(M,x)][!alice]);
                    }
                    else{
                        ans = min(ans,dp[i+x][max(M,x)][!alice]);
                    }
                }
                dp[i][M][alice] =  ans;
            }
        }
    }
    return dp[0][1][1];
}
int stoneGameII(vector<int>& piles) {
    // return solve(piles,0,1,true);

    vector<vector<vector<int>>> dp(piles.size()+1,vector<vector<int>>(piles.size()+1,vector<int>(2,-1)));
    return solveMem(piles,0,1,true,dp);

    // return solveTab(piles);
}
int main(){
    vector<int> piles = {2,7,9,4,4};
    cout << stoneGameII(piles) << endl; // Output: 10
    return 0;
}