#include<iostream>
#include<deque>
using namespace std;
int main(){
    deque<int> d;
    d.push_back(2);
    d.push_front(1);
    for(int i : d){
        cout<<i<<" ";
    }cout<<endl;
    cout<<"Front: "<<d.front()<<endl;
    cout<<"back: "<<d.back()<<endl;
    cout<<"size: "<<d.size()<<endl;
    cout<<"Element at 1 index: "<<d.at(1)<<endl;

    cout<<"Before erase:";
    for(int i : d){
        cout<<i<<" ";
    }cout<<endl;
    d.erase(d.begin(),d.begin()+1);
    cout<<"After erase: ";
    for(int i : d){
        cout<<i<<" ";
    }cout<<endl;
}