#include<bits/stdc++.h>
using namespace std;
class Graph{
    public:
    unordered_map<int,list<pair<int,int>>> adjList;
    void addEdge(int u,int v,int wt,bool direction){
        adjList[u].push_back({v,wt});
        if(direction==true){
            adjList[v].push_back({u,wt});
        }
    }
    void printAdjList(){
        for(auto i : adjList){
            cout<<i.first<<"->";
            for(auto neighbour : i.second){
                cout<<"("<<neighbour.first<<","<<neighbour.second<<")";
            }
            cout<<endl;
        }
    }
    void shortestPathbfs(int src, int dest){
        queue<int> q;
        unordered_map<int, bool> visited;
        unordered_map<int, int> parent;
        q.push(src);
        visited[src] = true;
        parent[src] = -1;
        while(!q.empty()){
            int frontNode = q.front();
            q.pop();
            for(auto neighbour  : adjList[frontNode]){
                if(!visited[neighbour.first]){
                    q.push(neighbour.first);
                    visited[neighbour.first] = true;
                    parent[neighbour.first] = frontNode;
                }
            }
        }

        vector<int> ans;
        int node = dest;
        while(node!=-1){
            ans.push_back(node);
            node = parent[node];
        }
        reverse(ans.begin(),ans.end());
        cout<<"Shortest path from "<<src<<" to "<<dest<<" is: ";
        for(auto i : ans){
            cout<<i<<"->";
        }
        cout<<endl;
    }
    
};
int main(){
    Graph g;
    g.addEdge(0,1,1,1);
    g.addEdge(1,2,1,1);
    g.addEdge(2,3,1,1);

    g.addEdge(3,4,1,1);
    g.addEdge(0,5,1,1);
    g.addEdge(5,4,1,1);

    g.addEdge(0,6,1,1);
    g.addEdge(6,7,1,1);
    g.addEdge(7,8,1,1);
    g.addEdge(8,4,1,1);
    
    g.printAdjList();

    int src = 0;
    int dest = 4;

    g.shortestPathbfs(src,dest);



}