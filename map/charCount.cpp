#include<iostream>
#include<unordered_map>
#include<map>
using namespace std;
int main(){
    // unordered_map<char, int> freq;
    // string s;
    // cout<<"Enter a string: ";
    // cin>>s;
    // for(int i=0;i<s.size();i++){
    //     char ch = s[i];
    //     freq[ch]++;
    // }
    // for(auto i : freq){
    //     cout<<i.first<<"->"<<i.second<<endl;
    // }

    map<char, int> freq;
    string s;
    cout<<"Enter a string: ";
    cin>>s;
    for(int i=0;i<s.size();i++){
        char ch = s[i];
        freq[ch]++;
    }
    for(auto i : freq){
        cout<<i.first<<"->"<<i.second<<endl;
    }
    
}