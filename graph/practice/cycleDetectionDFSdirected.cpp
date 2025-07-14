#include<iostream>
#include<vector>
#include<unordered_map>
using namespace std;
bool dfs(int node, vector<vector<int>>& adj, vector<bool>& visited, vector<bool>& recStack) {
    visited[node] = true;
    recStack[node] = true;

    for (int neighbor : adj[node]) {
        if (!visited[neighbor]) {
            if (dfs(neighbor, adj, visited, recStack)) {
                return true;
            }
        } else if (recStack[neighbor]) {
            return true;
        }
    }

    recStack[node] = false;
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
    }

    vector<bool> visited(n, false);
    vector<bool> recStack(n, false);

    bool hasCycle = false;
    for (int i = 0; i < n; i++) {
        if (!visited[i]) {
            if (dfs(i, adj, visited, recStack)) {
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