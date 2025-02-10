#include<iostream>
#include<stack>
using namespace std;
int main(){
    stack<string> s;
    s.push("Gaurav");
    s.push("Kumar");
    s.push("Jha");
    cout<<"before Top: "<<s.top()<<endl;
    s.pop();
    cout<<"After pop, Top: "<<s.top()<<endl;

    cout<<"size: "<<s.size()<<endl;
    cout<<"Empty or not: "<<s.empty()<<endl;
}