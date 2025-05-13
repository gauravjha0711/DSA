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
    // Dijkstra's algorithm to find the shortest distance from source to all other nodes
    // Time complexity: O(ElogV) where E is the number of edges and V is the number of vertices
    void shortestDistanceDijkstra(int src, int n){
        vector<int> dist(n,INT_MAX);
        set<pair<int,int>> st;
        dist[src] = 0;
        st.insert({0,src});
        while(!st.empty()){
            auto topElement = *(st.begin());
            int nodeDistance = topElement.first;
            int node = topElement.second;
            st.erase(st.begin());

            for(auto neighbour : adjList[node]){
                if(nodeDistance + neighbour.second < dist[neighbour.first] ){
                    auto result = st.find({dist[neighbour.first],neighbour.first});
                    if(result!=st.end()){
                        st.erase(result);
                    }
                    dist[neighbour.first] = nodeDistance + neighbour.second;
                    st.insert({dist[neighbour.first],neighbour.first});
                }
            }
        }
        cout<<"Printing ans: "<<endl;
        for(int i=0;i<n;i++){
            cout <<dist[i]<<", ";
        }
        cout<<endl;
    }
    void belmondAlgorithm(int src, int n){
        vector<int> dist(n,INT_MAX);
        set<pair<int,int>> st;
        dist[src] = 0;
        st.insert({0,src});
        while(!st.empty()){
            auto topElement = *(st.begin());
            int nodeDistance = topElement.first;
            int node = topElement.second;
            st.erase(st.begin());

            for(auto neighbour : adjList[node]){
                if(nodeDistance + neighbour.second < dist[neighbour.first] ){
                    auto result = st.find({dist[neighbour.first],neighbour.first});
                    if(result!=st.end()){
                        st.erase(result);
                    }
                    dist[neighbour.first] = nodeDistance + neighbour.second;
                    st.insert({dist[neighbour.first],neighbour.first});
                }
            }
        }
        cout<<"Printing ans: "<<endl;
        for(int i=0;i<n;i++){
            cout <<dist[i]<<", ";
        }
        cout<<endl;
    }
    void floydWarshal(int n){
        vector<vector<int>> dist(n,vector<int>(n,INT_MAX));
        for(int i=0;i<n;i++){
            dist[i][i] = 0;
        }
        for(auto i : adjList){
            int u = i.first;
            for(auto neighbour : i.second){
                int v = neighbour.first;
                int wt = neighbour.second;
                dist[u][v] = wt;
            }
        }
        for(int k=0;k<n;k++){
            for(int i=0;i<n;i++){
                for(int j=0;j<n;j++){
                    if(dist[i][k] != INT_MAX && dist[k][j] != INT_MAX){
                        dist[i][j] = min(dist[i][j],dist[i][k]+dist[k][j]);
                    }
                }
            }
        }
        cout<<"Printing ans: "<<endl;
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                cout <<dist[i][j]<<", ";
            }
            cout<<endl;
        }
    }

};
int main(){
    Graph g;

    g.addEdge(6,3,2,1);
    g.addEdge(6,1,14,1);
    g.addEdge(3,1,9,1);

    g.addEdge(3,2,10,1);
    g.addEdge(1,2,7,1);
    g.addEdge(2,4,15,1);
    g.addEdge(4,3,11,1);

    g.addEdge(6,5,9,1);
    g.addEdge(4,5,6,1);

    g.printAdjList();
    cout<<endl;
    g.shortestDistanceDijkstra(6,7);
    cout<<endl;
    g.belmondAlgorithm(6,7);
    cout<<endl;
    g.floydWarshal(7);
    cout<<endl;
}