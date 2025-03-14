#include<bits/stdc++.h>
using namespace std;
bool isSubset(vector<int> &a, vector<int> &b) {
    // Your code here
    unordered_map<int, int> map;
    for(int i=0;i<a.size();i++){
        map[a[i]]++;
    }
    for(int i=0;i<b.size();i++){
        if(map.find(b[i])==map.end()){
            return false;
        }
        else{
            if(map[b[i]]>0){
                map[b[i]]--;
            }
            else{
                return false;
            }
        }
    }
    return true;
}
int main(){
    vector<int> a = {11, 1, 13, 21, 3, 7};
    vector<int> b = {11, 3, 7, 1};
    cout<<isSubset(a, b)<<endl;
    return 0;
}