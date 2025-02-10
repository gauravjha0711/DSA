#include<iostream>
#include<vector>
using namespace std;
int main(){
    vector<int> vec;
    cout<<"size: "<<vec.size()<<endl;
    cout<<"capacity: "<<vec.capacity()<<endl;
    vec.push_back(0);
    cout<<"size: "<<vec.size()<<endl;
    cout<<"capacity: "<<vec.capacity()<<endl;
    vec.push_back(1);
    cout<<"size: "<<vec.size()<<endl;
    cout<<"capacity: "<<vec.capacity()<<endl;
    vec.push_back(2);
    cout<<"size: "<<vec.size()<<endl;
    cout<<"capacity: "<<vec.capacity()<<endl;
    vec.push_back(3);
    cout<<"size: "<<vec.size()<<endl;
    cout<<"capacity: "<<vec.capacity()<<endl;

    cout<<"Front: "<<vec.front()<<endl;
    cout<<"Back: "<<vec.back()<<endl;
 
    cout<<"Before pop:";
    for(int i : vec){
        cout<<i<<" ";
    }cout<<endl;
    vec.pop_back();
    cout<<"After pop: ";
    for(int i : vec){
        cout<<i<<" ";
    }cout<<endl;

    vector<int> a(5,1);
    cout<<"vector a: ";
    for(int i : a){
        cout<<i<<" ";
    }cout<<endl;

    vector<int> b(a);
    cout<<"vector b: ";
    for(int i : b){
        cout<<i<<" ";
    }cout<<endl;
}