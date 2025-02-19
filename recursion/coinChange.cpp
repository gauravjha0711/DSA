#include<iostream>
#include<vector>
#include<limits.h>
using namespace std;
int coinChange(vector<int> &coins, int amount){
    if(amount==0){
        return 0;
    }
    if(amount<0){
        return INT_MAX;
    }
    int mini = INT_MAX;
    for(int i=0;i<coins.size();i++){
        int coin = coins[i];
        if(coin<=amount){
            int res = coinChange(coins, amount-coin);
            if(res!=INT_MAX){
                int ans = 1+ res;
                mini = min(mini, ans);
            }
        }
    }
    return mini;
}
int main(){
    int n;
    cout<<"Enter the size of coins: ";
    cin>>n;
    vector<int> coins(n);
    cout<<"Enter the coins: ";
    for(int i=0;i<n;i++){
        cin>>coins[i];
    }
    int amount;
    cout<<"Enter the amount: ";
    cin>>amount;
    int ans = coinChange(coins, amount);
    if(ans==INT_MAX){
        cout<<"Not possible"<<endl;
    }
    else{
        cout<<"Minimum coins required: "<<ans<<endl;
    }
    return 0;
}