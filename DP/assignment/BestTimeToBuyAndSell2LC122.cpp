#include<bits/stdc++.h>
using namespace std;
int solve(vector<int> &prices,int i,int buy){
    if(i>=prices.size()) return 0;
    int profit =0;
    if(buy){
        int buyProfit = -prices[i]+solve(prices,i+1,0);
        int skipProfit = solve(prices,i+1,1);
        profit = max(buyProfit,skipProfit);
    }
    else{
        int sellProfit = prices[i]+solve(prices,i+1,1);
        int skipProfit = solve(prices,i+1,0);
        profit = max(sellProfit,skipProfit);
    }
    return profit;
}
int solveMemo(vector<int> &prices,int i,int buy,vector<vector<int>> &dp){
    if(i>=prices.size()) return 0;
    int profit =0;
    if(dp[i][buy]!=-1){
        return dp[i][buy];
    }
    if(buy){
        int buyProfit = -prices[i]+solveMemo(prices,i+1,0,dp);
        int skipProfit = solveMemo(prices,i+1,1,dp);
        profit = max(buyProfit,skipProfit);
    }
    else{
        int sellProfit = prices[i]+solveMemo(prices,i+1,1,dp);
        int skipProfit = solveMemo(prices,i+1,0,dp);
        profit = max(sellProfit,skipProfit);
    }
    return dp[i][buy] = profit;
}
int solveTab(vector<int> &prices,vector<vector<int>> &dp){
    for(int i =prices.size()-1;i>=0;i--){
        for(int buy=0;buy<2;buy++){
            int profit =0;
            if(buy){
                int buyProfit = -prices[i]+dp[i+1][0];
                int skipProfit = dp[i+1][1];
                profit = max(buyProfit,skipProfit);
            }
            else{
                int sellProfit = prices[i]+dp[i+1][1];
                int skipProfit = dp[i+1][0];
                profit = max(sellProfit,skipProfit);
            }
            dp[i][buy] = profit;
        }
    }
    return dp[0][1];
}
int solveSopt(vector<int> &prices,vector<vector<int>> &dp){
    for(int i =prices.size()-1;i>=0;i--){
        for(int buy=0;buy<2;buy++){
            int profit =0;
            if(buy){
                int buyProfit = -prices[i]+dp[1][0];
                int skipProfit = dp[1][1];
                profit = max(buyProfit,skipProfit);
            }
            else{
                int sellProfit = prices[i]+dp[1][1];
                int skipProfit = dp[1][0];
                profit = max(sellProfit,skipProfit);
            }
            dp[0][buy] = profit;
        }
        dp[1]=dp[0];
    }
    return dp[0][1];
}
int maxProfit(vector<int>& prices) {
    // return solve(prices,0,true);

    // vector<vector<int>> dp(prices.size()+1,vector<int>(2,-1));
    // return solveMemo(prices,0,true,dp);

    // vector<vector<int>> dp(prices.size()+1,vector<int>(2,0));
    // return solveTab(prices,dp);

    vector<vector<int>> dp(2,vector<int>(2,0));
    return solveSopt(prices,dp);
}
int main(){
    vector<int> prices = {7,1,5,3,6,4};
    cout<<maxProfit(prices)<<endl;
    return 0;
}