#include<iostream>
#include<vector>
#include<unordered_map>
using namespace std;
bool bfs(int start, vector<vector<int>>& adj, vector<bool>& visited, vector<int>& inDegree) {
    vector<int> queue;
    queue.push_back(start);
    visited[start] = true;
    while (!queue.empty()) {
        int node = queue.front();
        queue.erase(queue.begin());
        for (int neighbor : adj[node]) {
            inDegree[neighbor]--;
            if (inDegree[neighbor] == 0) {
                if (visited[neighbor]) {
                    return true; 
                }
                visited[neighbor] = true;
                queue.push_back(neighbor);
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
    vector<int> inDegree(n, 0);
    cout << "Enter edges (u v):" << endl;
    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        inDegree[v]++;
    }
    vector<bool> visited(n, false);
    bool hasCycle = false;
    for (int i = 0; i < n; i++) {
        if (!visited[i] && inDegree[i] == 0) {
            if (bfs(i, adj, visited, inDegree)) {
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