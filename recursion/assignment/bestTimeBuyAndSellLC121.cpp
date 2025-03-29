#include<bits/stdc++.h>
using namespace std;
void solve(vector<int>& prices, int i,int &mini, int &profit){
    if(i>=prices.size()){
        return;
    }
    mini = min(mini,prices[i]);
    profit = max(profit,(prices[i]-mini));
    solve(prices,i+1,mini,profit);
}
int maxProfit(vector<int>& prices) {
    int mini = INT_MAX;
    int profit = INT_MIN;
    solve(prices,0,mini,profit);
    return profit;
}
int main(){
    vector<int> prices = {7,1,5,3,6,4};
    cout<<maxProfit(prices)<<endl;
    return 0;
}