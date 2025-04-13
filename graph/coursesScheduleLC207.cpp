#include<bits/stdc++.h>
using namespace std;
bool topSortBFS(int n,unordered_map<int,list<int>>&adjList){
    vector<int> ans;
    queue<int> q;
    unordered_map<int,int> indegree;
    for(auto i : adjList){
        int src = i.first;
        for(auto neighbour : adjList[src]){
            indegree[neighbour]++;
        }
    }
    //put all the nodes with 0 indegree in the queue
    for(int i=0;i<n;i++){
        if(indegree[i] == 0){
            q.push(i);
        }
    }
    //bfs logic
    while(!q.empty()){
        int frontNode = q.front();
        q.pop();
        ans.push_back(frontNode);
        for(auto neighbour : adjList[frontNode]){
            indegree[neighbour]--;
            if(indegree[neighbour] == 0){
                q.push(neighbour);
            }
        }
    }
    if(ans.size()==n) return true;
    else return false;
}
bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
    unordered_map<int,list<int>> adjList;
    for(auto task : prerequisites){
        int u = task[0];
        int v = task[1];
        adjList[v].push_back(u);
    }
    bool ans = topSortBFS(numCourses,adjList);
    return ans;
}
int main() {
    int numCourses = 4;
    vector<vector<int>> prerequisites = {{1, 0}, {2, 1}, {3, 2}};
    bool result = canFinish(numCourses, prerequisites);
    cout << (result ? "Can finish all courses" : "Cannot finish all courses") << endl;
    return 0;
}