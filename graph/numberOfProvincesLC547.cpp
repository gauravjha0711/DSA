#include<bits/stdc++.h>
using namespace std;
// This is a graph problem. We have to find the number of provinces in a graph.
// We can solve this problem using DFS. We will keep a visited map and we will
void solvedfs(unordered_map<int,bool> &visited,int src,vector<vector<int>>& isConnected){
    visited[src] = true;
    int n = isConnected[src].size();
    for(int col=0;col<n;col++){
        if(col!=src && isConnected[src][col]==1){
            if(!visited[col]){
                solvedfs(visited,col,isConnected);
            }
        }
    }
}
int findCircleNum(vector<vector<int>>& isConnected) {
    unordered_map<int,bool> visited;
    int count = 0;
    int n = isConnected.size();
    for(int i=0;i<n;i++){
        if(!visited[i]){
            solvedfs(visited,i,isConnected);
            count++;
        }
    }
    return count;
}

int main(){
    vector<vector<int>> isConnected = {{1,1,0},{1,1,0},{0,0,1}};
    cout<<findCircleNum(isConnected)<<endl;
    return 0;
}