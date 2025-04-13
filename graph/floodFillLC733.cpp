#include<bits/stdc++.h>
using namespace std;
void dfssolve(vector<vector<int>>& ans,int oldcolor,int newcolor,int x,int y,map<pair<int,int>,bool>&visited){
    visited[{x,y}]=true;
    ans[x][y]=newcolor;
    int dx[] = {-1,0,1,0};
    int dy[] = {0,1,0,-1};
    for(int i=0;i<4;i++){
        int newx = x+dx[i];
        int newy = y+dy[i];
        if(newx>=0 && newx<ans.size() && newy>=0 && newy<ans[0].size() && !visited[{newx,newy}] && ans[newx][newy]==oldcolor){
            dfssolve(ans,oldcolor,newcolor,newx,newy,visited);
        }
    }
}
vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
    int oldcolor = image[sr][sc];
    vector<vector<int>> ans = image;
    map<pair<int,int>,bool> visited;
    dfssolve(ans,oldcolor,color,sr,sc,visited);
    return ans;
}
int main() {
    vector<vector<int>> image = {
        {1, 1, 1},
        {1, 1, 0},
        {1, 0, 1}
    };
    int sr = 1, sc = 1, color = 2;
    vector<vector<int>> result = floodFill(image, sr, sc, color);
    for (const auto& row : result) {
        for (int val : row) {
            cout << val << " ";
        }
        cout << endl;
    }
    return 0;
}
// This code defines a function to perform a flood fill operation on a 2D grid (image) using DFS. 