#include <bits/stdc++.h>
using namespace std;

class Graph {
public:
    int v;
    vector<list<pair<int, int>>> adjList;

    Graph(int v) {
        this->v = v;
        adjList.resize(v);
    }

    void addEdge(int u, int v, int w) {
        adjList[u].push_back({v, w});
        adjList[v].push_back({u, w}); // Because it's undirected
    }

    void findBridge(int src, int parent, int &timer,
                    vector<int>& tin, vector<int>& low,
                    vector<bool>& visited,
                    vector<vector<int>>& ans,
                    unordered_map<int, list<int>>& simpleAdj) {

        visited[src] = true;
        tin[src] = low[src] = timer++;

        for (auto nbr : simpleAdj[src]) {
            if (nbr == parent) continue;

            if (!visited[nbr]) {
                findBridge(nbr, src, timer, tin, low, visited, ans, simpleAdj);
                low[src] = min(low[src], low[nbr]);

                if (low[nbr] > tin[src]) {
                    ans.push_back({src, nbr});
                }
            } else {
                low[src] = min(low[src], tin[nbr]);
            }
        }
    }
};

int main() {
    int n = 5;
    Graph g(n);

    // Add edges
    g.addEdge(0, 1, 1);
    g.addEdge(1, 2, 1);
    g.addEdge(2, 0, 1);
    g.addEdge(1, 3, 1);
    g.addEdge(3, 4, 1);

    // Build simplified adjacency list (no weights needed for bridges)
    unordered_map<int, list<int>> simpleAdj;
    for (int i = 0; i < n; i++) {
        for (auto nbr : g.adjList[i]) {
            simpleAdj[i].push_back(nbr.first);
        }
    }

    vector<int> tin(n, -1), low(n, -1);
    vector<bool> visited(n, false);
    vector<vector<int>> bridges;
    int timer = 0;

    for (int i = 0; i < n; i++) {
        if (!visited[i]) {
            g.findBridge(i, -1, timer, tin, low, visited, bridges, simpleAdj);
        }
    }

    cout << "Bridges in the graph are:\n";
    for (auto bridge : bridges) {
        cout << bridge[0] << " - " << bridge[1] << "\n";
    }

    return 0;
}