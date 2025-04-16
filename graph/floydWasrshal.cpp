#include<bits/stdc++.h>
using namespace std;
class graph{
    int v;
    list<pair<int,int>> adjList;
    public:
    graph(int v){
        this->v = v;
    }
    void addEdge(int u, int v, int w){
        adjList.push_back(make_pair(v,w));
        adjList.push_back(make_pair(u,w));
    }
    void flodyWarshal(int n){
        //print all the distances from the source to all the other nodes
        vector<vector<int>> dist(n, vector<int>(n, INT_MAX));
        for(int i=0;i<n;i++){
            dist[i][i] = 0;
        }
        for(auto it: adjList){
            dist[it.first][it.second] = it.second;
        }
        for(int k=0;k<n;k++){
            for(int i=0;i<n;i++){
                for(int j=0;j<n;j++){
                    if(dist[i][k] != INT_MAX && dist[k][j] != INT_MAX){
                        dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
                    }
                }
            }
        }
        cout<<"The shortest distance between all the pairs of nodes is: "<<endl;
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(dist[i][j] == INT_MAX){
                    cout<<"INF"<<" ";
                }else{
                    cout<<dist[i][j]<<" ";
                }
            }
            cout<<endl;
        }
    }
};
int main(){
    int n = 4;
    graph g(n);
    g.addEdge(0,1,5);
    g.addEdge(0,2,10);
    g.addEdge(1,2,3);
    g.addEdge(1,3,2);
    g.addEdge(2,3,1);
    g.flodyWarshal(n);
    return 0;
}