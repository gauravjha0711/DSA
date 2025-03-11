#include<iostream>
#include<queue>
using namespace std;
int main(){
    priority_queue<int, vector<int>, greater<int>> pq;
    pq.push(15);
    pq.push(12);
    pq.push(13);
    pq.push(11);
    pq.push(14);
    while(!pq.empty()){
        cout<<pq.top()<<" ";
        pq.pop();
    }
}