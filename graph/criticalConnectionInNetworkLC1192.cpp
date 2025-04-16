#include <bits/stdc++.h>
using namespace std;

// Class only for graph construction
class Graph {
public:
    int v;
    vector<pair<int, int>> edges;

    Graph(int vertices) {
        v = vertices;
    }

    void addEdge(int u, int v) {
        edges.push_back({u, v});
    }

    unordered_map<int, list<int>> getAdjList() {
        unordered_map<int, list<int>> adjList;
        for (auto edge : edges) {
            int u = edge.first;
            int v = edge.second;
            adjList[u].push_back(v);
            adjList[v].push_back(u);
        }
        return adjList;
    }
};

// Tarjan's algorithm to find bridges
void findBridge(int src, int parent, int &timer,
                vector<int>& tin, vector<int>& low,
                vector<bool>& visited,
                vector<vector<int>>& ans,
                unordered_map<int, list<int>>& adjList) {
    
    visited[src] = true;
    tin[src] = low[src] = timer++;

    for (auto nbr : adjList[src]) {
        if (nbr == parent) continue;

        if (!visited[nbr]) {
            findBridge(nbr, src, timer, tin, low, visited, ans, adjList);
            low[src] = min(low[src], low[nbr]);

            if (low[nbr] > tin[src]) {
                ans.push_back({src, nbr});
            }
        } else {
            low[src] = min(low[src], tin[nbr]);
        }
    }
}

vector<vector<int>> criticalConnections(int n, Graph& g) {
    unordered_map<int, list<int>> adjList = g.getAdjList();
    
    vector<vector<int>> ans;
    vector<int> tin(n, -1), low(n, -1);
    vector<bool> visited(n, false);
    int timer = 0;

    for (int i = 0; i < n; i++) {
        if (!visited[i]) {
            findBridge(i, -1, timer, tin, low, visited, ans, adjList);
        }
    }

    return ans;
}

// Main function to test
int main() {
    int n = 5;
    Graph g(n);
    g.addEdge(0, 1);
    g.addEdge(1, 2);
    g.addEdge(2, 0);
    g.addEdge(1, 3);
    g.addEdge(3, 4);

    vector<vector<int>> bridges = criticalConnections(n, g);

    cout << "Bridges in the graph:\n";
    for (auto bridge : bridges) {
        cout << bridge[0] << " - " << bridge[1] << endl;
    }

    return 0;
}
