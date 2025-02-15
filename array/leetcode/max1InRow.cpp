#include<iostream>
#include<limits.h>
#include<vector>
using namespace std;
vector<int> rowAndMaximumOnes(vector<vector<int>>& mat) {
    vector<int> v;
    int n=mat.size();
    int maxn = INT_MIN;
    int row = -1;
    for(int i=0;i<n;i++){
        int count=0;
        for(int j=0;j<mat[i].size();j++){
            if(mat[i][j]==1){
                count++;
            }
        }
        if(maxn<count){
            maxn=count;
            row=i;
        }
    }
    v.push_back(row);
    v.push_back(maxn);
    return v;
}
int main(){
    vector<vector<int>> v={{0,0,0,1},{0,0,1,1},{0,1,1,1},{1,1,1,1}};
    vector<int> ans = rowAndMaximumOnes(v);
    for(int i=0;i<ans.size();i++){
        cout<<ans[i]<<" ";
    }
    return 0;
}