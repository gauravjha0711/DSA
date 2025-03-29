#include<bits/stdc++.h>
using namespace std;
void solveLtoR(string &s,char c,int i,int &n,int &ans){
    if(i==n){
        return;
    }
    if(s[i]==c){
        ans = i;
    }
    solveLtoR(s,c,i+1,n,ans);
}
void solveRtoL(string &s,char c,int i,int &n,int &ans){
    if(i<0){
        return;
    }
    if(s[i]==c){
        ans = i;
        return;
    }
    solveRtoL(s,c,i-1,n,ans);
}
int main(){
    string s;
    cout<<"Enter the string: ";
    cin>>s;
    char c;
    cout<<"Enter the character: ";
    cin>>c;
    int i=0;
    int n = s.size();
    int ans = -1;
    // solveLtoR(s,c,i,n,ans);
    solveRtoL(s,c,n-1,n,ans);
    cout<<"Last occurence of "<<c<<" is at index: "<<ans<<endl;
}