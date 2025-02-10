#include<iostream>
#include<queue>
using namespace std;
int main(){
    queue<string> q;
    q.push("Gaurav");
    q.push("Kumar");
    q.push("Jha");
    cout<<"before Top: "<<q.front()<<endl;
    q.pop();
    cout<<"After pop, Top: "<<q.front()<<endl;

    cout<<"size: "<<q.size()<<endl;
    cout<<"Empty or not: "<<q.empty()<<endl;
}