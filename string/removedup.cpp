#include<iostream>
using namespace std;
// string removeduplicate(string s, string p){
//     while((s.length()!=0) && (s.find(p)<s.length())){
//         s.erase(s.find(p), p.length());
//     }
//     return s;
// }
string removeduplicate(string s, string p){
    while(s.find(p)!=string::npos){
        s.erase(s.find(p), p.length());
    }
    return s;
}   
int main(){
    cout<<"Enter string: ";
    string s,p;
    cin>>s;
    cout<<"Enter the serach part: ";
    cin>>p;
    cout<<"Ans: "<<removeduplicate(s, p);
}