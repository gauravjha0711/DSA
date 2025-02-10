#include<iostream>
#include<queue>
using namespace std;
int main(){
    priority_queue<int> maxi;
    priority_queue<int, vector<int>, greater<int> > mini;
    maxi.push(0);
    maxi.push(1);
    maxi.push(2);
    maxi.push(3);
    int n1 = maxi.size();
    for(int i=0;i<n1;i++){
        cout<<maxi.top()<<" ";
        maxi.pop();
    }cout<<endl;

    mini.push(0);
    mini.push(1);
    mini.push(2);
    mini.push(3);
    int n2 = mini.size();
    for(int i=0;i<n2;i++){
        cout<<mini.top()<<" ";
        mini.pop();
    }cout<<endl;
}