#include<iostream>
#include<queue>
#include<stack>
using namespace std;
void reverseFirstK(queue<int> &q, int k){
    stack<int> s;
    int n = q.size();
    if(k>n || k==0){
        cout<<"Invalid k"<<endl;
        return;
    }
    for(int i=0;i<k;i++){
        int x = q.front();
        s.push(x);
        q.pop();
    }
    while(!s.empty()){
        int x = s.top();
        q.push(x);
        s.pop();
    }
    for(int i=0;i<n-k;i++){
        int x = q.front();
        q.pop();
        q.push(x);
    }
}
void print(queue<int> q){
    while(!q.empty()){
        cout<<q.front()<<" ";
        q.pop();
    }
}
int main(){
    cout<<"Enter the size : ";
    int n;
    cin>>n;
    queue<int> q;
    cout<<"Enter the elements : ";
    for(int i=0;i<n;i++){
        int x;
        cin>>x;
        q.push(x);
    }
    cout<<"Enter the value of k : ";
    int k;
    cin>>k;
    reverseFirstK(q,k);
    print(q);
}