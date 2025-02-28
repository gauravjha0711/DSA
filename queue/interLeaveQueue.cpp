#include<iostream>
#include<queue>
using namespace std;
void interLeaveQueue(queue<int> &q){
    queue<int> q2;
    int n = q.size();
    int k = n/2;
    int count=1;
    while(count<=k && !q.empty()){
        int element = q.front();
        q.pop();
        q2.push(element);
        count++;
    }
    while(!q.empty() && !q2.empty()){
        int element1 = q2.front();
        q2.pop();
        q.push(element1);

        int element2 = q.front();
        q.pop();
        q.push(element2);
    }
    if(n&1){
        int element = q.front();
        q.pop();
        q.push(element);
    }
}
void print(queue<int> q){
    while(!q.empty()){
        cout<<q.front()<<" ";
        q.pop();
    }
}
int main(){
    queue<int> q;
    cout<<"Enter the size: ";
    int n;
    cin>>n;
    cout<<"Enter element: ";
    for(int i=0;i<n;i++){
        int x;
        cin>>x;
        q.push(x);
    }
    interLeaveQueue(q);
    print(q);
}