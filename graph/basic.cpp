#include<bits/stdc++.h>
using namespace std;
template<typename T>
class Graph{
    public:
    unordered_map<T,list<T>> adjList;
    void addEdge(T u, T v, bool direction=true){
        //direction false - undirected graph
        //direction true - directed graph
        // created edge u to v
        adjList[u].push_back(v);
        if(!direction){
            adjList[v].push_back(u);
        }
    }
    void printAdjList(){
        for(auto node : adjList){
            cout<<node.first<<"->";
            for(auto neighbour : node.second){
                cout<<neighbour<<", ";
            }
            cout<<endl;
        }
    }
    void bfs(int src){
        queue<int> q;
        unordered_map<int,bool> visited;
        q.push(src);
        visited[src] = true;
        while(!q.empty()){
            int frontNode = q.front();
            q.pop();
            cout<<frontNode<<", ";

            //insert neighbours of frontNode
            for(auto neighbour : adjList[frontNode]){
                if(!visited[neighbour]){
                    q.push(neighbour);
                    visited[neighbour] = true;
                }
            }
        }
    }
    void dfs(int src,unordered_map<int,bool> &visited){
        visited[src] = true;
        cout<<src<<", ";
        for(auto neighbour : adjList[src]){
            if(!visited[neighbour]){
                dfs(neighbour,visited);
            }
        }
    }

    // with weight
    // unordered_map<int,list<pair<int,int>>> adjList;
    // void addEdge(int u, int v, int weight, bool direction=true){
    //     //direction false - undirected graph
    //     //direction true - directed graph
    //     // created edge u to v
    //     adjList[u].push_back({v,weight});
    //     if(!direction){
    //         adjList[v].push_back({u,weight});
    //     }
    // }
    // void printAdjList(){
    //     for(auto node : adjList){
    //         cout<<node.first<<"->";
    //         for(auto neighbour : node.second){
    //             cout<<"("<<neighbour.first<<","<<neighbour.second<<")";
    //         }
    //         cout<<endl;
    //     }
    // }
};
int main(){
    // int n;
    // cout<<"Enter the row & col: ";
    // cin>>n;
    // //adjaency matrix
    // vector<vector<int>> am(n,vector<int>(n,0));
    // //for edge
    // int edge;
    // cout<<"Enter no. of edge: ";
    // cin>>edge;
    // for(int i=0;i<edge;i++){
    //     int x,y;
    //     cin>>x>>y;
    //     am[x][y] = 1;
    // };
    // //print
    // for(int i=0;i<n;i++){
    //     for(int j=0;j<n;j++){
    //         cout<<am[i][j]<<" ";
    //     }
    //     cout<<endl;
    // }


    // Graph<char> g;
    //undiected graph
    // g.addEdge(0,1,0);
    // g.addEdge(1,2,0);
    // g.addEdge(0,2,0);
    // g.printAdjList();

    //directed graph
    //g.addEdge(sourece,destination,weight,direction)
//     g.addEdge(0,1,8,1);
//     g.addEdge(1,2,5,1);
//     g.addEdge(0,2,6,1);
//     g.printAdjList();


    // g.addEdge('a','b');
    // g.addEdge('a','c');
    // g.addEdge('b','d');
    // g.addEdge('c','d');
    // g.printAdjList();

    Graph<int> g;
    g.addEdge(0,1,0);
    g.addEdge(1,3,0);
    g.addEdge(0,2,0);
    g.addEdge(2,4,0);
    // g.addEdge(3,7,0);
    // g.addEdge(7,4,0);
    // g.addEdge(7,6,0);
    
    g.printAdjList();
    cout<<endl;
    cout<<"BFS: ";
    g.bfs(0);
    cout<<endl;

    unordered_map<int,bool> visited;
    cout<<"Dfs: ";
    g.dfs(0,visited);
}