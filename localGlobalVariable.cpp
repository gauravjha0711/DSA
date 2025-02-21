#include<iostream>
using namespace std;
int x=2;  //Global variable
int main(){
    int x=3;  //Local variable
    cout<<x<<endl;  //3
    cout<<::x<<endl;  //2
    {
        int x=4;  //Local variable
        cout<<x<<endl;  //4
        cout<<::x<<endl;  //2
    }
    return 0;
}