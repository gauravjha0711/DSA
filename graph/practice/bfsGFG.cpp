#include<iostream>
#include<vector>
#include<queue>
using namespace std;
vector<int> bfs(vector<vector<int>> &adj) {
    int n = adj.size();
    vector<bool> visited(n,false);
    vector<int> result;
    queue<int> q;
    visited[0]=true;
    q.push(0);
    while(!q.empty()){
        int front = q.front();
        q.pop();
        result.push_back(front);
        for(int neighbour : adj[front]){
            if(!visited[neighbour]){
                visited[neighbour]=true;
                q.push(neighbour);
            }
        }
    }
    return result;
}
int main(){
    int n, m;
    cout << "Enter number of vertices and edges: ";
    cin >> n >> m;
    vector<vector<int>> adj(n);
    cout << "Enter edges (u v):" << endl;
    for(int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u); // For undirected graph
    }
    
    vector<int> bfsResult = bfs(adj);
    cout << "BFS Traversal: ";
    for(int node : bfsResult) {
        cout << node << " ";
    }
    cout << endl;
    
    return 0;
}