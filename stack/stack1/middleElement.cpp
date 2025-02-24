#include<iostream>
#include<stack>
using namespace std;
void solve(stack<int> &s, int &pos, int &ans){
    if(pos==1){
        ans = s.top();
        return;
    }

    pos--;
    int temp = s.top();
    s.pop();
    solve(s,pos,ans);
    //backtracking step
    s.push(temp);

}
int middleElement(stack<int> &s){
    int n = s.size();
    if(n==0){
        cout<<"Stack is empty"<<endl;
        return -1;
    }
    int pos=-1;
    if(n&1){
        pos = n/2+1;
    }
    else{
        pos = n/2;
    }

    int ans=-1;
    solve(s,pos,ans);
    return ans;
}
int main(){
    stack<int> s;
    s.push(1);
    s.push(2);
    s.push(3);
    s.push(4);
    s.push(5);
    s.push(6);

    int middle = middleElement(s);
    cout<<"Middle element: "<<middle<<endl;
}