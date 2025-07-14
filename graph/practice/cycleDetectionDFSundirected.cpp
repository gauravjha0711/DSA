#include<iostream>
#include<vector>
using namespace std;

bool dfs(int node, int parent, vector<vector<int>>& adj, vector<bool>& visited) {
    visited[node] = true;

    for (int neighbor : adj[node]) {
        if (!visited[neighbor]) {
            if (dfs(neighbor, node, adj, visited)) {
                return true;
            }
        } else if (neighbor != parent) {
            return true;
        }
    }

    return false;
}

int main() {
    int n, m;
    cout << "Enter number of vertices and edges: ";
    cin >> n >> m;

    vector<vector<int>> adj(n);
    cout << "Enter edges (u v):" << endl;
    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;

        // Since it's undirected, add both ways
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    vector<bool> visited(n, false);
    bool hasCycle = false;

    for (int i = 0; i < n; i++) {
        if (!visited[i]) {
            if (dfs(i, -1, adj, visited)) {
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
