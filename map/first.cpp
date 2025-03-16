#include<iostream>
#include<unordered_map>
#include<vector>
using namespace std;
int main(){
    unordered_map<string, int> m;
    pair<string, int> p = make_pair("gaurav", 1);
    m.insert(p);

    pair<string, int> p2("Omkar", 2);
    m.insert(p2);

    m["Gagan"] = 3;

    //access
    cout<<m.at("gaurav")<<endl;
    // cout<<m.at("omkar")<<endl;
    cout<<m["Gagan"]<<endl;

    //search
    cout<<m.count("gaurav")<<endl;
    cout<<m.count("omkar")<<endl;

    if(m.find("gaurav") != m.end()){
        cout<<"Found"<<endl;
    }
    else{
        cout<<"Not Found"<<endl;
    }

    for(auto i : m){
        cout<<i.first<<"->"<<i.second<<endl;
    }
}