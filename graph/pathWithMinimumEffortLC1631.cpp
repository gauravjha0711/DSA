#include<bits/stdc++.h>
using namespace std;
int minimumEffortPath(vector<vector<int>>& heights) {
    priority_queue< pair<int,pair<int,int> >, vector<pair<int,pair<int,int> > >, greater<pair<int,pair<int,int> > > > pq;
    vector<vector<int> > dist(heights.size(), vector<int>(heights[0].size(), INT_MAX));
    pq.push({0, {0,0}});
    dist[0][0] = 0;
    while(!pq.empty()) {
        auto fNode = pq.top();
        pq.pop();
        int frontNodeDifference = fNode.first;
        int x = fNode.second.first;
        int y = fNode.second.second;

        //check ans tak toh nahi pahuch agye
        if(x == heights.size() - 1 && y == heights[0].size() - 1) {
            return dist[x][y];
        }

        int dx[] = {-1,0,1,0};
        int dy[] = {0,1,0,-1};
        for(int i=0; i<4; i++) {
            int newX = x + dx[i];
            int newY = y + dy[i];
            if(newX >=0 && newY >=0 && newX <heights.size() && newY < heights[0].size()) {
                int currDifference = abs(heights[x][y] - heights[newX][newY]);
                int newMax = max(frontNodeDifference, currDifference);
                if(newMax < dist[newX][newY]) {
                    dist[newX][newY] = newMax;
                    pq.push({newMax, {newX, newY}});
                }
            }
        }
    }
    return 0;
}
int main() {
    vector<vector<int>> heights = {{1,2,3},{3,2,1},{1,2,3}};
    int result = minimumEffortPath(heights);
    cout << "Minimum effort path: " << result << endl;
    return 0;
}
// //time complexity is O(n*m*log(n*m)) where n is the number of rows and m is the number of columns in the grid.
// //space complexity is O(n*m) for the distance array and the priority queue.
// //The code uses a priority queue to implement Dijkstra's algorithm to find the minimum effort path in the grid.
// //It iteratively explores the neighboring cells and updates the distance array with the minimum effort required to reach each cell.
// //The final result is the minimum effort required to reach the bottom-right cell from the top-left cell.