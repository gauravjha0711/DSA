#include<iostream>
#include<vector>
#include<unordered_map>
using namespace std;
bool bfs(int start, vector<vector<int>>& adj, vector<bool>& visited) {
    vector<int> parent(adj.size(), -1);
    vector<int> queue;
    queue.push_back(start);
    visited[start] = true;
    while (!queue.empty()) {
        int node = queue.front();
        queue.erase(queue.begin());
        for (int neighbor : adj[node]) {
            if (!visited[neighbor]) {
                visited[neighbor] = true;
                parent[neighbor] = node;
                queue.push_back(neighbor);
            } else if (parent[node] != neighbor) {
                return true; 
            }
        }
    }
    return false;
}
int main(){
    int n, m;
    cout << "Enter number of vertices and edges: ";
    cin >> n >> m;
    vector<vector<int>> adj(n);
    cout << "Enter edges (u v):" << endl;
    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    vector<bool> visited(n, false);
    bool hasCycle = false;
    for (int i = 0; i < n; i++) {
        if (!visited[i]) {
            if (bfs(i, adj, visited)) {
                hasCycle = true;
                break;
            }
        }
    }
    if (hasCycle) {
        cout << "Graph contains a cycle." << endl;
    } else {
        cout << "Graph does not contain a cycle." << endl;
    }
    return 0;
}