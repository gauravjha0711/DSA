#include<iostream>
using namespace std;
int main(){
    int a= 5;
    int *ptr = &a;
    cout<<"a: "<<a<<endl;
    cout<<"&a: "<<&a<<endl;
    // cout<<"*a: "<<*a<<endl;  //showing error
    cout<<"ptr: "<<ptr<<endl;
    cout<<"&ptr: "<<&ptr<<endl;
    cout<<"*ptr: "<<*ptr<<endl;
}
