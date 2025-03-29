#include <bits/stdc++.h>
using namespace std;
int solve(vector<int> &days, vector<int> &costs, int i){
    if(i>=days.size()) return 0;

    int cost1 = costs[0]+solve(days,costs,i+1);

    int lastDay = days[i]+7-1;
    int j=i;
    while(j<days.size() && days[j]<=lastDay){
        j++;
    }
    int cost7 = costs[1]+solve(days,costs,j);

    lastDay = days[i]+30-1;
    j=i;
    while(j<days.size() && days[j]<=lastDay){
        j++;
    }
    int cost30 = costs[2]+solve(days,costs,j);
    return min(cost1, min(cost30,cost7));
}
int solveMemo(vector<int> &days, vector<int> &costs, int i,vector<int> &dp){
    if(i>=days.size()) return 0;

    if(dp[i]!=-1) return dp[i];
    int cost1 = costs[0]+solveMemo(days,costs,i+1,dp);

    int lastDay = days[i]+7-1;
    int j=i;
    while(j<days.size() && days[j]<=lastDay){
        j++;
    }
    int cost7 = costs[1]+solveMemo(days,costs,j,dp);

    lastDay = days[i]+30-1;
    j=i;
    while(j<days.size() && days[j]<=lastDay){
        j++;
    }
    int cost30 = costs[2]+solveMemo(days,costs,j,dp);
    return dp[i] = min(cost1, min(cost30,cost7));
}
int mincostTickets(vector<int>& days, vector<int>& costs) {
    // return solve(days,costs,0);

    vector<int> dp(days.size()+1,-1);
    return solveMemo(days,costs,0,dp);
}
int main(){
    vector<int> days = {1,4,6,7,8,20};
    vector<int> costs = {2,7,15};
    cout<<mincostTickets(days,costs)<<endl;
    return 0;
}