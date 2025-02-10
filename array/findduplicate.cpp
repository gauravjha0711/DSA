#include<iostream>
using namespace std;
int main(){
    int arr[8] = {1,2,3,4,5,6,7,5};
    int ans = 0;
    for(int i=0;i<8;i++){
        ans = ans^arr[i];
    }
    for(int i=1;i<8;i++){
        ans = ans^i;
    }
    cout<<"Duplicate value is: "<<ans;
}