#include<bits/stdc++.h>
using namespace std;
void solve(string &s, string &part){
    int i = s.find(part);
    if(i!=string::npos){
        s.erase(i, part.length());
        solve(s,part);
    }
    else{
        return;
    }
}
string removeOccurrences(string s, string part) {
    solve(s,part);
    return s;
}
int main(){
    string s = "daabcbaabcbc";
    string part = "abc";
    cout<<removeOccurrences(s,part)<<endl;
    return 0;
}