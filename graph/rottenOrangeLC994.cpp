#include<bits/stdc++.h>
using namespace std;
int orangesRotting(vector<vector<int>>& grid) {
    vector<vector<int>> ans = grid;
    queue<pair<pair<int,int>,int>> q;
    int ansTime=0;
    for(int i=0;i<grid.size();i++){
        for(int j=0;j<grid[i].size();j++){
            if(grid[i][j]==2){
                pair<int,int> coordinate = make_pair(i,j);
                q.push({coordinate,0});
            }
        }
    }
    while(!q.empty()){
        auto fnode = q.front();
        q.pop();
        int x = fnode.first.first;
        int y = fnode.first.second;
        int time = fnode.second;
        int dx[] = {-1,0,1,0};
        int dy[] = {0,1,0,-1};
        for(int i=0;i<4;i++){
            int newx = x+dx[i];
            int newy = y+dy[i];
            if(newx>=0 && newx<ans.size() && newy>=0 && newy<ans[0].size() && ans[newx][newy]==1){
                pair<int,int> coord = make_pair(newx,newy);
                ansTime = max(ansTime,time+1);
                q.push({coord,time+1});
                ans[newx][newy]=2;
            }
        }
    }
    for(int i=0;i<grid.size();i++){
        for(int j=0;j<grid[i].size();j++){
            if(ans[i][j]==1){
                return -1;
            }
        }
    }
    return ansTime;
}
int main() {
    vector<vector<int>> grid = {
        {2, 1, 1},
        {1, 1, 0},
        {0, 1, 1}
    };
    int result = orangesRotting(grid);
    cout << "Minimum time to rot all oranges: " << result << endl;
    return 0;
}
// // This code defines a function to calculate the minimum time required to rot all oranges in a grid using BFS.