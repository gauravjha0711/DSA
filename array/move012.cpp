#include<iostream>
#include<vector>
using namespace std;
void move012(vector<int>& v){
    int n=v.size();
    int left=0, right= n-1, index=0;
    while(index<=right){
        if(v[index]==0){
            swap(v[index++], v[left++]);
        }
        else if(v[index]==2){
            swap(v[index], v[right--]);
        }
        else{
            index++;
        }
    }
}
int main(){
    vector<int> v={0,1,0,2,2,0,1,2,0};
    move012(v);
    for(int i=0;i<v.size();i++){
        cout<<v[i]<<" ";
    }
}