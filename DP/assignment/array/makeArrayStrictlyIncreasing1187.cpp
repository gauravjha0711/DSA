#include<bits/stdc++.h>
using namespace std;
#define INF (1e9+1)
int solve(vector<int>& arr1, vector<int>& arr2,int pre,int i){
    if(i==arr1.size()) return 0;
    int op1 = INF;
    if(pre<arr1[i])
        op1 = 0+solve(arr1,arr2,arr1[i],i+1);
    int op2 = INF;
    auto it = upper_bound(arr2.begin(),arr2.end(),pre);
    if(it!=arr2.end()){
        int index = it-arr2.begin();
        op2 = 1+solve(arr1,arr2,arr2[index],i+1);
    }
    return min(op1,op2);
}
int solveMem(vector<int>& arr1, vector<int>& arr2,int pre,int i,map<pair<int,int>,int>&dp){
    if(i==arr1.size()) return 0;
    if(dp.find({pre,i})!=dp.end()) return dp[{pre,i}];
    int op1 = INF;
    if(pre<arr1[i])
        op1 = 0+solveMem(arr1,arr2,arr1[i],i+1,dp);
    int op2 = INF;
    auto it = upper_bound(arr2.begin(),arr2.end(),pre);
    if(it!=arr2.end()){
        int index = it-arr2.begin();
        op2 = 1+solveMem(arr1,arr2,arr2[index],i+1,dp);
    }
    return dp[{pre,i}] = min(op1,op2);
}
int makeArrayIncreasing(vector<int>& arr1, vector<int>& arr2) {
    sort(arr2.begin(),arr2.end());
    // int ans = solve(arr1,arr2,-1,0);
    // return ans>=INF ? -1 :ans;

    map<pair<int,int>,int>dp;
    int ans = solveMem(arr1,arr2,-1,0,dp);
    return ans>=INF ? -1 :ans;

}
int main(){
    vector<int> arr1 = {1,5,3,6,7};
    vector<int> arr2 = {1,3,2,4};
    cout << makeArrayIncreasing(arr1,arr2) << endl; // Output: 1
    return 0;
}