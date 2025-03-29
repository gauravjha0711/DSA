#include<bits/stdc++.h>
using namespace std;
void solvedfs(int x,int y,int oldColor, int newColor,map<pair<int,int>, bool> &visited,vector<vector<int>> &arr){
    visited[{x,y}] = true;
    arr[x][y] = newColor;
    int dx[] = {-1,0,1,0};
    int dy[] = {0,1,0,-1};
    for(int i=0;i<4;i++){
        int newX = x+dx[i];
        int newY = y+dy[i];
        if(newX>=0 && newX<arr.size() && newY>=0 && newY<arr[0].size() && !visited[{newX,newY}] && arr[newX][newY]==oldColor){
            solvedfs(newX,newY,oldColor,newColor,visited,arr);
            visited[{newX,newY}] = true;
        }
    }
}
vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
    int oldColor = image[sr][sc];
    map<pair<int,int>,bool> visited;
    vector<vector<int>> ans = image;
    solvedfs(sr,sc,oldColor,color,visited,ans);
    return ans;
}
int main(){
    vector<vector<int>> image = {{1,1,1},{1,1,0},{1,0,1}};
    vector<vector<int>> ans = floodFill(image,1,1,2);
    for(int i=0;i<ans.size();i++){
        for(int j=0;j<ans[0].size();j++){
            cout<<ans[i][j]<<" ";
        }
        cout<<endl;
    }
    return 0;
}