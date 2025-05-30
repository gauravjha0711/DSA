#include<bits/stdc++.h>
using namespace std;
int memo(vector<int> &coins, int amount, vector<int> &dp){
    if(amount==0){
        return 0;
    }
    if(amount<0){
        return INT_MAX;
    }
    if(dp[amount]!=-1){
        return dp[amount];
    }
    int mini = INT_MAX;
    for(int i=0;i<coins.size();i++){
        int ans = memo(coins,amount-coins[i],dp);
        if(ans!=INT_MAX){
            mini = min(mini,ans+1);
        }
    }
    dp[amount] = mini;
    return mini;
}
int coinChange(vector<int>& coins, int amount) {
    vector<int> dp(amount+1, -1);
    int ans = memo(coins, amount, dp);
    if(ans==INT_MAX){
        return -1;
    }
    else{
        return ans;
    }
}
// Tabulation
int solveTab(vector<int> &coins, int amount){
    vector<int> dp(amount+1, INT_MAX);
    dp[0] = 0;
    for(int target=1; target<=amount;target++){
        int mini = INT_MAX;
        for(int i=0;i<coins.size();i++){
            if(target-coins[i]>=0){
                int ans = dp[target-coins[i]];
                if(ans!=INT_MAX){
                    mini = min(mini,ans+1);
                }
            }
        }
        dp[target] = mini;
    }
    return dp[amount];
}
int coinChange(vector<int>& coins, int amount) {
    // vector<int> dp(amount+1, -1);
    // int ans = memo(coins, amount, dp);
    // if(ans==INT_MAX){
    //     return -1;
    // }
    // else{
    //     return ans;
    // }

    int ans = solveTab(coins, amount);
    if(ans==INT_MAX){
        return -1;
    }
    else{
        return ans;
    }
}
int main(){
    vector<int> coins = {1,2,5};
    int amount = 11;
    cout<<coinChange(coins, amount)<<endl;
    return 0;
}