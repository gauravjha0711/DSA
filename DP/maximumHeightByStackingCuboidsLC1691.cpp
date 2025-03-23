#include<bits/stdc++.h>
using namespace std;
bool check(vector<int> &a, vector<int> &b){
    if(b[0]<=a[0] && b[1]<=a[1] && b[2]<=a[2]){
        return true;
    }
    else{
        return false;
    }
}
int solveSo(vector<vector<int>>& arr){
    int n =arr.size();
    vector<int> curRow(n+1,0);
    vector<int> nextRow(n+1,0);
    for(int cur=n-1;cur>=0;cur--){
        for(int prev=cur-1;prev>=-1;prev--){
            int include = 0;
            if(prev==-1 || check(arr[cur],arr[prev])){
                include = arr[cur][2] + nextRow[cur+1];
            }
            int exclude = nextRow[prev+1];
            curRow[prev+1] = max(include,exclude);
        }
        nextRow = curRow;
    }
    return nextRow[0];
}
int maxHeight(vector<vector<int>>& cuboids) {
    for(auto &a:cuboids){
        sort(a.begin(),a.end());
    }
    sort(cuboids.begin(),cuboids.end());
    return solveSo(cuboids);
}
int main(){
    vector<vector<int>> cuboids = {{50,45,20},{95,37,53},{45,23,12}};
    cout<<maxHeight(cuboids)<<endl;
    return 0;
}