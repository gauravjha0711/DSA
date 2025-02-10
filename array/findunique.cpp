#include<iostream>
using namespace std;
int main(){
    int arr[5] = {5,2,3,5,2};
    int ans = 0;
    for(int i=0;i<5;i++){
        ans=ans^arr[i];
    }
    cout<<ans;
}

