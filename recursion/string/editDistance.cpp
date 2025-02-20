#include<iostream>
#include<vector>
using namespace std;
int editDistance(string a, string b, int i, int j){
    if(i>=a.length()){
        return b.length()-j;
    }
    if(j>=b.length()){
        return a.length()-i;
    }
    int ans=0;
    if(a[i]==b[j]){
        ans = editDistance(a,b,i+1,j+1);
    }
    else{
        int insert = 1+editDistance(a,b,i,j+1);
        int remove = 1+editDistance(a,b,i+1,j);
        int replace = 1+editDistance(a,b,i+1,j+1);
        ans = min(insert,min(remove,replace));
    }
}
int main(){
    string a = "horse";
    string b = "ros";
    cout<<editDistance(a,b,0,0);
    return 0;
}