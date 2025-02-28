#include<iostream>
#include<queue>
#include<vector>
using namespace std;
int main(){
    queue<int> q;
    q.push(1);
    q.push(2);
    q.push(3);
    cout <<"Fromt: "<< q.front() << endl;
    q.pop();
    cout << "front:"<<q.front() << endl;
    cout << "Size:"<< q.size() << endl;
    cout << "empty: "<<q.empty() << endl;
    return 0;
}