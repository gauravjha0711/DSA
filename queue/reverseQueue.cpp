#include<iostream>
#include<queue>
#include<stack>
using namespace std;
void reverseQueue(queue<int> &q){
    stack<int> s;
    while(!q.empty()){
        s.push(q.front());
        q.pop();
    }

    while(!s.empty()){
        q.push(s.top());
        s.pop();
    }
}
void reverseQueueRecursion(queue<int> &q){
    if(q.empty()){
        return;
    }
    int temp=q.front();
    q.pop();

    reverseQueueRecursion(q);

    q.push(temp);
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
    // reverseQueue(q);
    // print(q);

    reverseQueueRecursion(q);
    print(q);
}