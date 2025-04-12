#include <bits/stdc++.h>
using namespace std;

template<typename T>
class Graph {
public:
    unordered_map<T, list<T>> adjList;

    void addEdge(T u, T v, bool direction = false) {
        // direction false - undirected graph
        // direction true - directed graph
        adjList[u].push_back(v);
        if (!direction) {
            adjList[v].push_back(u);
        }
    }

    void printAdjList() {
        for (auto node : adjList) {
            cout << node.first << "->";
            for (auto neighbour : node.second) {
                cout << neighbour << ", ";
            }
            cout << endl;
        }
    }

    bool checkCyclicUsingDFS(int src, unordered_map<int, bool> &visited, int parent) {
        visited[src] = true;

        for (auto neighbour : adjList[src]) {
            if (!visited[neighbour]) {
                if (checkCyclicUsingDFS(neighbour, visited, src)) {
                    return true;
                }
            } 
            else {
                if (neighbour != parent) {
                    return true;
                }
            }
        }

        return false;
    }
};


int main() {
    Graph<int> g;
    g.addEdge(0, 1);
    g.addEdge(1, 2);
    g.addEdge(2, 3);
    g.addEdge(3, 0); // Creates a cycle


    unordered_map<int, bool> visited;
    for (auto node : g.adjList) {
        if (!visited[node.first]) {
            if (g.checkCyclicUsingDFS(node.first, visited,-1)) {
                cout << "Cyclic";
                return 0;
            }
        }
    }

    cout << "Not Cyclic";
    return 0;
}
