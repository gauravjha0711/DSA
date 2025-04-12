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
    void topSortdfs(int src,unordered_map<int,bool> &visited,stack<int> &ans){
        visited[src] = true;
        cout<<src<<", ";
        for(auto neighbour : adjList[src]){
            if(!visited[neighbour.first]){
                topSortdfs(neighbour.first,visited,ans);
            }
        }
        ans.push(src);
    }
    void shortestPathdfs(int dest,stack<int> &topOrder,int n){
        vector<int> dist(n,INT_MAX);
        int src = topOrder.top();
        topOrder.pop();
        dist[src] = 0;
        for(auto neighbour : adjList[0]){
            if(dist[neighbour.first] > dist[0] + neighbour.second){
                dist[neighbour.first] = dist[0] + neighbour.second;
            }
        }
        while(!topOrder.empty()){
            int topElement = topOrder.top();
            topOrder.pop();
            if(dist[topElement] != INT_MAX){
                for(auto neighbour : adjList[topElement]){
                    if(dist[neighbour.first] > dist[topElement] + neighbour.second){
                        dist[neighbour.first] = dist[topElement] + neighbour.second;
                    }
                }
            }
        }
        cout<<"Printing ans: "<<endl;
        for(int i=0;i<n;i++){
            cout<<i<<" -> "<<dist[i]<<endl;
        }
    }

};
int main(){
    Graph g;
    // g.addEdge(0,1,1,1);
    // g.addEdge(1,2,1,1);
    // g.addEdge(2,3,1,1);

    // g.addEdge(3,4,1,1);
    // g.addEdge(0,5,1,1);
    // g.addEdge(5,4,1,1);

    // g.addEdge(0,6,1,1);
    // g.addEdge(6,7,1,1);
    // g.addEdge(7,8,1,1);
    // g.addEdge(8,4,1,1);
    
    // g.printAdjList();

    // int src = 0;
    // int dest = 4;

    // g.shortestPathbfs(src,dest);

    g.addEdge(0,1,5,0);
    g.addEdge(0,2,3,0);
    g.addEdge(2,1,2,0);

    g.addEdge(1,3,3,0);
    g.addEdge(2,3,5,0);
    g.addEdge(2,4,6,0);
    g.addEdge(4,3,1,0);

    g.printAdjList();
    cout<<endl;
    stack<int> topOrder;
    unordered_map<int,bool> visited;
    g.topSortdfs(0,visited,topOrder);
    cout<<endl;
    g.shortestPathdfs(3,topOrder,5);

}