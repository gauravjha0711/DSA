#include<iostream>
#include<vector>
#include<queue>
using namespace std;
void dfssolve(int node,vector<vector<int>> &adj,vector<bool>& visited,vector<int>& result){
    visited[node]=true;
    result.push_back(node);
    for(int neigh : adj[node]){
        if(!visited[neigh]){
            dfssolve(neigh,adj,visited,result);
        }
    }
}
vector<int> dfs(vector<vector<int>>& adj) {
    // Code here
    int v = adj.size();
    vector<bool> visited(v,false);
    vector<int> result;
    dfssolve(0,adj,visited,result);
    return result;
}
int main() {
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
    
    vector<int> dfsResult = dfs(adj);
    cout << "DFS Traversal: ";
    for(int node : dfsResult) {
        cout << node << " ";
    }
    cout << endl;
    
    return 0;
}