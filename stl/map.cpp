#include<iostream>
#include<map>
using namespace std;
int main(){
    map<int, string> m;
    m[1] = "patna";
    m[12] = "muzaffarpur";
    m[2] = "bihar";
    m.insert({5, "India"});
    for(auto i : m){
        cout<<i.first<<" "<<i.second<<endl;
    }

    cout<<"12 present or not: "<<m.count(12)<<endl;

    cout<<"before erase: "<<endl;
    for(auto i : m){
        cout<<i.first<<" "<<i.second<<endl;
    }
    m.erase(12);
    cout<<"After earse: "<<endl;
    for(auto i : m){
        cout<<i.first<<" "<<i.second<<endl;
    }

    auto it = m.find(5);
    for(auto i=it;i!=m.end();i++){
        cout<<(*i).first<<" ";
    }cout<<endl;
}