#include <bits/stdc++.h>
using namespace std;
void solvebfs(vector<vector<bool>> &visited, int row, int col, vector<vector<char>> &grid) {
    queue<pair<int, int>> q;
    q.push({row, col});
    visited[row][col] = true;
    int dx[] = {-1, 0, 1, 0};
    int dy[] = {0, 1, 0, -1};
    
    while (!q.empty()) {
        int x = q.front().first;
        int y = q.front().second;
        q.pop();
        
        for (int i = 0; i < 4; i++) {
            int newX = x + dx[i];
            int newY = y + dy[i];
            if (newX >= 0 && newX < grid.size() && newY >= 0 && newY < grid[0].size() && 
                !visited[newX][newY] && grid[newX][newY] == '1') {
                q.push({newX, newY});
                visited[newX][newY] = true;
            }
        }
    }
}
int numIslands(vector<vector<char>> &grid) {
    int rows = grid.size();
    int cols = grid[0].size();
    vector<vector<bool>> visited(rows, vector<bool>(cols, false));
    int count = 0;
    
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            if (!visited[i][j] && grid[i][j] == '1') {
                solvebfs(visited, i, j, grid);
                count++;
            }
        }
    }
    return count;
}

int main() {
    vector<vector<char>> grid = {
        {'1', '1', '0', '0', '0'},
        {'1', '1', '0', '0', '0'},
        {'0', '0', '1', '0', '0'},
        {'0', '0', '0', '1', '1'}
    };
    cout << numIslands(grid) << endl;
    return 0;
}
// This code defines a function to count the number of islands in a 2D grid using BFS.
// An island is surrounded by water and is formed by connecting adjacent lands horizontally or vertically.
//The function uses a queue to perform BFS and mark visited cells. The main function demonstrates the usage of the numIslands function with a sample grid.
// The output will be the number of islands in the given grid.