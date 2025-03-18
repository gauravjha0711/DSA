#include<bits/stdc++.h>
using namespace std;
int solveRec(int start, int end){
    if(start>=end){
        return 0;
    }
    int ans = INT_MAX;
    for(int i=start;i<=end;i++){
        ans = min(ans,i+max(solveRec(start,i-1),solveRec(i+1,end)));
    }
    return ans;
}
int solveMem(int start, int end,vector<vector<int>> &dp){
    if(start>=end){
        return 0;
    }
    if(dp[start][end]!=-1){
        return dp[start][end];
    }
    int ans = INT_MAX;
    for(int i=start;i<=end;i++){
        ans = min(ans,i+max(solveMem(start,i-1,dp),solveMem(i+1,end,dp)));
    }
    dp[start][end] = ans;
    return dp[start][end];
}
int solveTab(int end){
    vector<vector<int>> dp(end+2,vector<int>(end+2,0));
    for(int s=end;s>=1;s--){
        for(int e=1;e<=end;e++){
            if(s>=e){
                continue;
            }
            else{
                int ans = INT_MAX;
                for(int i=s;i<=e;i++){
                    ans = min(ans,i+max(dp[s][i-1],dp[i+1][e]));
                }
                dp[s][e] = ans;
            }
        }
    }
    return dp[1][end];
}

int getMoneyAmount(int n) {
    // return solveRec(1,n);

    // vector<vector<int>> dp(n+1,vector<int>(n+1,-1));
    // return solveMem(1,n,dp);

    return solveTab(n);
}
int main(){
    int n;
    cin>>n;
    cout<<getMoneyAmount(n)<<endl;
}