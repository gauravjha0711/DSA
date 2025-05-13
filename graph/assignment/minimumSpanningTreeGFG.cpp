#include <bits/stdc++.h>
using namespace std;

// ─── Original helper ────────────────────────────────────────────────────────────
int getMinValueNode(vector<int>& key, vector<int>& mst) {
    int temp  = INT_MAX;
    int index = -1;
    for (int i = 0; i < (int)key.size(); ++i) {
        if (key[i] < temp && mst[i] == false) {
            temp  = key[i];
            index = i;
        }
    }
    return index;
}

// ─── Original Prim’s implementation ────────────────────────────────────────────
int spanningTree(int V, vector<vector<int>> adj[]) {
    vector<int> key(V, INT_MAX);
    vector<int> mst(V, false);
    vector<int> parent(V, -1);

    key[0] = 0;
    while (true) {
        int u = getMinValueNode(key, mst);
        if (u == -1) break;
        mst[u] = true;

        for (auto edge : adj[u]) {
            int v = edge[0];
            int w = edge[1];
            if (mst[v] == false && w < key[v]) {
                key[v]    = w;
                parent[v] = u;
            }
        }
    }

    int sum = 0;
    for (int u = 0; u < (int)parent.size(); ++u) {
        if (parent[u] == -1) continue;
        for (auto edge : adj[u]) {
            int v = edge[0];
            int w = edge[1];
            if (v == parent[u]) {
                sum += w;
            }
        }
    }
    return sum;
}

// ─── Driver code ───────────────────────────────────────────────────────────────
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout<<"Enter the edges: " << endl;
    cout<<"V E" << endl;
    int V, E;
    if (!(cin >> V >> E)) return 0;

    // adjacency list as vector<vector<int>> adj[V];
    vector<vector<int>>* adj = new vector<vector<int>>[V];

    auto addEdge = [&](int u, int v, int w) {
        adj[u].push_back({v, w});
        adj[v].push_back({u, w});      // undirected graph
    };
    cout<<"u v w" << endl;
    for (int i = 0; i < E; ++i) {
        int u, v, w;
        cin >> u >> v >> w;
        addEdge(u, v, w);
    }

    cout << spanningTree(V, adj) << '\n';

    delete[] adj;
    return 0;
}